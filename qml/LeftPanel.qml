import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Rectangle {
    color: "lightblue"
    id: leftPanel
    width: 200
    Layout.fillHeight: true

    signal itemClicked(var item)

    ModulesModel {
        id: modulesModel
    }

    ColumnLayout {
        anchors.fill: parent

        Component {
            id: contactDelegate
            Item {
                width: 200
                height: leftPanel.height / modulesModel.count

                Rectangle {
                    width: parent.width
                    height: parent.height
                    color: "transparent"
                    border.color: "gray"

                    Column {
                        anchors.fill: parent
                        anchors.margins: 5

                        Text {
                            text: '<b>Name:</b> ' + name
                        }
                    }

                    MouseArea {
                        id: itemMouseArea
                        anchors.fill: parent
                        onClicked: {
                            leftPanel.itemClicked(model)
                            console.debug("Selected", name)
                        }
                        hoverEnabled: true

                        Rectangle {
                            anchors.fill: parent
                            color: "transparent"
                            border.color: itemMouseArea.containsMouse ? "red" : "transparent"
                            border.width: 1

                        }
                    }
                }
            }
        }

        ListView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: ModulesModel {}
            delegate: contactDelegate
            opacity: leftPanel.width > 0 ? 1.0 : 0.0
            focus: true
        }
    }
}
