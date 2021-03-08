cmake_minimum_required (VERSION 3.19)

project("Test")

add_subdirectory(B)
include_directories(.)

add_executable(application C/main.h C/main.cpp A/index.h)
#add_library(application B)

add_custom_target(run_python_script ALL
	DEPENDS ${CMAKE_SOURCE_DIR}/A/index.h
	VERBATIM)

add_custom_command(
		PRE_BUILD
		OUTPUT ${CMAKE_SOURCE_DIR}/A/index.h
		COMMAND python3 ${CMAKE_SOURCE_DIR}/A/preparing.py
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/A/
		COMMENT "Run python script"
		VERBATIM)
