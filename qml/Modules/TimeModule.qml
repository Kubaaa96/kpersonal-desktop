import QtQuick 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: timeModule
    color: "lightgray"
    Layout.fillHeight: true
    Layout.fillWidth: true

    Column {
        anchors.centerIn: parent
        Text {
            text: "Time Module"
            font.pointSize: 24
        }
    }
}
