# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/kaze/fje_re

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kaze/fje_re/build

# Include any dependencies generated for this target.
include CMakeFiles/TreePrinter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TreePrinter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TreePrinter.dir/flags.make

CMakeFiles/TreePrinter.dir/src/main.cpp.o: CMakeFiles/TreePrinter.dir/flags.make
CMakeFiles/TreePrinter.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kaze/fje_re/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TreePrinter.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TreePrinter.dir/src/main.cpp.o -c /home/kaze/fje_re/src/main.cpp

CMakeFiles/TreePrinter.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TreePrinter.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kaze/fje_re/src/main.cpp > CMakeFiles/TreePrinter.dir/src/main.cpp.i

CMakeFiles/TreePrinter.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TreePrinter.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kaze/fje_re/src/main.cpp -o CMakeFiles/TreePrinter.dir/src/main.cpp.s

CMakeFiles/TreePrinter.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/TreePrinter.dir/src/main.cpp.o.requires

CMakeFiles/TreePrinter.dir/src/main.cpp.o.provides: CMakeFiles/TreePrinter.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TreePrinter.dir/build.make CMakeFiles/TreePrinter.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/TreePrinter.dir/src/main.cpp.o.provides

CMakeFiles/TreePrinter.dir/src/main.cpp.o.provides.build: CMakeFiles/TreePrinter.dir/src/main.cpp.o


CMakeFiles/TreePrinter.dir/src/Component.cpp.o: CMakeFiles/TreePrinter.dir/flags.make
CMakeFiles/TreePrinter.dir/src/Component.cpp.o: ../src/Component.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kaze/fje_re/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TreePrinter.dir/src/Component.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TreePrinter.dir/src/Component.cpp.o -c /home/kaze/fje_re/src/Component.cpp

CMakeFiles/TreePrinter.dir/src/Component.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TreePrinter.dir/src/Component.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kaze/fje_re/src/Component.cpp > CMakeFiles/TreePrinter.dir/src/Component.cpp.i

CMakeFiles/TreePrinter.dir/src/Component.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TreePrinter.dir/src/Component.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kaze/fje_re/src/Component.cpp -o CMakeFiles/TreePrinter.dir/src/Component.cpp.s

CMakeFiles/TreePrinter.dir/src/Component.cpp.o.requires:

.PHONY : CMakeFiles/TreePrinter.dir/src/Component.cpp.o.requires

CMakeFiles/TreePrinter.dir/src/Component.cpp.o.provides: CMakeFiles/TreePrinter.dir/src/Component.cpp.o.requires
	$(MAKE) -f CMakeFiles/TreePrinter.dir/build.make CMakeFiles/TreePrinter.dir/src/Component.cpp.o.provides.build
.PHONY : CMakeFiles/TreePrinter.dir/src/Component.cpp.o.provides

CMakeFiles/TreePrinter.dir/src/Component.cpp.o.provides.build: CMakeFiles/TreePrinter.dir/src/Component.cpp.o


CMakeFiles/TreePrinter.dir/src/Iterator.cpp.o: CMakeFiles/TreePrinter.dir/flags.make
CMakeFiles/TreePrinter.dir/src/Iterator.cpp.o: ../src/Iterator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kaze/fje_re/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TreePrinter.dir/src/Iterator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TreePrinter.dir/src/Iterator.cpp.o -c /home/kaze/fje_re/src/Iterator.cpp

CMakeFiles/TreePrinter.dir/src/Iterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TreePrinter.dir/src/Iterator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kaze/fje_re/src/Iterator.cpp > CMakeFiles/TreePrinter.dir/src/Iterator.cpp.i

CMakeFiles/TreePrinter.dir/src/Iterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TreePrinter.dir/src/Iterator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kaze/fje_re/src/Iterator.cpp -o CMakeFiles/TreePrinter.dir/src/Iterator.cpp.s

CMakeFiles/TreePrinter.dir/src/Iterator.cpp.o.requires:

.PHONY : CMakeFiles/TreePrinter.dir/src/Iterator.cpp.o.requires

CMakeFiles/TreePrinter.dir/src/Iterator.cpp.o.provides: CMakeFiles/TreePrinter.dir/src/Iterator.cpp.o.requires
	$(MAKE) -f CMakeFiles/TreePrinter.dir/build.make CMakeFiles/TreePrinter.dir/src/Iterator.cpp.o.provides.build
.PHONY : CMakeFiles/TreePrinter.dir/src/Iterator.cpp.o.provides

CMakeFiles/TreePrinter.dir/src/Iterator.cpp.o.provides.build: CMakeFiles/TreePrinter.dir/src/Iterator.cpp.o


CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.o: CMakeFiles/TreePrinter.dir/flags.make
CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.o: ../src/PrintStrategy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kaze/fje_re/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.o -c /home/kaze/fje_re/src/PrintStrategy.cpp

CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kaze/fje_re/src/PrintStrategy.cpp > CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.i

CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kaze/fje_re/src/PrintStrategy.cpp -o CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.s

CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.o.requires:

.PHONY : CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.o.requires

CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.o.provides: CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.o.requires
	$(MAKE) -f CMakeFiles/TreePrinter.dir/build.make CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.o.provides.build
.PHONY : CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.o.provides

CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.o.provides.build: CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.o


CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.o: CMakeFiles/TreePrinter.dir/flags.make
CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.o: ../src/jsonToTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kaze/fje_re/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.o -c /home/kaze/fje_re/src/jsonToTree.cpp

CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kaze/fje_re/src/jsonToTree.cpp > CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.i

CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kaze/fje_re/src/jsonToTree.cpp -o CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.s

CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.o.requires:

.PHONY : CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.o.requires

CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.o.provides: CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.o.requires
	$(MAKE) -f CMakeFiles/TreePrinter.dir/build.make CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.o.provides.build
.PHONY : CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.o.provides

CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.o.provides.build: CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.o


CMakeFiles/TreePrinter.dir/src/Printer.cpp.o: CMakeFiles/TreePrinter.dir/flags.make
CMakeFiles/TreePrinter.dir/src/Printer.cpp.o: ../src/Printer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kaze/fje_re/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TreePrinter.dir/src/Printer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TreePrinter.dir/src/Printer.cpp.o -c /home/kaze/fje_re/src/Printer.cpp

CMakeFiles/TreePrinter.dir/src/Printer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TreePrinter.dir/src/Printer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kaze/fje_re/src/Printer.cpp > CMakeFiles/TreePrinter.dir/src/Printer.cpp.i

CMakeFiles/TreePrinter.dir/src/Printer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TreePrinter.dir/src/Printer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kaze/fje_re/src/Printer.cpp -o CMakeFiles/TreePrinter.dir/src/Printer.cpp.s

CMakeFiles/TreePrinter.dir/src/Printer.cpp.o.requires:

.PHONY : CMakeFiles/TreePrinter.dir/src/Printer.cpp.o.requires

CMakeFiles/TreePrinter.dir/src/Printer.cpp.o.provides: CMakeFiles/TreePrinter.dir/src/Printer.cpp.o.requires
	$(MAKE) -f CMakeFiles/TreePrinter.dir/build.make CMakeFiles/TreePrinter.dir/src/Printer.cpp.o.provides.build
.PHONY : CMakeFiles/TreePrinter.dir/src/Printer.cpp.o.provides

CMakeFiles/TreePrinter.dir/src/Printer.cpp.o.provides.build: CMakeFiles/TreePrinter.dir/src/Printer.cpp.o


# Object files for target TreePrinter
TreePrinter_OBJECTS = \
"CMakeFiles/TreePrinter.dir/src/main.cpp.o" \
"CMakeFiles/TreePrinter.dir/src/Component.cpp.o" \
"CMakeFiles/TreePrinter.dir/src/Iterator.cpp.o" \
"CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.o" \
"CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.o" \
"CMakeFiles/TreePrinter.dir/src/Printer.cpp.o"

# External object files for target TreePrinter
TreePrinter_EXTERNAL_OBJECTS =

TreePrinter: CMakeFiles/TreePrinter.dir/src/main.cpp.o
TreePrinter: CMakeFiles/TreePrinter.dir/src/Component.cpp.o
TreePrinter: CMakeFiles/TreePrinter.dir/src/Iterator.cpp.o
TreePrinter: CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.o
TreePrinter: CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.o
TreePrinter: CMakeFiles/TreePrinter.dir/src/Printer.cpp.o
TreePrinter: CMakeFiles/TreePrinter.dir/build.make
TreePrinter: CMakeFiles/TreePrinter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kaze/fje_re/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable TreePrinter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TreePrinter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TreePrinter.dir/build: TreePrinter

.PHONY : CMakeFiles/TreePrinter.dir/build

CMakeFiles/TreePrinter.dir/requires: CMakeFiles/TreePrinter.dir/src/main.cpp.o.requires
CMakeFiles/TreePrinter.dir/requires: CMakeFiles/TreePrinter.dir/src/Component.cpp.o.requires
CMakeFiles/TreePrinter.dir/requires: CMakeFiles/TreePrinter.dir/src/Iterator.cpp.o.requires
CMakeFiles/TreePrinter.dir/requires: CMakeFiles/TreePrinter.dir/src/PrintStrategy.cpp.o.requires
CMakeFiles/TreePrinter.dir/requires: CMakeFiles/TreePrinter.dir/src/jsonToTree.cpp.o.requires
CMakeFiles/TreePrinter.dir/requires: CMakeFiles/TreePrinter.dir/src/Printer.cpp.o.requires

.PHONY : CMakeFiles/TreePrinter.dir/requires

CMakeFiles/TreePrinter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TreePrinter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TreePrinter.dir/clean

CMakeFiles/TreePrinter.dir/depend:
	cd /home/kaze/fje_re/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kaze/fje_re /home/kaze/fje_re /home/kaze/fje_re/build /home/kaze/fje_re/build /home/kaze/fje_re/build/CMakeFiles/TreePrinter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TreePrinter.dir/depend

