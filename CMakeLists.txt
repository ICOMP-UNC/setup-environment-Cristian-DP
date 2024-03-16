# TODO 1: Set the minimum required version of CMake to be 3.10
# https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html#command:cmake_minimum_required

cmake_minimum_required (VERSION 3.25)

# TODO 2: Create a project named Tutorial
# https://cmake.org/cmake/help/latest/command/project.html#command:project

project(
		lab0
        VERSION 1.0.0
        DESCRIPTION "CMake Configuration"
        HOMEPAGE_URL "https://github.com/ICOMP-UNC/setup-environment-Cristian-DP"
        LANGUAGES C
        )


# TODO 7: Set the project version number as 1.0 in the above project command

# TODO 6: Set the variable CMAKE_CXX_STANDARD to 11
#         and the variable CMAKE_CXX_STANDARD_REQUIRED to True

# TODO 8: Use configure_file to configure and copy TutorialConfig.h.in to
#         TutorialConfig.h

# TODO 3: Add an executable called Tutorial to the project
# Hint: Be sure to specify the source file as tutorial.cxx
# https://cmake.org/cmake/help/latest/command/add_executable.html#command:add_executable

add_executable (
	lab0_executble
	src/main.c
)

# TODO 9: Use target_include_directories to include ${PROJECT_BINARY_DIR}
