# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_SOURCE_DIR = "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild"

# Utility rule file for p6-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/p6-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/p6-populate.dir/progress.make

CMakeFiles/p6-populate: CMakeFiles/p6-populate-complete

CMakeFiles/p6-populate-complete: p6-populate-prefix/src/p6-populate-stamp/p6-populate-install
CMakeFiles/p6-populate-complete: p6-populate-prefix/src/p6-populate-stamp/p6-populate-mkdir
CMakeFiles/p6-populate-complete: p6-populate-prefix/src/p6-populate-stamp/p6-populate-download
CMakeFiles/p6-populate-complete: p6-populate-prefix/src/p6-populate-stamp/p6-populate-update
CMakeFiles/p6-populate-complete: p6-populate-prefix/src/p6-populate-stamp/p6-populate-patch
CMakeFiles/p6-populate-complete: p6-populate-prefix/src/p6-populate-stamp/p6-populate-configure
CMakeFiles/p6-populate-complete: p6-populate-prefix/src/p6-populate-stamp/p6-populate-build
CMakeFiles/p6-populate-complete: p6-populate-prefix/src/p6-populate-stamp/p6-populate-install
CMakeFiles/p6-populate-complete: p6-populate-prefix/src/p6-populate-stamp/p6-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Completed 'p6-populate'"
	/usr/local/bin/cmake -E make_directory "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/CMakeFiles"
	/usr/local/bin/cmake -E touch "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/CMakeFiles/p6-populate-complete"
	/usr/local/bin/cmake -E touch "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/src/p6-populate-stamp/p6-populate-done"

p6-populate-prefix/src/p6-populate-stamp/p6-populate-update:
.PHONY : p6-populate-prefix/src/p6-populate-stamp/p6-populate-update

p6-populate-prefix/src/p6-populate-stamp/p6-populate-build: p6-populate-prefix/src/p6-populate-stamp/p6-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'p6-populate'"
	cd "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-build" && /usr/local/bin/cmake -E echo_append
	cd "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-build" && /usr/local/bin/cmake -E touch "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/src/p6-populate-stamp/p6-populate-build"

p6-populate-prefix/src/p6-populate-stamp/p6-populate-configure: p6-populate-prefix/tmp/p6-populate-cfgcmd.txt
p6-populate-prefix/src/p6-populate-stamp/p6-populate-configure: p6-populate-prefix/src/p6-populate-stamp/p6-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'p6-populate'"
	cd "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-build" && /usr/local/bin/cmake -E echo_append
	cd "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-build" && /usr/local/bin/cmake -E touch "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/src/p6-populate-stamp/p6-populate-configure"

p6-populate-prefix/src/p6-populate-stamp/p6-populate-download: p6-populate-prefix/src/p6-populate-stamp/p6-populate-gitinfo.txt
p6-populate-prefix/src/p6-populate-stamp/p6-populate-download: p6-populate-prefix/src/p6-populate-stamp/p6-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'p6-populate'"
	cd "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps" && /usr/local/bin/cmake -P "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/tmp/p6-populate-gitclone.cmake"
	cd "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps" && /usr/local/bin/cmake -E touch "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/src/p6-populate-stamp/p6-populate-download"

p6-populate-prefix/src/p6-populate-stamp/p6-populate-install: p6-populate-prefix/src/p6-populate-stamp/p6-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'p6-populate'"
	cd "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-build" && /usr/local/bin/cmake -E echo_append
	cd "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-build" && /usr/local/bin/cmake -E touch "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/src/p6-populate-stamp/p6-populate-install"

p6-populate-prefix/src/p6-populate-stamp/p6-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'p6-populate'"
	/usr/local/bin/cmake -Dcfgdir= -P "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/tmp/p6-populate-mkdirs.cmake"
	/usr/local/bin/cmake -E touch "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/src/p6-populate-stamp/p6-populate-mkdir"

p6-populate-prefix/src/p6-populate-stamp/p6-populate-patch: p6-populate-prefix/src/p6-populate-stamp/p6-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'p6-populate'"
	/usr/local/bin/cmake -E echo_append
	/usr/local/bin/cmake -E touch "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/src/p6-populate-stamp/p6-populate-patch"

p6-populate-prefix/src/p6-populate-stamp/p6-populate-update:
.PHONY : p6-populate-prefix/src/p6-populate-stamp/p6-populate-update

p6-populate-prefix/src/p6-populate-stamp/p6-populate-test: p6-populate-prefix/src/p6-populate-stamp/p6-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'p6-populate'"
	cd "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-build" && /usr/local/bin/cmake -E echo_append
	cd "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-build" && /usr/local/bin/cmake -E touch "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/src/p6-populate-stamp/p6-populate-test"

p6-populate-prefix/src/p6-populate-stamp/p6-populate-update: p6-populate-prefix/src/p6-populate-stamp/p6-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'p6-populate'"
	cd "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-src" && /usr/local/bin/cmake -P "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/p6-populate-prefix/tmp/p6-populate-gitupdate.cmake"

p6-populate: CMakeFiles/p6-populate
p6-populate: CMakeFiles/p6-populate-complete
p6-populate: p6-populate-prefix/src/p6-populate-stamp/p6-populate-build
p6-populate: p6-populate-prefix/src/p6-populate-stamp/p6-populate-configure
p6-populate: p6-populate-prefix/src/p6-populate-stamp/p6-populate-download
p6-populate: p6-populate-prefix/src/p6-populate-stamp/p6-populate-install
p6-populate: p6-populate-prefix/src/p6-populate-stamp/p6-populate-mkdir
p6-populate: p6-populate-prefix/src/p6-populate-stamp/p6-populate-patch
p6-populate: p6-populate-prefix/src/p6-populate-stamp/p6-populate-test
p6-populate: p6-populate-prefix/src/p6-populate-stamp/p6-populate-update
p6-populate: CMakeFiles/p6-populate.dir/build.make
.PHONY : p6-populate

# Rule to build all files generated by this target.
CMakeFiles/p6-populate.dir/build: p6-populate
.PHONY : CMakeFiles/p6-populate.dir/build

CMakeFiles/p6-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p6-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p6-populate.dir/clean

CMakeFiles/p6-populate.dir/depend:
	cd "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild" "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild" "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild" "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild" "/home/rempoir/Documents/IMAC/Annee2/Semestre 2/Programmation/Simple-p6-Setup/build/_deps/p6-subbuild/CMakeFiles/p6-populate.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/p6-populate.dir/depend
