#ifndef CUTEHMI_LIBBASE_SRC_MODBUS_REGISTERTRAITS_HPP
#define CUTEHMI_LIBBASE_SRC_MODBUS_REGISTERTRAITS_HPP

#include "InputRegister.hpp"
#include "HoldingRegister.hpp"

namespace modbus {

template <typename R>
struct RegisterTraits
{
	typedef typename RegisterTraits<R>::Container Container;
};

template <>
struct RegisterTraits<InputRegister>
{
	typedef QHash<int, InputRegister *> Container;
};

template <>
struct RegisterTraits<HoldingRegister>
{
	typedef QHash<int, HoldingRegister *> Container;
};

}

#endif

