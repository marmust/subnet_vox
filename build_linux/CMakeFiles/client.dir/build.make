# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sedgrz/Desktop/subnet_vox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sedgrz/Desktop/subnet_vox/build

# Include any dependencies generated for this target.
include CMakeFiles/client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/client.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

CMakeFiles/client.dir/client.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/client.cpp.o: /home/sedgrz/Desktop/subnet_vox/client.cpp
CMakeFiles/client.dir/client.cpp.o: CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sedgrz/Desktop/subnet_vox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client.dir/client.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/client.dir/client.cpp.o -MF CMakeFiles/client.dir/client.cpp.o.d -o CMakeFiles/client.dir/client.cpp.o -c /home/sedgrz/Desktop/subnet_vox/client.cpp

CMakeFiles/client.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/client.dir/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sedgrz/Desktop/subnet_vox/client.cpp > CMakeFiles/client.dir/client.cpp.i

CMakeFiles/client.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/client.dir/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sedgrz/Desktop/subnet_vox/client.cpp -o CMakeFiles/client.dir/client.cpp.s

CMakeFiles/client.dir/networking.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/networking.cpp.o: /home/sedgrz/Desktop/subnet_vox/networking.cpp
CMakeFiles/client.dir/networking.cpp.o: CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sedgrz/Desktop/subnet_vox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/client.dir/networking.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/client.dir/networking.cpp.o -MF CMakeFiles/client.dir/networking.cpp.o.d -o CMakeFiles/client.dir/networking.cpp.o -c /home/sedgrz/Desktop/subnet_vox/networking.cpp

CMakeFiles/client.dir/networking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/client.dir/networking.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sedgrz/Desktop/subnet_vox/networking.cpp > CMakeFiles/client.dir/networking.cpp.i

CMakeFiles/client.dir/networking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/client.dir/networking.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sedgrz/Desktop/subnet_vox/networking.cpp -o CMakeFiles/client.dir/networking.cpp.s

CMakeFiles/client.dir/message.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/message.cpp.o: /home/sedgrz/Desktop/subnet_vox/message.cpp
CMakeFiles/client.dir/message.cpp.o: CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sedgrz/Desktop/subnet_vox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/client.dir/message.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/client.dir/message.cpp.o -MF CMakeFiles/client.dir/message.cpp.o.d -o CMakeFiles/client.dir/message.cpp.o -c /home/sedgrz/Desktop/subnet_vox/message.cpp

CMakeFiles/client.dir/message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/client.dir/message.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sedgrz/Desktop/subnet_vox/message.cpp > CMakeFiles/client.dir/message.cpp.i

CMakeFiles/client.dir/message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/client.dir/message.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sedgrz/Desktop/subnet_vox/message.cpp -o CMakeFiles/client.dir/message.cpp.s

CMakeFiles/client.dir/consoleGraphics.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/consoleGraphics.cpp.o: /home/sedgrz/Desktop/subnet_vox/consoleGraphics.cpp
CMakeFiles/client.dir/consoleGraphics.cpp.o: CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sedgrz/Desktop/subnet_vox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/client.dir/consoleGraphics.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/client.dir/consoleGraphics.cpp.o -MF CMakeFiles/client.dir/consoleGraphics.cpp.o.d -o CMakeFiles/client.dir/consoleGraphics.cpp.o -c /home/sedgrz/Desktop/subnet_vox/consoleGraphics.cpp

CMakeFiles/client.dir/consoleGraphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/client.dir/consoleGraphics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sedgrz/Desktop/subnet_vox/consoleGraphics.cpp > CMakeFiles/client.dir/consoleGraphics.cpp.i

CMakeFiles/client.dir/consoleGraphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/client.dir/consoleGraphics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sedgrz/Desktop/subnet_vox/consoleGraphics.cpp -o CMakeFiles/client.dir/consoleGraphics.cpp.s

CMakeFiles/client.dir/userInterface.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/userInterface.cpp.o: /home/sedgrz/Desktop/subnet_vox/userInterface.cpp
CMakeFiles/client.dir/userInterface.cpp.o: CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sedgrz/Desktop/subnet_vox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/client.dir/userInterface.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/client.dir/userInterface.cpp.o -MF CMakeFiles/client.dir/userInterface.cpp.o.d -o CMakeFiles/client.dir/userInterface.cpp.o -c /home/sedgrz/Desktop/subnet_vox/userInterface.cpp

CMakeFiles/client.dir/userInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/client.dir/userInterface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sedgrz/Desktop/subnet_vox/userInterface.cpp > CMakeFiles/client.dir/userInterface.cpp.i

CMakeFiles/client.dir/userInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/client.dir/userInterface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sedgrz/Desktop/subnet_vox/userInterface.cpp -o CMakeFiles/client.dir/userInterface.cpp.s

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/client.cpp.o" \
"CMakeFiles/client.dir/networking.cpp.o" \
"CMakeFiles/client.dir/message.cpp.o" \
"CMakeFiles/client.dir/consoleGraphics.cpp.o" \
"CMakeFiles/client.dir/userInterface.cpp.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

client: CMakeFiles/client.dir/client.cpp.o
client: CMakeFiles/client.dir/networking.cpp.o
client: CMakeFiles/client.dir/message.cpp.o
client: CMakeFiles/client.dir/consoleGraphics.cpp.o
client: CMakeFiles/client.dir/userInterface.cpp.o
client: CMakeFiles/client.dir/build.make
client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/sedgrz/Desktop/subnet_vox/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: client
.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend:
	cd /home/sedgrz/Desktop/subnet_vox/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sedgrz/Desktop/subnet_vox /home/sedgrz/Desktop/subnet_vox /home/sedgrz/Desktop/subnet_vox/build /home/sedgrz/Desktop/subnet_vox/build /home/sedgrz/Desktop/subnet_vox/build/CMakeFiles/client.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/client.dir/depend

