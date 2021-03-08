cmake_minimum_required (VERSION 3.10)

project("Test")

add_subdirectory(B)
include_directories(.)

set_target_properties(B PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(C C/main.h C/main.cpp A/index.h)
target_link_libraries(C B)


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
