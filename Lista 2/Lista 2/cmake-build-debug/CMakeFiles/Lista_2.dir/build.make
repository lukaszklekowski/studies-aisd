# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = "D:\Program Files (x86)\JetBrains\CLion 2016.3.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files (x86)\JetBrains\CLion 2016.3.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Lukasz\CLionProjects\Lista 2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Lukasz\CLionProjects\Lista 2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Lista_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lista_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lista_2.dir/flags.make

CMakeFiles/Lista_2.dir/main.cpp.obj: CMakeFiles/Lista_2.dir/flags.make
CMakeFiles/Lista_2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Lukasz\CLionProjects\Lista 2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lista_2.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lista_2.dir\main.cpp.obj -c "C:\Users\Lukasz\CLionProjects\Lista 2\main.cpp"

CMakeFiles/Lista_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lista_2.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Lukasz\CLionProjects\Lista 2\main.cpp" > CMakeFiles\Lista_2.dir\main.cpp.i

CMakeFiles/Lista_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lista_2.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Lukasz\CLionProjects\Lista 2\main.cpp" -o CMakeFiles\Lista_2.dir\main.cpp.s

CMakeFiles/Lista_2.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Lista_2.dir/main.cpp.obj.requires

CMakeFiles/Lista_2.dir/main.cpp.obj.provides: CMakeFiles/Lista_2.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Lista_2.dir\build.make CMakeFiles/Lista_2.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Lista_2.dir/main.cpp.obj.provides

CMakeFiles/Lista_2.dir/main.cpp.obj.provides.build: CMakeFiles/Lista_2.dir/main.cpp.obj


# Object files for target Lista_2
Lista_2_OBJECTS = \
"CMakeFiles/Lista_2.dir/main.cpp.obj"

# External object files for target Lista_2
Lista_2_EXTERNAL_OBJECTS =

Lista_2.exe: CMakeFiles/Lista_2.dir/main.cpp.obj
Lista_2.exe: CMakeFiles/Lista_2.dir/build.make
Lista_2.exe: CMakeFiles/Lista_2.dir/linklibs.rsp
Lista_2.exe: CMakeFiles/Lista_2.dir/objects1.rsp
Lista_2.exe: CMakeFiles/Lista_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Lukasz\CLionProjects\Lista 2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lista_2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lista_2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lista_2.dir/build: Lista_2.exe

.PHONY : CMakeFiles/Lista_2.dir/build

CMakeFiles/Lista_2.dir/requires: CMakeFiles/Lista_2.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Lista_2.dir/requires

CMakeFiles/Lista_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lista_2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lista_2.dir/clean

CMakeFiles/Lista_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Lukasz\CLionProjects\Lista 2" "C:\Users\Lukasz\CLionProjects\Lista 2" "C:\Users\Lukasz\CLionProjects\Lista 2\cmake-build-debug" "C:\Users\Lukasz\CLionProjects\Lista 2\cmake-build-debug" "C:\Users\Lukasz\CLionProjects\Lista 2\cmake-build-debug\CMakeFiles\Lista_2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lista_2.dir/depend
