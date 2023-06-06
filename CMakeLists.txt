cmake_minimum_required(VERSION 3.22)
project(lab_6)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "MSVC")
    add_compile_options(-W3)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif ()

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include(cmake/utils.cmake)

link_libraries(Qt5::Widgets Qt5::Core Qt5::Gui)
add_subdirectory(game)



add_executable(lab_6 main.cpp resource.qrc)
target_link_libraries(lab_6
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        game
        )

windeployqt(lab_6)