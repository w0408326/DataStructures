# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/student2007/Downloads/clion-2019.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/student2007/Downloads/clion-2019.3.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student2007/CLionProjects/LinkedListsDeletion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student2007/CLionProjects/LinkedListsDeletion/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LinkedListsDeletion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LinkedListsDeletion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LinkedListsDeletion.dir/flags.make

CMakeFiles/LinkedListsDeletion.dir/main.cpp.o: CMakeFiles/LinkedListsDeletion.dir/flags.make
CMakeFiles/LinkedListsDeletion.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student2007/CLionProjects/LinkedListsDeletion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LinkedListsDeletion.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LinkedListsDeletion.dir/main.cpp.o -c /home/student2007/CLionProjects/LinkedListsDeletion/main.cpp

CMakeFiles/LinkedListsDeletion.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LinkedListsDeletion.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student2007/CLionProjects/LinkedListsDeletion/main.cpp > CMakeFiles/LinkedListsDeletion.dir/main.cpp.i

CMakeFiles/LinkedListsDeletion.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LinkedListsDeletion.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student2007/CLionProjects/LinkedListsDeletion/main.cpp -o CMakeFiles/LinkedListsDeletion.dir/main.cpp.s

# Object files for target LinkedListsDeletion
LinkedListsDeletion_OBJECTS = \
"CMakeFiles/LinkedListsDeletion.dir/main.cpp.o"

# External object files for target LinkedListsDeletion
LinkedListsDeletion_EXTERNAL_OBJECTS =

LinkedListsDeletion: CMakeFiles/LinkedListsDeletion.dir/main.cpp.o
LinkedListsDeletion: CMakeFiles/LinkedListsDeletion.dir/build.make
LinkedListsDeletion: CMakeFiles/LinkedListsDeletion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student2007/CLionProjects/LinkedListsDeletion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LinkedListsDeletion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LinkedListsDeletion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LinkedListsDeletion.dir/build: LinkedListsDeletion

.PHONY : CMakeFiles/LinkedListsDeletion.dir/build

CMakeFiles/LinkedListsDeletion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LinkedListsDeletion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LinkedListsDeletion.dir/clean

CMakeFiles/LinkedListsDeletion.dir/depend:
	cd /home/student2007/CLionProjects/LinkedListsDeletion/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student2007/CLionProjects/LinkedListsDeletion /home/student2007/CLionProjects/LinkedListsDeletion /home/student2007/CLionProjects/LinkedListsDeletion/cmake-build-debug /home/student2007/CLionProjects/LinkedListsDeletion/cmake-build-debug /home/student2007/CLionProjects/LinkedListsDeletion/cmake-build-debug/CMakeFiles/LinkedListsDeletion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LinkedListsDeletion.dir/depend
