import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import "Modules"

ApplicationWindow {
    width: 800
    height: 600
    minimumWidth: 640
    minimumHeight: 480
    visible: true
    title: "KPersonal"

    property var selectedItem: null

    property var moduleMap: ({
                                 "Task": 0,
                                 "Time": 1,
                                 "Flashcards": 2,
                                 "Habit": 3,
                                 "Wiki": 4,
                                 "Project": 5,
                                 "Timeline": 6,
                                 "Calendar": 7,
                                 "Kanban": 8,
                                 "List": 9
                             })

    RowLayout {
        id: mainLayout
        anchors.fill: parent

        LeftPanel {
            id: leftPanel
            Layout.preferredWidth: leftPanel.visible ? 200 : 0
            Layout.fillHeight: true
            onItemClicked: item => {
                               selectedItem = item
                               stackLayout.currentIndex = moduleMap[selectedItem.name]
                           }
        }

        ColumnLayout {
            id: buttonColumnLayout
            Layout.fillHeight: true
            Layout.preferredWidth: 20

            Button {
                id: toggleButton
                text: leftPanel.visible ? "<" : ">"
                font.pixelSize: 18
                Layout.fillHeight: true
                Layout.preferredWidth: buttonColumnLayout.width
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                onClicked: {
                    leftPanel.visible = !leftPanel.visible
                    if (leftPanel.visible) {
                        leftPanel.width = 200
                    } else {
                        leftPanel.width = 0
                    }
                }
            }
        }
        StackLayout {
            id: stackLayout
            Layout.fillHeight: true
            Layout.fillWidth: true
            currentIndex: 0
            TaskModule {}
            TimeModule {}
            FlashcardsModule {}
            HabitModule {}
            WikiModule {}
            ProjectModule {}
            TimelineModule {}
            CalendarModule {}
            KanbanModule {}
            ListModule {}
        }
    }
    menuBar: MenuBarLoader {
        id: menuBarLoader
    }
}
