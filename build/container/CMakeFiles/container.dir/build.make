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
include container/CMakeFiles/container.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include container/CMakeFiles/container.dir/compiler_depend.make

# Include the progress variables for this target.
include container/CMakeFiles/container.dir/progress.make

# Include the compile flags for this target's objects.
include container/CMakeFiles/container.dir/flags.make

container/CMakeFiles/container.dir/Command.cpp.o: container/CMakeFiles/container.dir/flags.make
container/CMakeFiles/container.dir/Command.cpp.o: ../container/Command.cpp
container/CMakeFiles/container.dir/Command.cpp.o: container/CMakeFiles/container.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/right/git-right/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object container/CMakeFiles/container.dir/Command.cpp.o"
	cd /home/right/git-right/build/container && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT container/CMakeFiles/container.dir/Command.cpp.o -MF CMakeFiles/container.dir/Command.cpp.o.d -o CMakeFiles/container.dir/Command.cpp.o -c /home/right/git-right/container/Command.cpp

container/CMakeFiles/container.dir/Command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/container.dir/Command.cpp.i"
	cd /home/right/git-right/build/container && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/right/git-right/container/Command.cpp > CMakeFiles/container.dir/Command.cpp.i

container/CMakeFiles/container.dir/Command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/container.dir/Command.cpp.s"
	cd /home/right/git-right/build/container && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/right/git-right/container/Command.cpp -o CMakeFiles/container.dir/Command.cpp.s

container/CMakeFiles/container.dir/Command_Factory.cpp.o: container/CMakeFiles/container.dir/flags.make
container/CMakeFiles/container.dir/Command_Factory.cpp.o: ../container/Command_Factory.cpp
container/CMakeFiles/container.dir/Command_Factory.cpp.o: container/CMakeFiles/container.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/right/git-right/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object container/CMakeFiles/container.dir/Command_Factory.cpp.o"
	cd /home/right/git-right/build/container && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT container/CMakeFiles/container.dir/Command_Factory.cpp.o -MF CMakeFiles/container.dir/Command_Factory.cpp.o.d -o CMakeFiles/container.dir/Command_Factory.cpp.o -c /home/right/git-right/container/Command_Factory.cpp

container/CMakeFiles/container.dir/Command_Factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/container.dir/Command_Factory.cpp.i"
	cd /home/right/git-right/build/container && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/right/git-right/container/Command_Factory.cpp > CMakeFiles/container.dir/Command_Factory.cpp.i

container/CMakeFiles/container.dir/Command_Factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/container.dir/Command_Factory.cpp.s"
	cd /home/right/git-right/build/container && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/right/git-right/container/Command_Factory.cpp -o CMakeFiles/container.dir/Command_Factory.cpp.s

container/CMakeFiles/container.dir/Register_Action.cpp.o: container/CMakeFiles/container.dir/flags.make
container/CMakeFiles/container.dir/Register_Action.cpp.o: ../container/Register_Action.cpp
container/CMakeFiles/container.dir/Register_Action.cpp.o: container/CMakeFiles/container.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/right/git-right/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object container/CMakeFiles/container.dir/Register_Action.cpp.o"
	cd /home/right/git-right/build/container && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT container/CMakeFiles/container.dir/Register_Action.cpp.o -MF CMakeFiles/container.dir/Register_Action.cpp.o.d -o CMakeFiles/container.dir/Register_Action.cpp.o -c /home/right/git-right/container/Register_Action.cpp

container/CMakeFiles/container.dir/Register_Action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/container.dir/Register_Action.cpp.i"
	cd /home/right/git-right/build/container && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/right/git-right/container/Register_Action.cpp > CMakeFiles/container.dir/Register_Action.cpp.i

container/CMakeFiles/container.dir/Register_Action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/container.dir/Register_Action.cpp.s"
	cd /home/right/git-right/build/container && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/right/git-right/container/Register_Action.cpp -o CMakeFiles/container.dir/Register_Action.cpp.s

# Object files for target container
container_OBJECTS = \
"CMakeFiles/container.dir/Command.cpp.o" \
"CMakeFiles/container.dir/Command_Factory.cpp.o" \
"CMakeFiles/container.dir/Register_Action.cpp.o"

# External object files for target container
container_EXTERNAL_OBJECTS =

container/libcontainer.so: container/CMakeFiles/container.dir/Command.cpp.o
container/libcontainer.so: container/CMakeFiles/container.dir/Command_Factory.cpp.o
container/libcontainer.so: container/CMakeFiles/container.dir/Register_Action.cpp.o
container/libcontainer.so: container/CMakeFiles/container.dir/build.make
container/libcontainer.so: common/libcommon.so
container/libcontainer.so: container/CMakeFiles/container.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/right/git-right/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library libcontainer.so"
	cd /home/right/git-right/build/container && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/container.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
container/CMakeFiles/container.dir/build: container/libcontainer.so
.PHONY : container/CMakeFiles/container.dir/build

container/CMakeFiles/container.dir/clean:
	cd /home/right/git-right/build/container && $(CMAKE_COMMAND) -P CMakeFiles/container.dir/cmake_clean.cmake
.PHONY : container/CMakeFiles/container.dir/clean

container/CMakeFiles/container.dir/depend:
	cd /home/right/git-right/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/right/git-right /home/right/git-right/container /home/right/git-right/build /home/right/git-right/build/container /home/right/git-right/build/container/CMakeFiles/container.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : container/CMakeFiles/container.dir/depend

