cmake_minimum_required(VERSION 3.5)

project(GemBrowserTests LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Test Widgets Gui Sql)
find_package(Qt6 REQUIRED COMPONENTS Test Widgets Gui Sql)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(includes
    "../src/core/"
)

add_executable(ConfigTests core/tst_configfile.cpp )
add_executable(HistoryTests core/tst_historyclass.cpp )

target_include_directories(ConfigTests PRIVATE "core")
target_include_directories(ConfigTests PRIVATE ${includes})

target_include_directories(HistoryTests PRIVATE "core")
target_include_directories(HistoryTests PRIVATE ${includes})

add_test(NAME CoreTests COMMAND CoreTests )

target_link_libraries(ConfigTests PRIVATE Qt6::Test)
target_link_libraries(ConfigTests PRIVATE Qt6::Widgets)
target_link_libraries(ConfigTests PRIVATE Qt6::Gui)
target_link_libraries(ConfigTests PRIVATE core)

target_link_libraries(HistoryTests PRIVATE Qt6::Test)
target_link_libraries(HistoryTests PRIVATE Qt6::Sql)
target_link_libraries(HistoryTests PRIVATE core)

