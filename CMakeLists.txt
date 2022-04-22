cmake_minimum_required(VERSION 2.8.12)

project(oppen)

set(SOURCE_FILES
	src/graphics/window.cpp
	src/internal.cpp
)


add_library(oppen ${SOURCE_FILES})
target_include_directories(oppen PUBLIC include)
target_link_libraries(oppen PUBLIC GL GLEW)
