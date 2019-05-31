# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/pi/apriltag/tags/v3.0.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/apriltag/tags/v3.0.0

# Include any dependencies generated for this target.
include CMakeFiles/opencv_demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opencv_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opencv_demo.dir/flags.make

CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o: CMakeFiles/opencv_demo.dir/flags.make
CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o: example/opencv_demo.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/apriltag/tags/v3.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o -c /home/pi/apriltag/tags/v3.0.0/example/opencv_demo.cc

CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/apriltag/tags/v3.0.0/example/opencv_demo.cc > CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.i

CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/apriltag/tags/v3.0.0/example/opencv_demo.cc -o CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.s

CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o.requires:

.PHONY : CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o.requires

CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o.provides: CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o.requires
	$(MAKE) -f CMakeFiles/opencv_demo.dir/build.make CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o.provides.build
.PHONY : CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o.provides

CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o.provides.build: CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o


# Object files for target opencv_demo
opencv_demo_OBJECTS = \
"CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o"

# External object files for target opencv_demo
opencv_demo_EXTERNAL_OBJECTS =

opencv_demo: CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o
opencv_demo: CMakeFiles/opencv_demo.dir/build.make
opencv_demo: lib/libapriltag.so.3.0.0
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_videostab.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_ts.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_superres.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_stitching.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_ocl.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_gpu.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_contrib.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_photo.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_legacy.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_video.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_objdetect.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_ml.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_calib3d.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_features2d.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_highgui.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_imgproc.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_flann.so.2.4.9
opencv_demo: /usr/lib/arm-linux-gnueabihf/libopencv_core.so.2.4.9
opencv_demo: CMakeFiles/opencv_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/apriltag/tags/v3.0.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable opencv_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opencv_demo.dir/build: opencv_demo

.PHONY : CMakeFiles/opencv_demo.dir/build

CMakeFiles/opencv_demo.dir/requires: CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o.requires

.PHONY : CMakeFiles/opencv_demo.dir/requires

CMakeFiles/opencv_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opencv_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opencv_demo.dir/clean

CMakeFiles/opencv_demo.dir/depend:
	cd /home/pi/apriltag/tags/v3.0.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/apriltag/tags/v3.0.0 /home/pi/apriltag/tags/v3.0.0 /home/pi/apriltag/tags/v3.0.0 /home/pi/apriltag/tags/v3.0.0 /home/pi/apriltag/tags/v3.0.0/CMakeFiles/opencv_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opencv_demo.dir/depend

