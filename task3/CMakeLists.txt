cmake_minimum_required(VERSION 3.10)

if(${ARM_BUILD})
	set(CMAKE_FIND_ROOT_PATH ${SYSROOT})
	set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
	set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
	set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
endif()

if(DEFINED TOOLCHAIN)
	set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-g++)
	set(CMAKE_C_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-gcc)
endif()

project(SimpleLibrary)

include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)

add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

add_subdirectory(src)

target_link_libraries(MainLib buffer)
set_target_properties(MainLib PROPERTIES PUBLIC_HEADER ${PROJECT_SOURCE_DIR}/include/buffer.h)

message(${CMAKE_INSTALL_PREFIX})

set_target_properties(MainLib PROPERTIES
	IMPORTED_LOCATION "$ORIGIN/../lib/"
	INSTALL_RPATH "$ORIGIN/../lib/"
)
 
if(DEFINED CMAKE_INSTALL_PREFIX)
	install(TARGETS Main MainLib buffer
		LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
		PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include
		RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
endif()

set_target_properties(MainLib PROPERTIES
	IMPORTED_LOCATION "$ORIGIN/../lib/"
)

set(LD_LIBRARY_PATH "$ORIGIN/../lib")
