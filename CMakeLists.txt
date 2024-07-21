cmake_minimum_required(VERSION 3.5)

project(TNGemBrowser VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Network LinguistTools)

add_subdirectory(src/core)
add_subdirectory(src/Desktop)
add_subdirectory(tests)

find_package(Doxygen)
if(Doxygen_FOUND)
    add_subdirectory(docs)
else()
    message(STATUS "Doxygen not found, not building docs")
endif()

set(distfiles
    README.md
    LICENSE.md
)

add_custom_target(legal SOURCES ${distfiles})
