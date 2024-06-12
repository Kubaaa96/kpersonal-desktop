cmake_minimum_required(VERSION 3.16)

project(kpersonal-desktop VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appkpersonal-desktop
    src/main.cpp
)
qt_policy(SET QTP0001 NEW)
qt_add_qml_module(appkpersonal-desktop
    URI kpersonal-desktop
    VERSION 1.0
    QML_FILES qml/Main.qml
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
