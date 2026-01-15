cmake_minimum_required(VERSION 3.19)
project(app LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(Qt6_DIR "/usr/lib/cmake/Qt6")
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

add_subdirectory(tablemodel)

qt_add_executable(app
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

target_link_libraries(app
    PRIVATE
        Qt::Core
        Qt::Widgets
)

target_link_libraries(app
    PRIVATE
        mytabmodel
)

include(GNUInstallDirs)

install(TARGETS app
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET app
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
