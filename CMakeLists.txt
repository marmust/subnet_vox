cmake_minimum_required(VERSION 3.10.0)
project(subnet_vox VERSION 0.1.0 LANGUAGES C CXX)

# Include headers
include_directories(${CMAKE_SOURCE_DIR}/include)

set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")

# Define the source files
set(NETWORKING_SOURCES networking.cpp message.cpp consoleGraphics.cpp userInterface.cpp)

# Define executables
add_executable(client client.cpp ${NETWORKING_SOURCES})

# Link Windows networking library
if (WIN32)
    # Static runtime linkage
    foreach(flag_var
            CMAKE_C_FLAGS_RELEASE CMAKE_C_FLAGS_DEBUG
            CMAKE_CXX_FLAGS_RELEASE CMAKE_CXX_FLAGS_DEBUG)
        string(REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
    endforeach()

    target_link_libraries(client ws2_32)
endif()

