cmake_minimum_required (VERSION 3.10)
project (StairDesigner)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(include)

add_subdirectory(test)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(
        UI_RESOURCES
                "resources/ui/MainWindow.ui"
)
set(
        UI_HEADERS
                "include/ui/MainWindow.h"
)
set(
        UI_SOURCES
                "src/ui/MainWindow.cpp"
)
set(
	GEOMETRY_SOURCES
		"include/geometry/Shape.hpp"
		"include/geometry/Point.hpp"
		"src/geometry/Point.cpp"
		"include/geometry/Line.hpp"
                "src/geometry/Line.cpp"
                "include/geometry/CustomLine.hpp"
                "src/geometry/CustomLine.cpp"
                "include/geometry/HorizontalLine.hpp"
                "src/geometry/HorizontalLine.cpp"
)

set(
        UTIL_SOURCES
                "util/Optional.hpp"
)

set(
	SOURCES
		"src/main.cpp"
                ${UI_SOURCES}
                ${UI_RESOURCES}
)
qt5_wrap_ui(SOURCES ${UI_RESOURCES})
qt5_wrap_cpp(SOURCES ${UI_HEADERS})

add_library(geometry ${GEOMETRY_SOURCES})

add_executable(stair_designer ${SOURCES})

target_link_libraries(stair_designer 
        geometry 
        Qt5::Core
	Qt5::Gui 
	Qt5::Widgets
)

