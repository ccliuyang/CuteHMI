import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1

import CuteHMI.Modbus 2.0

ColumnLayout {
	id: root

	property string title: qsTr("Coil")

	property AbstractDevice device

	property Item delegate

	property alias controller: controller

	CoilController {
		id: controller

		device: root.device
		address: addressBox.value
		readOnWrite: readOnWriteBox.checked
		writeDelay: writeDelayBox.value
		writeMode: writeModeBox.value

		onValueUpdated: delegate.checked = value
	}

	Connections {
		target: delegate
		onCheckedChanged: controller.value = delegate.checked
	}

	Label {
		text: root.title
	}

	GroupBox {
		GridLayout {
			columns: 2

			Label {
				Layout.alignment: Qt.AlignRight

				text: qsTr("Address:")
			}

			SpinBox {
				id: addressBox

				from: 0
				to: 65536
				editable: true
			}

			Label {
				Layout.alignment: Qt.AlignRight

				text: qsTr("Write mode:")
			}

			ComboBox {
				id: writeModeBox

				textRole: "key"
				model: ListModel {
					ListElement { key: "Delayed"; value: CoilController.WRITE_DELAYED }
					ListElement { key: "Postponed"; value: CoilController.WRITE_POSTPONED }
					ListElement { key: "Immediate"; value: CoilController.WRITE_IMMEDIATE }
					ListElement { key: "Explicit"; value: CoilController.WRITE_EXPLICIT }
				}

				property int value: model.get(currentIndex).value

				onActivated: value = model.get(index).value
			}

			Label {
				Layout.alignment: Qt.AlignRight

				text: qsTr("Write delay:")
			}

			SpinBox {
				id: writeDelayBox

				enabled: controller.writeMode == CoilController.WRITE_DELAYED

				from: 0
				to: 1000
				stepSize: 100

				value: 500
			}

			Label {
				Layout.alignment: Qt.AlignRight

				text: qsTr("Read on write:")
			}

			CheckBox {
				id: readOnWriteBox

				checked: true
			}
		}
	}
}