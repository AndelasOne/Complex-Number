cmake_minimum_required(VERSION 3.15)
project(Templates)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest)
add_subdirectory(source)

# add googletest and src before adding test
add_subdirectory(test)

add_executable(Templates main.cpp)


target_link_libraries(
        Templates
        PUBLIC
        SourceLib
)