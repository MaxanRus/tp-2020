cmake_minimum_required(VERSION 3.10)
project(SimpleLibrary)

include_directories(include)

message("БЛА БЛА БЛА")

if(${ARM_BUILD})
	set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)
	set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)

	set(CMAKE_FIND_ROOT_PATH ${SYSROOT})
	set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
	set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
	set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

	message("БЛА БЛА БЛА!")
	# set(CMAKE_CXX_COMPILER ${CMAKE_SOURCE_DIR}/compiler/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-c++)
	message(${CMAKE_CXX_COMPILER})
endif()

if(DEFINED TOOLCHAIN)
	message("БЛА БЛА БЛА!!")
	# set(CMAKE_CXX_COMPILER ${CMAKE_BINARY_DIR}/${TOOLCHAIN}/aarch64-linux-gnu-c++)
	set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-g++)
	set(CMAKE_C_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-g++)
endif()

message("БЛА БЛА БЛА#")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)
add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

target_link_libraries(MainLib buffer)

if(DEFINED CMAKE_INSTALL_PREFIX)
	install(DIRECTORY MainLib Main DESTINATION ${CMAKE_INSTALL_PREFIX})
endif()

message("БЛА БЛА БЛА##")
