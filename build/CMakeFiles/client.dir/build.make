# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 4.0

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\build

# Include any dependencies generated for this target.
include CMakeFiles/client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/client.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

CMakeFiles/client.dir/codegen:
.PHONY : CMakeFiles/client.dir/codegen

CMakeFiles/client.dir/client.cpp.obj: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/client.cpp.obj: CMakeFiles/client.dir/includes_CXX.rsp
CMakeFiles/client.dir/client.cpp.obj: C:/Users/user/Desktop/AUTOENCODER/git_drop/subnet_vox/client.cpp
CMakeFiles/client.dir/client.cpp.obj: CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client.dir/client.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/client.dir/client.cpp.obj -MF CMakeFiles\client.dir\client.cpp.obj.d -o CMakeFiles\client.dir\client.cpp.obj -c C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\client.cpp

CMakeFiles/client.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/client.dir/client.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\client.cpp > CMakeFiles\client.dir\client.cpp.i

CMakeFiles/client.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/client.dir/client.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\client.cpp -o CMakeFiles\client.dir\client.cpp.s

CMakeFiles/client.dir/networking.cpp.obj: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/networking.cpp.obj: CMakeFiles/client.dir/includes_CXX.rsp
CMakeFiles/client.dir/networking.cpp.obj: C:/Users/user/Desktop/AUTOENCODER/git_drop/subnet_vox/networking.cpp
CMakeFiles/client.dir/networking.cpp.obj: CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/client.dir/networking.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/client.dir/networking.cpp.obj -MF CMakeFiles\client.dir\networking.cpp.obj.d -o CMakeFiles\client.dir\networking.cpp.obj -c C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\networking.cpp

CMakeFiles/client.dir/networking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/client.dir/networking.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\networking.cpp > CMakeFiles\client.dir\networking.cpp.i

CMakeFiles/client.dir/networking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/client.dir/networking.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\networking.cpp -o CMakeFiles\client.dir\networking.cpp.s

CMakeFiles/client.dir/message.cpp.obj: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/message.cpp.obj: CMakeFiles/client.dir/includes_CXX.rsp
CMakeFiles/client.dir/message.cpp.obj: C:/Users/user/Desktop/AUTOENCODER/git_drop/subnet_vox/message.cpp
CMakeFiles/client.dir/message.cpp.obj: CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/client.dir/message.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/client.dir/message.cpp.obj -MF CMakeFiles\client.dir\message.cpp.obj.d -o CMakeFiles\client.dir\message.cpp.obj -c C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\message.cpp

CMakeFiles/client.dir/message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/client.dir/message.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\message.cpp > CMakeFiles\client.dir\message.cpp.i

CMakeFiles/client.dir/message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/client.dir/message.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\message.cpp -o CMakeFiles\client.dir\message.cpp.s

CMakeFiles/client.dir/consoleGraphics.cpp.obj: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/consoleGraphics.cpp.obj: CMakeFiles/client.dir/includes_CXX.rsp
CMakeFiles/client.dir/consoleGraphics.cpp.obj: C:/Users/user/Desktop/AUTOENCODER/git_drop/subnet_vox/consoleGraphics.cpp
CMakeFiles/client.dir/consoleGraphics.cpp.obj: CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/client.dir/consoleGraphics.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/client.dir/consoleGraphics.cpp.obj -MF CMakeFiles\client.dir\consoleGraphics.cpp.obj.d -o CMakeFiles\client.dir\consoleGraphics.cpp.obj -c C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\consoleGraphics.cpp

CMakeFiles/client.dir/consoleGraphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/client.dir/consoleGraphics.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\consoleGraphics.cpp > CMakeFiles\client.dir\consoleGraphics.cpp.i

CMakeFiles/client.dir/consoleGraphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/client.dir/consoleGraphics.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\consoleGraphics.cpp -o CMakeFiles\client.dir\consoleGraphics.cpp.s

CMakeFiles/client.dir/userInterface.cpp.obj: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/userInterface.cpp.obj: CMakeFiles/client.dir/includes_CXX.rsp
CMakeFiles/client.dir/userInterface.cpp.obj: C:/Users/user/Desktop/AUTOENCODER/git_drop/subnet_vox/userInterface.cpp
CMakeFiles/client.dir/userInterface.cpp.obj: CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/client.dir/userInterface.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/client.dir/userInterface.cpp.obj -MF CMakeFiles\client.dir\userInterface.cpp.obj.d -o CMakeFiles\client.dir\userInterface.cpp.obj -c C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\userInterface.cpp

CMakeFiles/client.dir/userInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/client.dir/userInterface.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\userInterface.cpp > CMakeFiles\client.dir\userInterface.cpp.i

CMakeFiles/client.dir/userInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/client.dir/userInterface.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\userInterface.cpp -o CMakeFiles\client.dir\userInterface.cpp.s

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/client.cpp.obj" \
"CMakeFiles/client.dir/networking.cpp.obj" \
"CMakeFiles/client.dir/message.cpp.obj" \
"CMakeFiles/client.dir/consoleGraphics.cpp.obj" \
"CMakeFiles/client.dir/userInterface.cpp.obj"

# External object files for target client
client_EXTERNAL_OBJECTS =

client.exe: CMakeFiles/client.dir/client.cpp.obj
client.exe: CMakeFiles/client.dir/networking.cpp.obj
client.exe: CMakeFiles/client.dir/message.cpp.obj
client.exe: CMakeFiles/client.dir/consoleGraphics.cpp.obj
client.exe: CMakeFiles/client.dir/userInterface.cpp.obj
client.exe: CMakeFiles/client.dir/build.make
client.exe: CMakeFiles/client.dir/linkLibs.rsp
client.exe: CMakeFiles/client.dir/objects1.rsp
client.exe: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable client.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\client.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: client.exe
.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\client.dir\cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\build C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\build C:\Users\user\Desktop\AUTOENCODER\git_drop\subnet_vox\build\CMakeFiles\client.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/client.dir/depend

