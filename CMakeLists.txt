cmake_minimum_required(VERSION 3.28.3-msvcll)

project(project3d
	VERSION 1.0.0
	LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD				14)
set(CMAKE_CXX_STANDARD_REQUIRED		ON)
set(CMAKE_CXX_EXTENSIONS			OFF)

SET(PROJECT3D project3d)

add_subdirectory(PROJECT3D)