# Computer Graphics – Ray Tracing

> **To get started:** Clone this repository and its submodule using
> 
>     git clone --recursive https://github.com/alliez/CSC317-A9.git


Prerequisite installation
On all platforms, we will assume you have installed cmake and a modern c++ compiler on Mac OS X¹, Linux², or Windows³.

We also assume that you have cloned this repository using the --recursive flag (if not then issue git submodule update --init --recursive).

The README.md file will describe the background, contents and tasks of the assignment.

The CMakeLists.txt file setups up the cmake build routine for this assignment.

The main.cpp file will include the headers in the include/ directory and link to the functions compiled in the src/ directory. This file contains the main function that is executed when the program is run from the command line.

The include/ directory contains one file for each function that you will implement as part of the assignment. Do not change these files.

The src/ directory contains empty implementations of the functions specified in the include/ directory. This is where you will implement the parts of the assignment.

The data/ directory contains sample input data for your program. Keep in mind you should create your own test data to verify your program as you write it. It is not necessarily sufficient that your program only works on the given sample data.

Compilation
This and all following assignments will follow a typical cmake/make build routine. Starting in this directory, issue:

mkdir build
cd build
cmake ..
If you are using Mac or Linux, then issue:

make
If you are using Windows, then running cmake .. should have created a Visual Studio solution file called raster.sln that you can open and build from there. Building the raster project will generate an .exe file.

Execution
Once built, you can execute the assignment from inside the build(where the executable is)/ using

./raytracing


## Background
A creative bonus assginment for csc317;
Because of the limitation of file size submission on Markus, source.zip include all my works on codes. 
A full source including lib (Eigen, etc.) is in the GitHub link below: 
https://github.com/alliez/CSC317-A9.git

My work of this image competition assignment is based on our HW3 ray casting. 
In this assignment I use this algorithm to create different objects which overall combined to be a 3D snowman, and beautiful wallpaper.

> ### HW2 Solution
> If you don't trust the solutions to the files from HW2:

>     src/Plane.cpp
>     src/Sphere.cpp
>     src/Triangle.cpp
>     src/TriangleSoup.cpp
>     src/first_hit.cpp
>     src/viewing_ray.cpp
>     src/write_ppm.cpp
>
> You can use precompiled binaries (provided for linux, mac, and windows) using a
> the cmake command:
>
>     mkdir build
>     cd build
>     cmake -DCMAKE_BUILD_TYPE=Debug -DHW2LIB_DIR=../lib/debug/linux/ ..
>     make
>
> This will use the library at `../lib/debug/linux/libhw2.a` instead of
> compiling the above files in `src/`.
>

------------------------------------------------------------------------

> You can dramatic improve the performance simply by enabling [compiler
> optimization](https://en.wikipedia.org/wiki/Optimizing_compiler): 
>
> ```
> mkdir build-release
> cd build-release
> cmake ../ -DCMAKE_BUILD_TYPE=Release
> make
> ```
