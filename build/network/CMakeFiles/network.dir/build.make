# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/right/git-right

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/right/git-right/build

# Include any dependencies generated for this target.
include network/CMakeFiles/network.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include network/CMakeFiles/network.dir/compiler_depend.make

# Include the progress variables for this target.
include network/CMakeFiles/network.dir/progress.make

# Include the compile flags for this target's objects.
include network/CMakeFiles/network.dir/flags.make

network/CMakeFiles/network.dir/Invoker.cpp.o: network/CMakeFiles/network.dir/flags.make
network/CMakeFiles/network.dir/Invoker.cpp.o: ../network/Invoker.cpp
network/CMakeFiles/network.dir/Invoker.cpp.o: network/CMakeFiles/network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/right/git-right/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object network/CMakeFiles/network.dir/Invoker.cpp.o"
	cd /home/right/git-right/build/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT network/CMakeFiles/network.dir/Invoker.cpp.o -MF CMakeFiles/network.dir/Invoker.cpp.o.d -o CMakeFiles/network.dir/Invoker.cpp.o -c /home/right/git-right/network/Invoker.cpp

network/CMakeFiles/network.dir/Invoker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network.dir/Invoker.cpp.i"
	cd /home/right/git-right/build/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/right/git-right/network/Invoker.cpp > CMakeFiles/network.dir/Invoker.cpp.i

network/CMakeFiles/network.dir/Invoker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network.dir/Invoker.cpp.s"
	cd /home/right/git-right/build/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/right/git-right/network/Invoker.cpp -o CMakeFiles/network.dir/Invoker.cpp.s

network/CMakeFiles/network.dir/Server.cpp.o: network/CMakeFiles/network.dir/flags.make
network/CMakeFiles/network.dir/Server.cpp.o: ../network/Server.cpp
network/CMakeFiles/network.dir/Server.cpp.o: network/CMakeFiles/network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/right/git-right/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object network/CMakeFiles/network.dir/Server.cpp.o"
	cd /home/right/git-right/build/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT network/CMakeFiles/network.dir/Server.cpp.o -MF CMakeFiles/network.dir/Server.cpp.o.d -o CMakeFiles/network.dir/Server.cpp.o -c /home/right/git-right/network/Server.cpp

network/CMakeFiles/network.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network.dir/Server.cpp.i"
	cd /home/right/git-right/build/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/right/git-right/network/Server.cpp > CMakeFiles/network.dir/Server.cpp.i

network/CMakeFiles/network.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network.dir/Server.cpp.s"
	cd /home/right/git-right/build/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/right/git-right/network/Server.cpp -o CMakeFiles/network.dir/Server.cpp.s

network/CMakeFiles/network.dir/Server_Stream.cpp.o: network/CMakeFiles/network.dir/flags.make
network/CMakeFiles/network.dir/Server_Stream.cpp.o: ../network/Server_Stream.cpp
network/CMakeFiles/network.dir/Server_Stream.cpp.o: network/CMakeFiles/network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/right/git-right/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object network/CMakeFiles/network.dir/Server_Stream.cpp.o"
	cd /home/right/git-right/build/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT network/CMakeFiles/network.dir/Server_Stream.cpp.o -MF CMakeFiles/network.dir/Server_Stream.cpp.o.d -o CMakeFiles/network.dir/Server_Stream.cpp.o -c /home/right/git-right/network/Server_Stream.cpp

network/CMakeFiles/network.dir/Server_Stream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network.dir/Server_Stream.cpp.i"
	cd /home/right/git-right/build/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/right/git-right/network/Server_Stream.cpp > CMakeFiles/network.dir/Server_Stream.cpp.i

network/CMakeFiles/network.dir/Server_Stream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network.dir/Server_Stream.cpp.s"
	cd /home/right/git-right/build/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/right/git-right/network/Server_Stream.cpp -o CMakeFiles/network.dir/Server_Stream.cpp.s

network/CMakeFiles/network.dir/Task_Thread.cpp.o: network/CMakeFiles/network.dir/flags.make
network/CMakeFiles/network.dir/Task_Thread.cpp.o: ../network/Task_Thread.cpp
network/CMakeFiles/network.dir/Task_Thread.cpp.o: network/CMakeFiles/network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/right/git-right/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object network/CMakeFiles/network.dir/Task_Thread.cpp.o"
	cd /home/right/git-right/build/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT network/CMakeFiles/network.dir/Task_Thread.cpp.o -MF CMakeFiles/network.dir/Task_Thread.cpp.o.d -o CMakeFiles/network.dir/Task_Thread.cpp.o -c /home/right/git-right/network/Task_Thread.cpp

network/CMakeFiles/network.dir/Task_Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network.dir/Task_Thread.cpp.i"
	cd /home/right/git-right/build/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/right/git-right/network/Task_Thread.cpp > CMakeFiles/network.dir/Task_Thread.cpp.i

network/CMakeFiles/network.dir/Task_Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network.dir/Task_Thread.cpp.s"
	cd /home/right/git-right/build/network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/right/git-right/network/Task_Thread.cpp -o CMakeFiles/network.dir/Task_Thread.cpp.s

# Object files for target network
network_OBJECTS = \
"CMakeFiles/network.dir/Invoker.cpp.o" \
"CMakeFiles/network.dir/Server.cpp.o" \
"CMakeFiles/network.dir/Server_Stream.cpp.o" \
"CMakeFiles/network.dir/Task_Thread.cpp.o"

# External object files for target network
network_EXTERNAL_OBJECTS =

network/libnetwork.so: network/CMakeFiles/network.dir/Invoker.cpp.o
network/libnetwork.so: network/CMakeFiles/network.dir/Server.cpp.o
network/libnetwork.so: network/CMakeFiles/network.dir/Server_Stream.cpp.o
network/libnetwork.so: network/CMakeFiles/network.dir/Task_Thread.cpp.o
network/libnetwork.so: network/CMakeFiles/network.dir/build.make
network/libnetwork.so: network/CMakeFiles/network.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/right/git-right/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX shared library libnetwork.so"
	cd /home/right/git-right/build/network && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/network.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
network/CMakeFiles/network.dir/build: network/libnetwork.so
.PHONY : network/CMakeFiles/network.dir/build

network/CMakeFiles/network.dir/clean:
	cd /home/right/git-right/build/network && $(CMAKE_COMMAND) -P CMakeFiles/network.dir/cmake_clean.cmake
.PHONY : network/CMakeFiles/network.dir/clean

network/CMakeFiles/network.dir/depend:
	cd /home/right/git-right/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/right/git-right /home/right/git-right/network /home/right/git-right/build /home/right/git-right/build/network /home/right/git-right/build/network/CMakeFiles/network.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : network/CMakeFiles/network.dir/depend
