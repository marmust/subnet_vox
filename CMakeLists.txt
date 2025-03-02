cmake_minimum_required(VERSION 3.10.0)
project(subnet_vox VERSION 0.1.0 LANGUAGES C CXX)

# Include headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Define the source files
set(NETWORKING_SOURCES networking.cpp message.cpp consoleGraphics.cpp userInterface.cpp)

# Define executables
add_executable(client client.cpp ${NETWORKING_SOURCES})

# Link Windows networking library
if (WIN32)
    target_link_libraries(client ws2_32)
endif()
