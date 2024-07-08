cmake_minimum_required(VERSION 3.5)

project(GemBrowserTests LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Test Widgets Gui)
find_package(Qt6 REQUIRED COMPONENTS Test Widgets Gui)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(includes
    "../src/core/"
)

set(SOURCES
	core/tst_configfile.cpp
)

add_executable(GemBrowserTests ${SOURCES})
target_include_directories(GemBrowserTests PRIVATE "core")
target_include_directories(GemBrowserTests PRIVATE ${includes})

add_test(NAME ConfigFile COMMAND ConfigFile)

target_link_libraries(GemBrowserTests PRIVATE Qt6::Test)
target_link_libraries(GemBrowserTests PRIVATE Qt6::Widgets)
target_link_libraries(GemBrowserTests PRIVATE Qt6::Gui)
target_link_libraries(GemBrowserTests PRIVATE core)

