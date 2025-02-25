cmake_minimum_required(VERSION 3.10.0)
project(subnet_vox VERSION 0.1.0 LANGUAGES C CXX)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23 -DASIO_STANDALONE")

set(CMAKE_CXX_STANDARD 23)  # Use C++23
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

aux_source_directory(. SRC_LIST)
include_directories(asio/include)
add_executable(${PROJECT_NAME} ${SRC_LIST})