cmake_minimum_required (VERSION 3.10)
project (StairDesigner)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(include)

add_subdirectory(test)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(
        UI_RESOURCES
                "resources/ui/Main.ui"
)
set(
        UI_HEADERS
                "include/ui/Main.h"
)

set(
	GEOMETRY_SOURCES
		"include/geometry/shapes.hpp"
		"src/geometry/shapes.cpp"
)

set(
	SOURCES
		"src/main.cpp"
                "src/ui/Main.cpp"
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

