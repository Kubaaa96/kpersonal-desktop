cmake_minimum_required(VERSION 3.16)

project(kpersonal-desktop VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)
set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml)
qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appkpersonal-desktop
    src/main.cpp
)
qt_policy(SET QTP0001 NEW)
qt_add_qml_module(appkpersonal-desktop
    URI kpersonal-desktop
    VERSION 1.0
    QML_FILES qml/Main.qml
    QML_FILES qml/MenuBarLoader.qml
    QML_FILES qml/LeftPanel.qml
    QML_FILES qml/ModulesModel.qml
    QML_FILES qml/Modules/TaskModule.qml
    QML_FILES qml/Modules/TimeModule.qml
    QML_FILES qml/Modules/FlashcardsModule.qml
    QML_FILES qml/Modules/HabitModule.qml
    QML_FILES qml/Modules/ProjectModule.qml
    QML_FILES qml/Modules/TimelineModule.qml
    QML_FILES qml/Modules/CalendarModule.qml
    QML_FILES qml/Modules/KanbanModule.qml
    QML_FILES qml/Modules/ListModule.qml
    QML_FILES qml/Modules/WikiModule.qml
)
set_target_properties(appkpersonal-desktop PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appkpersonal-desktop
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appkpersonal-desktop
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
