# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fx/softDocument/vscode/cpp/muduo_server_learn/src/05

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fx/softDocument/vscode/cpp/muduo_server_learn/src/build

# Include any dependencies generated for this target.
include CMakeFiles/echosrv_poll.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/echosrv_poll.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/echosrv_poll.dir/flags.make

CMakeFiles/echosrv_poll.dir/echosrv_poll.cpp.o: CMakeFiles/echosrv_poll.dir/flags.make
CMakeFiles/echosrv_poll.dir/echosrv_poll.cpp.o: /home/fx/softDocument/vscode/cpp/muduo_server_learn/src/05/echosrv_poll.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/echosrv_poll.dir/echosrv_poll.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/echosrv_poll.dir/echosrv_poll.cpp.o -c /home/fx/softDocument/vscode/cpp/muduo_server_learn/src/05/echosrv_poll.cpp

CMakeFiles/echosrv_poll.dir/echosrv_poll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/echosrv_poll.dir/echosrv_poll.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fx/softDocument/vscode/cpp/muduo_server_learn/src/05/echosrv_poll.cpp > CMakeFiles/echosrv_poll.dir/echosrv_poll.cpp.i

CMakeFiles/echosrv_poll.dir/echosrv_poll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/echosrv_poll.dir/echosrv_poll.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fx/softDocument/vscode/cpp/muduo_server_learn/src/05/echosrv_poll.cpp -o CMakeFiles/echosrv_poll.dir/echosrv_poll.cpp.s

# Object files for target echosrv_poll
echosrv_poll_OBJECTS = \
"CMakeFiles/echosrv_poll.dir/echosrv_poll.cpp.o"

# External object files for target echosrv_poll
echosrv_poll_EXTERNAL_OBJECTS =

bin/echosrv_poll: CMakeFiles/echosrv_poll.dir/echosrv_poll.cpp.o
bin/echosrv_poll: CMakeFiles/echosrv_poll.dir/build.make
bin/echosrv_poll: CMakeFiles/echosrv_poll.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fx/softDocument/vscode/cpp/muduo_server_learn/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/echosrv_poll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/echosrv_poll.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/echosrv_poll.dir/build: bin/echosrv_poll

.PHONY : CMakeFiles/echosrv_poll.dir/build

CMakeFiles/echosrv_poll.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/echosrv_poll.dir/cmake_clean.cmake
.PHONY : CMakeFiles/echosrv_poll.dir/clean

CMakeFiles/echosrv_poll.dir/depend:
	cd /home/fx/softDocument/vscode/cpp/muduo_server_learn/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fx/softDocument/vscode/cpp/muduo_server_learn/src/05 /home/fx/softDocument/vscode/cpp/muduo_server_learn/src/05 /home/fx/softDocument/vscode/cpp/muduo_server_learn/src/build /home/fx/softDocument/vscode/cpp/muduo_server_learn/src/build /home/fx/softDocument/vscode/cpp/muduo_server_learn/src/build/CMakeFiles/echosrv_poll.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/echosrv_poll.dir/depend

