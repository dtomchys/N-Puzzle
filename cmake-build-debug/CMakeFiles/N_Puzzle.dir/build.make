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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dtomchys/Study/N-Puzzle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dtomchys/Study/N-Puzzle/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/N_Puzzle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/N_Puzzle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/N_Puzzle.dir/flags.make

CMakeFiles/N_Puzzle.dir/main.cpp.o: CMakeFiles/N_Puzzle.dir/flags.make
CMakeFiles/N_Puzzle.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dtomchys/Study/N-Puzzle/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/N_Puzzle.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/N_Puzzle.dir/main.cpp.o -c /Users/dtomchys/Study/N-Puzzle/main.cpp

CMakeFiles/N_Puzzle.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/N_Puzzle.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dtomchys/Study/N-Puzzle/main.cpp > CMakeFiles/N_Puzzle.dir/main.cpp.i

CMakeFiles/N_Puzzle.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/N_Puzzle.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dtomchys/Study/N-Puzzle/main.cpp -o CMakeFiles/N_Puzzle.dir/main.cpp.s

CMakeFiles/N_Puzzle.dir/src/ErrorManager.cpp.o: CMakeFiles/N_Puzzle.dir/flags.make
CMakeFiles/N_Puzzle.dir/src/ErrorManager.cpp.o: ../src/ErrorManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dtomchys/Study/N-Puzzle/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/N_Puzzle.dir/src/ErrorManager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/N_Puzzle.dir/src/ErrorManager.cpp.o -c /Users/dtomchys/Study/N-Puzzle/src/ErrorManager.cpp

CMakeFiles/N_Puzzle.dir/src/ErrorManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/N_Puzzle.dir/src/ErrorManager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dtomchys/Study/N-Puzzle/src/ErrorManager.cpp > CMakeFiles/N_Puzzle.dir/src/ErrorManager.cpp.i

CMakeFiles/N_Puzzle.dir/src/ErrorManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/N_Puzzle.dir/src/ErrorManager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dtomchys/Study/N-Puzzle/src/ErrorManager.cpp -o CMakeFiles/N_Puzzle.dir/src/ErrorManager.cpp.s

CMakeFiles/N_Puzzle.dir/src/ArgumentHandler.cpp.o: CMakeFiles/N_Puzzle.dir/flags.make
CMakeFiles/N_Puzzle.dir/src/ArgumentHandler.cpp.o: ../src/ArgumentHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dtomchys/Study/N-Puzzle/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/N_Puzzle.dir/src/ArgumentHandler.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/N_Puzzle.dir/src/ArgumentHandler.cpp.o -c /Users/dtomchys/Study/N-Puzzle/src/ArgumentHandler.cpp

CMakeFiles/N_Puzzle.dir/src/ArgumentHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/N_Puzzle.dir/src/ArgumentHandler.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dtomchys/Study/N-Puzzle/src/ArgumentHandler.cpp > CMakeFiles/N_Puzzle.dir/src/ArgumentHandler.cpp.i

CMakeFiles/N_Puzzle.dir/src/ArgumentHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/N_Puzzle.dir/src/ArgumentHandler.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dtomchys/Study/N-Puzzle/src/ArgumentHandler.cpp -o CMakeFiles/N_Puzzle.dir/src/ArgumentHandler.cpp.s

# Object files for target N_Puzzle
N_Puzzle_OBJECTS = \
"CMakeFiles/N_Puzzle.dir/main.cpp.o" \
"CMakeFiles/N_Puzzle.dir/src/ErrorManager.cpp.o" \
"CMakeFiles/N_Puzzle.dir/src/ArgumentHandler.cpp.o"

# External object files for target N_Puzzle
N_Puzzle_EXTERNAL_OBJECTS =

N_Puzzle: CMakeFiles/N_Puzzle.dir/main.cpp.o
N_Puzzle: CMakeFiles/N_Puzzle.dir/src/ErrorManager.cpp.o
N_Puzzle: CMakeFiles/N_Puzzle.dir/src/ArgumentHandler.cpp.o
N_Puzzle: CMakeFiles/N_Puzzle.dir/build.make
N_Puzzle: CMakeFiles/N_Puzzle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dtomchys/Study/N-Puzzle/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable N_Puzzle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/N_Puzzle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/N_Puzzle.dir/build: N_Puzzle

.PHONY : CMakeFiles/N_Puzzle.dir/build

CMakeFiles/N_Puzzle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/N_Puzzle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/N_Puzzle.dir/clean

CMakeFiles/N_Puzzle.dir/depend:
	cd /Users/dtomchys/Study/N-Puzzle/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dtomchys/Study/N-Puzzle /Users/dtomchys/Study/N-Puzzle /Users/dtomchys/Study/N-Puzzle/cmake-build-debug /Users/dtomchys/Study/N-Puzzle/cmake-build-debug /Users/dtomchys/Study/N-Puzzle/cmake-build-debug/CMakeFiles/N_Puzzle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/N_Puzzle.dir/depend

