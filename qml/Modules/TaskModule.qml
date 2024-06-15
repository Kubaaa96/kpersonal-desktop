import QtQuick 2.15
import QtQuick.Layouts 1.15

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
}
