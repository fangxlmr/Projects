# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Shared\Projects\1.Tetris

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Shared\Projects\1.Tetris\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tetris.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tetris.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tetris.dir/flags.make

CMakeFiles/Tetris.dir/demo.c.obj: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/demo.c.obj: ../demo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Shared\Projects\1.Tetris\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Tetris.dir/demo.c.obj"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Tetris.dir\demo.c.obj   -c D:\Shared\Projects\1.Tetris\demo.c

CMakeFiles/Tetris.dir/demo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tetris.dir/demo.c.i"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Shared\Projects\1.Tetris\demo.c > CMakeFiles\Tetris.dir\demo.c.i

CMakeFiles/Tetris.dir/demo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tetris.dir/demo.c.s"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Shared\Projects\1.Tetris\demo.c -o CMakeFiles\Tetris.dir\demo.c.s

CMakeFiles/Tetris.dir/demo.c.obj.requires:

.PHONY : CMakeFiles/Tetris.dir/demo.c.obj.requires

CMakeFiles/Tetris.dir/demo.c.obj.provides: CMakeFiles/Tetris.dir/demo.c.obj.requires
	$(MAKE) -f CMakeFiles\Tetris.dir\build.make CMakeFiles/Tetris.dir/demo.c.obj.provides.build
.PHONY : CMakeFiles/Tetris.dir/demo.c.obj.provides

CMakeFiles/Tetris.dir/demo.c.obj.provides.build: CMakeFiles/Tetris.dir/demo.c.obj


# Object files for target Tetris
Tetris_OBJECTS = \
"CMakeFiles/Tetris.dir/demo.c.obj"

# External object files for target Tetris
Tetris_EXTERNAL_OBJECTS =

Tetris.exe: CMakeFiles/Tetris.dir/demo.c.obj
Tetris.exe: CMakeFiles/Tetris.dir/build.make
Tetris.exe: CMakeFiles/Tetris.dir/linklibs.rsp
Tetris.exe: CMakeFiles/Tetris.dir/objects1.rsp
Tetris.exe: CMakeFiles/Tetris.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Shared\Projects\1.Tetris\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Tetris.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Tetris.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tetris.dir/build: Tetris.exe

.PHONY : CMakeFiles/Tetris.dir/build

CMakeFiles/Tetris.dir/requires: CMakeFiles/Tetris.dir/demo.c.obj.requires

.PHONY : CMakeFiles/Tetris.dir/requires

CMakeFiles/Tetris.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Tetris.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Tetris.dir/clean

CMakeFiles/Tetris.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Shared\Projects\1.Tetris D:\Shared\Projects\1.Tetris D:\Shared\Projects\1.Tetris\cmake-build-debug D:\Shared\Projects\1.Tetris\cmake-build-debug D:\Shared\Projects\1.Tetris\cmake-build-debug\CMakeFiles\Tetris.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tetris.dir/depend

