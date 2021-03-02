project("Test")

add_subdirectory(B)
include_directories(.)

add_executable(application C/main.cpp)
