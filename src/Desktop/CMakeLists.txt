cmake_minimum_required(VERSION 3.5)

project(TNGemBrowser VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets Sql Gui)
find_package(Qt6 REQUIRED COMPONENTS Widgets Sql Gui)

set(corePath "../core")
set(TS_FILES TNGemBrowser_pl_PL.ts)

set(PROJECT_SOURCES
    main.cpp
    gembrowser.h gembrowser.cpp gembrowser.ui
    prefsdialog.h prefsdialog.cpp prefsdialog.ui
    ${TS_FILES}
)

qt_add_executable(TNGemBrowser
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} TS_FILES TNGemBrowser_pl_PL.ts
    RESOURCE_PREFIX /i18n
    SOURCES ${PROJECT_SOURCES}
    LUPDATE_OPTIONS -source-language en -target-language pl
)

target_include_directories(TNGemBrowser PRIVATE ${corePath})
target_link_libraries(TNGemBrowser PRIVATE Qt6::Widgets)
target_link_libraries(TNGemBrowser PRIVATE Qt6::Network)
target_link_libraries(TNGemBrowser PRIVATE Qt6::Sql)
target_link_libraries(TNGemBrowser PRIVATE Qt6::Gui)
target_link_libraries(TNGemBrowser PRIVATE core)

set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER pl.com.TrollNet.TNGemBrowser)


set_target_properties(TNGemBrowser PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS TNGemBrowser
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(TNGemBrowser)

