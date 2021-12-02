cmake_minimum_required(VERSION 3.21)
project(piRandom)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenMP REQUIRED)
add_executable(piRandom main.cpp Ran2.cpp Ran2.h Ran2ST.h)
target_link_libraries(piRandom PRIVATE OpenMP::OpenMP_CXX)