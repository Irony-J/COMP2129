# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/irony/Documents/Code/COMP2129/Basic Reference Counting"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/irony/Documents/Code/COMP2129/Basic Reference Counting/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Basic_Reference_Counting.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Basic_Reference_Counting.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Basic_Reference_Counting.dir/flags.make

CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.o: CMakeFiles/Basic_Reference_Counting.dir/flags.make
CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.o: ../mem_ref.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/irony/Documents/Code/COMP2129/Basic Reference Counting/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.o   -c "/Users/irony/Documents/Code/COMP2129/Basic Reference Counting/mem_ref.c"

CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/irony/Documents/Code/COMP2129/Basic Reference Counting/mem_ref.c" > CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.i

CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/irony/Documents/Code/COMP2129/Basic Reference Counting/mem_ref.c" -o CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.s

CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.o.requires:

.PHONY : CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.o.requires

CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.o.provides: CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.o.requires
	$(MAKE) -f CMakeFiles/Basic_Reference_Counting.dir/build.make CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.o.provides.build
.PHONY : CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.o.provides

CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.o.provides.build: CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.o


CMakeFiles/Basic_Reference_Counting.dir/run.c.o: CMakeFiles/Basic_Reference_Counting.dir/flags.make
CMakeFiles/Basic_Reference_Counting.dir/run.c.o: ../run.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/irony/Documents/Code/COMP2129/Basic Reference Counting/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Basic_Reference_Counting.dir/run.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Basic_Reference_Counting.dir/run.c.o   -c "/Users/irony/Documents/Code/COMP2129/Basic Reference Counting/run.c"

CMakeFiles/Basic_Reference_Counting.dir/run.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Basic_Reference_Counting.dir/run.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/irony/Documents/Code/COMP2129/Basic Reference Counting/run.c" > CMakeFiles/Basic_Reference_Counting.dir/run.c.i

CMakeFiles/Basic_Reference_Counting.dir/run.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Basic_Reference_Counting.dir/run.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/irony/Documents/Code/COMP2129/Basic Reference Counting/run.c" -o CMakeFiles/Basic_Reference_Counting.dir/run.c.s

CMakeFiles/Basic_Reference_Counting.dir/run.c.o.requires:

.PHONY : CMakeFiles/Basic_Reference_Counting.dir/run.c.o.requires

CMakeFiles/Basic_Reference_Counting.dir/run.c.o.provides: CMakeFiles/Basic_Reference_Counting.dir/run.c.o.requires
	$(MAKE) -f CMakeFiles/Basic_Reference_Counting.dir/build.make CMakeFiles/Basic_Reference_Counting.dir/run.c.o.provides.build
.PHONY : CMakeFiles/Basic_Reference_Counting.dir/run.c.o.provides

CMakeFiles/Basic_Reference_Counting.dir/run.c.o.provides.build: CMakeFiles/Basic_Reference_Counting.dir/run.c.o


# Object files for target Basic_Reference_Counting
Basic_Reference_Counting_OBJECTS = \
"CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.o" \
"CMakeFiles/Basic_Reference_Counting.dir/run.c.o"

# External object files for target Basic_Reference_Counting
Basic_Reference_Counting_EXTERNAL_OBJECTS =

Basic_Reference_Counting: CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.o
Basic_Reference_Counting: CMakeFiles/Basic_Reference_Counting.dir/run.c.o
Basic_Reference_Counting: CMakeFiles/Basic_Reference_Counting.dir/build.make
Basic_Reference_Counting: CMakeFiles/Basic_Reference_Counting.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/irony/Documents/Code/COMP2129/Basic Reference Counting/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Basic_Reference_Counting"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Basic_Reference_Counting.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Basic_Reference_Counting.dir/build: Basic_Reference_Counting

.PHONY : CMakeFiles/Basic_Reference_Counting.dir/build

CMakeFiles/Basic_Reference_Counting.dir/requires: CMakeFiles/Basic_Reference_Counting.dir/mem_ref.c.o.requires
CMakeFiles/Basic_Reference_Counting.dir/requires: CMakeFiles/Basic_Reference_Counting.dir/run.c.o.requires

.PHONY : CMakeFiles/Basic_Reference_Counting.dir/requires

CMakeFiles/Basic_Reference_Counting.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Basic_Reference_Counting.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Basic_Reference_Counting.dir/clean

CMakeFiles/Basic_Reference_Counting.dir/depend:
	cd "/Users/irony/Documents/Code/COMP2129/Basic Reference Counting/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/irony/Documents/Code/COMP2129/Basic Reference Counting" "/Users/irony/Documents/Code/COMP2129/Basic Reference Counting" "/Users/irony/Documents/Code/COMP2129/Basic Reference Counting/cmake-build-debug" "/Users/irony/Documents/Code/COMP2129/Basic Reference Counting/cmake-build-debug" "/Users/irony/Documents/Code/COMP2129/Basic Reference Counting/cmake-build-debug/CMakeFiles/Basic_Reference_Counting.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Basic_Reference_Counting.dir/depend
