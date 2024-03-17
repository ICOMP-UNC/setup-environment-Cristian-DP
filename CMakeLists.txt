# https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html#command:cmake_minimum_required

cmake_minimum_required (VERSION 3.25)

# https://cmake.org/cmake/help/latest/command/project.html#command:project

project(
		lab0
        VERSION 1.0.0
        DESCRIPTION "CMake Configuration"
        HOMEPAGE_URL "https://github.com/ICOMP-UNC/setup-environment-Cristian-DP"
        LANGUAGES C
        )

# https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20Usage%20Requirements%20for%20a%20Library.html#exercise-2-setting-the-c-standard-with-interface-libraries

set (CMAKE_C_STANDARD 17)

include_directories (include)

file (
	GLOB_RECURSE 
	SOURCES
	"src/*.c"
)

# https://cmake.org/cmake/help/latest/command/add_executable.html#command:add_executable

add_executable (
	${PROJECT_NAME}
	${SOURCES}
)

# Se añaden liberarias staticas y dinamicas

add_subdirectory(lib/libdyn)
add_subdirectory(lib/libsta)

# Tenemos que especificar los headers de las librerias

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	lib/libsta/include
)

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	lib/libdyn/include
)

# TENEMOS QUE LINKEAR LAS LIBRERIAS

target_link_libraries (
	${PROJECT_NAME}
	static_library
	dinamyc_library
)