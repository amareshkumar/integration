Project: integration
This is a sole purpose project for practices for some C++ concepts and self-programming practices.

Generating build script
=======================

Create a subdirectory called "build" and change to it.

On Windows create a Visual Studio solution by executing:
    
	cmake -G "Visual Studio 14 2015 Win64" ..

On macOS/Linux create a makefile by executing:

    cmake -DCMAKE_BUILD_TYPE=Debug ..

or

    cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..

Building
===================

You can build the Visual Studio solution using the following from the "build"
directory:

    devenv integrated.sln /build Debug

or

    devenv integrated.sln /build RelWithDebInfo

The output will be in the build\Debug or build\RelWithDebInfo subdirectory.

You can build on macOS/Linux using make:

    make

The output will be the "build" subdirectory.