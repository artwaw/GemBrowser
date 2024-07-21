cmake_minimum_required(VERSION 3.5)

project(core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(TS_FILES core.ts)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)

add_library(core SHARED
  configfile.h configfile.cpp
  geminiparser.h geminiparser.cpp
  geminiprotocol.h geminiprotocol.cpp
  historyclass.h historyclass.cpp
  toolkitclass.h toolkitclass.cpp
)

qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} TS_FILES core_PL.ts
    RESOURCE_PREFIX /i18n
    SOURCES ${PROJECT_SOURCES}
    LUPDATE_OPTIONS -source-language en -target-language pl
)
target_include_directories(core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(core PRIVATE Qt6::Core)
target_link_libraries(core PRIVATE Qt6::Network)
target_link_libraries(core PRIVATE Qt6::Sql)
target_link_libraries(core PRIVATE Qt6::Widgets)

target_compile_definitions(core PRIVATE CORE_LIBRARY)
