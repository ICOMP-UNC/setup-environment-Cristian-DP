# https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html#command:cmake_minimum_required

cmake_minimum_required (VERSION 3.25)

# https://cmake.org/cmake/help/latest/command/project.html#command:project

project(
		lab0
        VERSION 1.2.0
        DESCRIPTION "CMake Configuration and Unity test"
        HOMEPAGE_URL "https://github.com/ICOMP-UNC/setup-environment-Cristian-DP"
        LANGUAGES C
)

# Enables test
include(CTest)

# https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20Usage%20Requirements%20for%20a%20Library.html#exercise-2-setting-the-c-standard-with-interface-libraries

set (CMAKE_C_STANDARD 17)

include_directories (include)

# Permite descargar dependencias externas
include(FetchContent)
set(UNITY_GIT_URL "https://github.com/ThrowTheSwitch/Unity.git")

# Enable dibug
set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare (
	Unity
	GIT_REPOSITORY ${UNITY_GIT_URL}
	SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity
	UPDATE_COMMAND ""
)

FetchContent_MakeAvailable (Unity)

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

if(RUN_TEST EQUAL 1 OR RUN_COVERAGE EQUAL 1 )
	add_subdirectory(tests)
endif()
