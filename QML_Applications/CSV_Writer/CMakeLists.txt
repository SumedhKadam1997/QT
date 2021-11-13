cmake_minimum_required(VERSION 3.19)

project(
    CSVWriter
    LANGUAGE CXX
)

find_package(
    Qt5
    REQUIRED
    COMPONENTS
        Core
        Quick
)

add_executable(CSVWriter)

qt_wrap_cpp(
    CSVWriter_QT_MOCS
    "csvwriter.hpp"
)

qt_add_resources(
    CSVWriter_QT_RES
        "qml.qrc"
)

target_sources(
    CSVWriter
    PRIVATE
        ${CSVWriter_QT_MOCS}
        ${CSVWriter_QT_RES}
        "main.cpp"
        "csvwriter.cpp"
)

target_include_directories(
    CSVWriter
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(
    CSVWriter
    PRIVATE
        Qt5::Core
        Qt5::Quick
)
