# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/MaxScale-develop/pcre2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/MaxScale-develop/pcre2

# Include any dependencies generated for this target.
include CMakeFiles/pcre2grep.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pcre2grep.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pcre2grep.dir/flags.make

CMakeFiles/pcre2grep.dir/src/pcre2grep.c.o: CMakeFiles/pcre2grep.dir/flags.make
CMakeFiles/pcre2grep.dir/src/pcre2grep.c.o: src/pcre2grep.c
	$(CMAKE_COMMAND) -E cmake_progress_report /root/MaxScale-develop/pcre2/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/pcre2grep.dir/src/pcre2grep.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pcre2grep.dir/src/pcre2grep.c.o   -c /root/MaxScale-develop/pcre2/src/pcre2grep.c

CMakeFiles/pcre2grep.dir/src/pcre2grep.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pcre2grep.dir/src/pcre2grep.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /root/MaxScale-develop/pcre2/src/pcre2grep.c > CMakeFiles/pcre2grep.dir/src/pcre2grep.c.i

CMakeFiles/pcre2grep.dir/src/pcre2grep.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pcre2grep.dir/src/pcre2grep.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /root/MaxScale-develop/pcre2/src/pcre2grep.c -o CMakeFiles/pcre2grep.dir/src/pcre2grep.c.s

CMakeFiles/pcre2grep.dir/src/pcre2grep.c.o.requires:
.PHONY : CMakeFiles/pcre2grep.dir/src/pcre2grep.c.o.requires

CMakeFiles/pcre2grep.dir/src/pcre2grep.c.o.provides: CMakeFiles/pcre2grep.dir/src/pcre2grep.c.o.requires
	$(MAKE) -f CMakeFiles/pcre2grep.dir/build.make CMakeFiles/pcre2grep.dir/src/pcre2grep.c.o.provides.build
.PHONY : CMakeFiles/pcre2grep.dir/src/pcre2grep.c.o.provides

CMakeFiles/pcre2grep.dir/src/pcre2grep.c.o.provides.build: CMakeFiles/pcre2grep.dir/src/pcre2grep.c.o

# Object files for target pcre2grep
pcre2grep_OBJECTS = \
"CMakeFiles/pcre2grep.dir/src/pcre2grep.c.o"

# External object files for target pcre2grep
pcre2grep_EXTERNAL_OBJECTS =

pcre2grep: CMakeFiles/pcre2grep.dir/src/pcre2grep.c.o
pcre2grep: CMakeFiles/pcre2grep.dir/build.make
pcre2grep: libpcre2posix.a
pcre2grep: /usr/lib64/libz.so
pcre2grep: /usr/lib64/libbz2.so
pcre2grep: libpcre2-8.a
pcre2grep: CMakeFiles/pcre2grep.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable pcre2grep"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pcre2grep.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pcre2grep.dir/build: pcre2grep
.PHONY : CMakeFiles/pcre2grep.dir/build

CMakeFiles/pcre2grep.dir/requires: CMakeFiles/pcre2grep.dir/src/pcre2grep.c.o.requires
.PHONY : CMakeFiles/pcre2grep.dir/requires

CMakeFiles/pcre2grep.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pcre2grep.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pcre2grep.dir/clean

CMakeFiles/pcre2grep.dir/depend:
	cd /root/MaxScale-develop/pcre2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/MaxScale-develop/pcre2 /root/MaxScale-develop/pcre2 /root/MaxScale-develop/pcre2 /root/MaxScale-develop/pcre2 /root/MaxScale-develop/pcre2/CMakeFiles/pcre2grep.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pcre2grep.dir/depend
