#ifndef H_EXTENSIONS_CUTEHMI_MODBUS_2_INCLUDE_CUTEHMI_MODBUS_INTERNAL_QTRTUSERVER_HPP
#define H_EXTENSIONS_CUTEHMI_MODBUS_2_INCLUDE_CUTEHMI_MODBUS_INTERNAL_QTRTUSERVER_HPP

#include "common.hpp"
#include "RegisterTraits.hpp"
#include "QtServerMixin.hpp"

#include <QModbusRtuSerialSlave>

namespace cutehmi {
namespace modbus {
namespace internal {

/**
 * Qt SerialBus based TCP server.
 */
class CUTEHMI_MODBUS_PRIVATE QtRTUServer:
	public QModbusRtuSerialSlave,
	protected QtServerMixin<QtRTUServer>
{
		Q_OBJECT

		friend class QtServerMixin<QtRTUServer>;
		typedef QtServerMixin<QtRTUServer> Mixin;

	public:
		typedef typename RegisterTraits<Coil>::Container CoilDataContainer;
		typedef typename RegisterTraits<DiscreteInput>::Container DiscreteInputDataContainer;
		typedef typename RegisterTraits<HoldingRegister>::Container HoldingRegisterDataContainer;
		typedef typename RegisterTraits<InputRegister>::Container InputRegisterDataContainer;

		QtRTUServer(CoilDataContainer * coilData,
				DiscreteInputDataContainer * discreteInputData,
				HoldingRegisterDataContainer * holdingRegisterData,
				InputRegisterDataContainer * inputRegisterData,
				QObject * parent = nullptr);

		bool setMap(const QModbusDataUnitMap & map) override;

	protected:
		bool readData(QModbusDataUnit * newData) const override;

		bool writeData(const QModbusDataUnit & newData) override;

	private:
		struct Members {
			CoilDataContainer * coilData;
			DiscreteInputDataContainer * discreteInputData;
			HoldingRegisterDataContainer * holdingRegisterData;
			InputRegisterDataContainer * inputRegisterData;
		};

		MPtr<Members> m;
};

}
}
}

#endif

//(c)C: Copyright © 2019, Michał Policht <michal@policht.pl>. All rights reserved.
//(c)C: This file is a part of CuteHMI.
//(c)C: CuteHMI is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//(c)C: CuteHMI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
//(c)C: You should have received a copy of the GNU Lesser General Public License along with CuteHMI.  If not, see <https://www.gnu.org/licenses/>.
