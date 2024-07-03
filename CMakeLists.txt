cmake_minimum_required(VERSION 3.16)

project(kpersonal-desktop VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

list(APPEND CMAKE_PREFIX_PATH "C:/Qt/6.7.1/mingw_64/lib/cmake")
find_package(Qt6 6.5 REQUIRED COMPONENTS Widgets)

add_executable(kpersonal-desktop
        src/main.cpp

        include/MainWindow.hpp
        src/MainWindow.cpp

        include/ListItemWidget.hpp
        src/ListItemWidget.cpp

        include/CustomDelegate.hpp
        src/CustomDelegate.cpp

        include/StackedModuleWidget.hpp
        src/StackedModuleWidget.cpp

        include/modules/CalendarModule.hpp
        src/modules/CalendarModule.cpp
        include/modules/FlashcardsModule.hpp
        src/modules/FlashcardsModule.cpp
        include/modules/HabitModule.hpp
        src/modules/HabitModule.cpp
        include/modules/KanbanModule.hpp
        src/modules/KanbanModule.cpp
        include/modules/ProjectModule.hpp
        src/modules/ProjectModule.cpp
        include/modules/TaskModule.hpp
        src/modules/TaskModule.cpp
        include/modules/TimeModule.hpp
        src/modules/TimeModule.cpp
        include/modules/WikiModule.hpp
        src/modules/WikiModule.cpp
)

target_include_directories(kpersonal-desktop PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(kpersonal-desktop PRIVATE Qt6::Widgets)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
