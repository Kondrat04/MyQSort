# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\kondr\CLionProjects\Other\QsortModified

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\kondr\CLionProjects\Other\QsortModified\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/QsortModified.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/QsortModified.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QsortModified.dir/flags.make

CMakeFiles/QsortModified.dir/main.cpp.obj: CMakeFiles/QsortModified.dir/flags.make
CMakeFiles/QsortModified.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kondr\CLionProjects\Other\QsortModified\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/QsortModified.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\QsortModified.dir\main.cpp.obj -c C:\Users\kondr\CLionProjects\Other\QsortModified\main.cpp

CMakeFiles/QsortModified.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QsortModified.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kondr\CLionProjects\Other\QsortModified\main.cpp > CMakeFiles\QsortModified.dir\main.cpp.i

CMakeFiles/QsortModified.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QsortModified.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kondr\CLionProjects\Other\QsortModified\main.cpp -o CMakeFiles\QsortModified.dir\main.cpp.s

CMakeFiles/QsortModified.dir/Thread.cpp.obj: CMakeFiles/QsortModified.dir/flags.make
CMakeFiles/QsortModified.dir/Thread.cpp.obj: ../Thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kondr\CLionProjects\Other\QsortModified\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/QsortModified.dir/Thread.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\QsortModified.dir\Thread.cpp.obj -c C:\Users\kondr\CLionProjects\Other\QsortModified\Thread.cpp

CMakeFiles/QsortModified.dir/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QsortModified.dir/Thread.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kondr\CLionProjects\Other\QsortModified\Thread.cpp > CMakeFiles\QsortModified.dir\Thread.cpp.i

CMakeFiles/QsortModified.dir/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QsortModified.dir/Thread.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kondr\CLionProjects\Other\QsortModified\Thread.cpp -o CMakeFiles\QsortModified.dir\Thread.cpp.s

# Object files for target QsortModified
QsortModified_OBJECTS = \
"CMakeFiles/QsortModified.dir/main.cpp.obj" \
"CMakeFiles/QsortModified.dir/Thread.cpp.obj"

# External object files for target QsortModified
QsortModified_EXTERNAL_OBJECTS =

QsortModified.exe: CMakeFiles/QsortModified.dir/main.cpp.obj
QsortModified.exe: CMakeFiles/QsortModified.dir/Thread.cpp.obj
QsortModified.exe: CMakeFiles/QsortModified.dir/build.make
QsortModified.exe: CMakeFiles/QsortModified.dir/linklibs.rsp
QsortModified.exe: CMakeFiles/QsortModified.dir/objects1.rsp
QsortModified.exe: CMakeFiles/QsortModified.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\kondr\CLionProjects\Other\QsortModified\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable QsortModified.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\QsortModified.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QsortModified.dir/build: QsortModified.exe

.PHONY : CMakeFiles/QsortModified.dir/build

CMakeFiles/QsortModified.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\QsortModified.dir\cmake_clean.cmake
.PHONY : CMakeFiles/QsortModified.dir/clean

CMakeFiles/QsortModified.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\kondr\CLionProjects\Other\QsortModified C:\Users\kondr\CLionProjects\Other\QsortModified C:\Users\kondr\CLionProjects\Other\QsortModified\cmake-build-debug C:\Users\kondr\CLionProjects\Other\QsortModified\cmake-build-debug C:\Users\kondr\CLionProjects\Other\QsortModified\cmake-build-debug\CMakeFiles\QsortModified.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QsortModified.dir/depend

