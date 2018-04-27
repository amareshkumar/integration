Project: integration
This is a sole purpose project for self-practices for some C++ concepts and algo/ds implementations.

Generating build script
=======================

Create a subdirectory called "build" and change to it.
	mkdir build && cd build

On Windows create a Visual Studio solution by executing:
    
	cmake -G "Visual Studio 14 2015 Win64" ..

On Linux/MacOS create a makefile by executing:

    cmake -DCMAKE_BUILD_TYPE=Debug ..

or

    cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..

Building
===================

You can build the Visual Studio solution using the following from the "build"
directory:
	
for library:
	
    devenv integrated.sln /build Debug
	
client application:

	devenv integrationClient.sln /build Debug
or

    devenv integrated.sln /build RelWithDebInfo

The output will be in the build\Debug or build\RelWithDebInfo subdirectory.

You can build on macOS/Linux using make:

    make

The output will be in the "bin" subdirectory.

IntegrationClient (Linux)
=======================
Please make sure the .a file is generated before you generate build files for client. Steps:

to build: cd client

	mkdir build && cd build 
	cmake -DCMAKE_BUILD_TYPE=Debug ..
	make

to run: cd bin
./integrationClient