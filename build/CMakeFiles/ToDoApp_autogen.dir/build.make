# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hw20a124/Desktop/ToDoApp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hw20a124/Desktop/ToDoApp/build

# Utility rule file for ToDoApp_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/ToDoApp_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ToDoApp_autogen.dir/progress.make

CMakeFiles/ToDoApp_autogen: ToDoApp_autogen/timestamp

ToDoApp_autogen/timestamp: /usr/local/share/qt/libexec/moc
ToDoApp_autogen/timestamp: /usr/local/share/qt/libexec/uic
ToDoApp_autogen/timestamp: CMakeFiles/ToDoApp_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/hw20a124/Desktop/ToDoApp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target ToDoApp"
	/usr/local/bin/cmake -E cmake_autogen /Users/hw20a124/Desktop/ToDoApp/build/CMakeFiles/ToDoApp_autogen.dir/AutogenInfo.json ""
	/usr/local/bin/cmake -E touch /Users/hw20a124/Desktop/ToDoApp/build/ToDoApp_autogen/timestamp

CMakeFiles/ToDoApp_autogen.dir/codegen:
.PHONY : CMakeFiles/ToDoApp_autogen.dir/codegen

ToDoApp_autogen: CMakeFiles/ToDoApp_autogen
ToDoApp_autogen: ToDoApp_autogen/timestamp
ToDoApp_autogen: CMakeFiles/ToDoApp_autogen.dir/build.make
.PHONY : ToDoApp_autogen

# Rule to build all files generated by this target.
CMakeFiles/ToDoApp_autogen.dir/build: ToDoApp_autogen
.PHONY : CMakeFiles/ToDoApp_autogen.dir/build

CMakeFiles/ToDoApp_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ToDoApp_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ToDoApp_autogen.dir/clean

CMakeFiles/ToDoApp_autogen.dir/depend:
	cd /Users/hw20a124/Desktop/ToDoApp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hw20a124/Desktop/ToDoApp /Users/hw20a124/Desktop/ToDoApp /Users/hw20a124/Desktop/ToDoApp/build /Users/hw20a124/Desktop/ToDoApp/build /Users/hw20a124/Desktop/ToDoApp/build/CMakeFiles/ToDoApp_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ToDoApp_autogen.dir/depend

