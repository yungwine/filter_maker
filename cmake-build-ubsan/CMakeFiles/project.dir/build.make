# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/maxankurb/Desktop/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/maxankurb/Desktop/project/cmake-build-ubsan

# Include any dependencies generated for this target.
include CMakeFiles/project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project.dir/flags.make

CMakeFiles/project.dir/main.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maxankurb/Desktop/project/cmake-build-ubsan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project.dir/main.cpp.o"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/main.cpp.o -c /Users/maxankurb/Desktop/project/main.cpp

CMakeFiles/project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/main.cpp.i"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maxankurb/Desktop/project/main.cpp > CMakeFiles/project.dir/main.cpp.i

CMakeFiles/project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/main.cpp.s"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maxankurb/Desktop/project/main.cpp -o CMakeFiles/project.dir/main.cpp.s

CMakeFiles/project.dir/command_line_parser.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/command_line_parser.cpp.o: ../command_line_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maxankurb/Desktop/project/cmake-build-ubsan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project.dir/command_line_parser.cpp.o"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/command_line_parser.cpp.o -c /Users/maxankurb/Desktop/project/command_line_parser.cpp

CMakeFiles/project.dir/command_line_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/command_line_parser.cpp.i"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maxankurb/Desktop/project/command_line_parser.cpp > CMakeFiles/project.dir/command_line_parser.cpp.i

CMakeFiles/project.dir/command_line_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/command_line_parser.cpp.s"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maxankurb/Desktop/project/command_line_parser.cpp -o CMakeFiles/project.dir/command_line_parser.cpp.s

CMakeFiles/project.dir/base_filter.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/base_filter.cpp.o: ../base_filter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maxankurb/Desktop/project/cmake-build-ubsan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project.dir/base_filter.cpp.o"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/base_filter.cpp.o -c /Users/maxankurb/Desktop/project/base_filter.cpp

CMakeFiles/project.dir/base_filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/base_filter.cpp.i"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maxankurb/Desktop/project/base_filter.cpp > CMakeFiles/project.dir/base_filter.cpp.i

CMakeFiles/project.dir/base_filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/base_filter.cpp.s"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maxankurb/Desktop/project/base_filter.cpp -o CMakeFiles/project.dir/base_filter.cpp.s

CMakeFiles/project.dir/filter_pipeline_maker.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/filter_pipeline_maker.cpp.o: ../filter_pipeline_maker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maxankurb/Desktop/project/cmake-build-ubsan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/project.dir/filter_pipeline_maker.cpp.o"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/filter_pipeline_maker.cpp.o -c /Users/maxankurb/Desktop/project/filter_pipeline_maker.cpp

CMakeFiles/project.dir/filter_pipeline_maker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/filter_pipeline_maker.cpp.i"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maxankurb/Desktop/project/filter_pipeline_maker.cpp > CMakeFiles/project.dir/filter_pipeline_maker.cpp.i

CMakeFiles/project.dir/filter_pipeline_maker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/filter_pipeline_maker.cpp.s"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maxankurb/Desktop/project/filter_pipeline_maker.cpp -o CMakeFiles/project.dir/filter_pipeline_maker.cpp.s

CMakeFiles/project.dir/application.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/application.cpp.o: ../application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maxankurb/Desktop/project/cmake-build-ubsan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/project.dir/application.cpp.o"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/application.cpp.o -c /Users/maxankurb/Desktop/project/application.cpp

CMakeFiles/project.dir/application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/application.cpp.i"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maxankurb/Desktop/project/application.cpp > CMakeFiles/project.dir/application.cpp.i

CMakeFiles/project.dir/application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/application.cpp.s"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maxankurb/Desktop/project/application.cpp -o CMakeFiles/project.dir/application.cpp.s

CMakeFiles/project.dir/bitmap.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/bitmap.cpp.o: ../bitmap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maxankurb/Desktop/project/cmake-build-ubsan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/project.dir/bitmap.cpp.o"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/bitmap.cpp.o -c /Users/maxankurb/Desktop/project/bitmap.cpp

CMakeFiles/project.dir/bitmap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/bitmap.cpp.i"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maxankurb/Desktop/project/bitmap.cpp > CMakeFiles/project.dir/bitmap.cpp.i

CMakeFiles/project.dir/bitmap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/bitmap.cpp.s"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maxankurb/Desktop/project/bitmap.cpp -o CMakeFiles/project.dir/bitmap.cpp.s

# Object files for target project
project_OBJECTS = \
"CMakeFiles/project.dir/main.cpp.o" \
"CMakeFiles/project.dir/command_line_parser.cpp.o" \
"CMakeFiles/project.dir/base_filter.cpp.o" \
"CMakeFiles/project.dir/filter_pipeline_maker.cpp.o" \
"CMakeFiles/project.dir/application.cpp.o" \
"CMakeFiles/project.dir/bitmap.cpp.o"

# External object files for target project
project_EXTERNAL_OBJECTS =

project: CMakeFiles/project.dir/main.cpp.o
project: CMakeFiles/project.dir/command_line_parser.cpp.o
project: CMakeFiles/project.dir/base_filter.cpp.o
project: CMakeFiles/project.dir/filter_pipeline_maker.cpp.o
project: CMakeFiles/project.dir/application.cpp.o
project: CMakeFiles/project.dir/bitmap.cpp.o
project: CMakeFiles/project.dir/build.make
project: CMakeFiles/project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/maxankurb/Desktop/project/cmake-build-ubsan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project.dir/build: project

.PHONY : CMakeFiles/project.dir/build

CMakeFiles/project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project.dir/clean

CMakeFiles/project.dir/depend:
	cd /Users/maxankurb/Desktop/project/cmake-build-ubsan && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maxankurb/Desktop/project /Users/maxankurb/Desktop/project /Users/maxankurb/Desktop/project/cmake-build-ubsan /Users/maxankurb/Desktop/project/cmake-build-ubsan /Users/maxankurb/Desktop/project/cmake-build-ubsan/CMakeFiles/project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project.dir/depend

