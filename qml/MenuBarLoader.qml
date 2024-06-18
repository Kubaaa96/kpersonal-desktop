import QtQuick 2.15
import QtQuick.Controls 2.15

Loader {
    id: root
    sourceComponent: menuBarComponent

    Dialog {
            id: quitDialog
            title: "Quit"
            modal: true
            anchors.centerIn: parent
            standardButtons: Dialog.Ok | Dialog.Cancel

            onAccepted: {
                console.log("Ok clicked")
            }
            onRejected: {
                console.log("Cancel clicked")
            }

            Text {
                text: "This is a dialog box!"
                anchors.centerIn: parent
            }
        }

    Component {
        id: menuBarComponent
        MenuBar {
                   Menu {
                       title: qsTr("&File")
                       Action {
                           text: qsTr("&New...")
                           onTriggered: {
                               console.debug("New")
                           }
                       }
                       Action {
                           text: qsTr("&Open...")
                           onTriggered: {
                               console.debug("Open")
                           }
                       }
                       Action {
                           text: qsTr("&Save")
                           onTriggered: {
                               console.debug("Save")
                           }
                       }
                       Action {
                           text: qsTr("Save &As...")
                           onTriggered: {
                               console.debug("Save As")
                           }
                       }
                       MenuSeparator { }
                       Action {
                           text: qsTr("&Quit")
                           onTriggered: {
                               console.debug("Quit")
                               quitDialog.open()
                           }
                       }
                   }
                   Menu {
                       title: qsTr("&Actions")
                       Action{
                           text: qsTr("&Export")
                           onTriggered: {
                               console.debug("Export")
                           }
                       }
                       Action{
                           text: qsTr("&Statistics")
                           onTriggered: {
                               console.debug("Statistics")
                           }
                       }
                       Action{
                           text: qsTr("&Options")
                           onTriggered: {
                               console.debug("Options")
                           }
                       }
                   }
                   Menu {
                       title: qsTr("&Help")
                       Action {
                           text: qsTr("&About")
                           onTriggered: {
                               console.debug("About")
                           }
                       }
                   }
               }
    }
}
