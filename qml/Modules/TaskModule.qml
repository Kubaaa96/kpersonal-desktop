import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Rectangle {
    id: taskModule
    color: "lightgray"
    Layout.fillHeight: true
    Layout.fillWidth: true

    Column {
        anchors.centerIn: parent
        Text {
            text: "Task Module"
            font.pointSize: 24
        }
    }
    Button {
        id: floatingButton
        text: "+"
        width: 50
        height: 50
        anchors {
            right: parent.right
            bottom: parent.bottom
            margins: 20
        }
        font.pixelSize: 24
        contentItem: Item {
            width: floatingButton.width
            height: floatingButton.height
            Text {
                text: "+"
                font.pixelSize: 30
                color: "black"
                anchors.centerIn: parent
            }
        }
        onClicked: {
            console.debug("Add Task")
        }
    }

}
