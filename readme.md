# WAP C++ System Tools

A collection of mini features to help me better understand std:: , Windows, and C++ development. If this is useful to others, that's great, but I am only releasing this software for educational purposes as I teach myself C++.

Command Line Menu: 

1. Save file to C://wap.md
2. Read C://wap.md file
3. System Users
     1. View User Folders
     2. Get Current Username
     3. Get Current User Directory Path
4. Pictures
     1. List all files in user Pictures folder.
     2. Delete all files in user Pictures folder, recursively.
5. Confusing Filenames
     1. All Desktop Files
     2. All Desktop Files, Subfolders (Recursive)


## Release Executables
Clicking start.exe will launch a prompt to request administrator permissions for pkg/run.exe

The run.exe is built from the primary main.cpp file in root folder.

The start.exe is built from starter.cpp file in root folder.

The program has options that will create, read, edit, or delete files and folders. No operation is designed to be malicious, but using the program can cause data loss. This is my attempt at learning cool C++ functionality from command line prompts and as such, some test folders are used instead at this time, to prevent deletion of actual system files.


## Compile with CMake

The CMakeLists.txt file has instructions for 'pkg/run.exe' (program itself, which only works fully with Admin permissions) and 'start.exe' which triggers the opening of pkg/run.exe with 'runas' admin permission request.

*NOTE: This current release's CMakeLists file does not use the res object, so the program has no manifest or logo/icon attached. 


## Compile the Resource Script

Run the following command from project root dir to compile the resource script into a COFF object file:

windres config/sysAccess.rc -O coff -o config/sysAccess.res

*NOTE: This is not needed if you are using the Packager.exe for a version distribution (this command is ran automatically from Packager)



## Compile pkg/run.exe (main program)

g++ -std=c++17 main.cpp lib/FolderScanner/main.cpp lib/Random/main.cpp lib/SystemUser/main.cpp config/sysAccess.res -o dist/alpha-0.0.4/pkg/run.exe

The version of gcc must be 8+ to use filesystem dependencies. I am using 'gcc.exe (x86_64-posix-seh-rev0, Built by MinGW-Builds project) 13.2.0' at this time.

*NOTE: This is not needed if you are using the Packager.exe for a version distribution (this command is ran automatically from Packager). If you don't use start.exe, you must run pkg/run.exe as Administrator to use full features.



## Compile start.exe

This only needs to be done once. This will automatically request admin permissions for the run.exe, to support all operations.

g++ starter.cpp -o dist/alpha-0.0.1/start.exe

*NOTE: This is not needed if you are using the Packager.exe for a version distribution (this command is ran automatically from Packager)



## Compile dev/Packager/Packager.exe

This is only here for an example of a C++ executable that allows distributions of WAP C++ System Tools to be easily packaged into a new version. It is not needed if you are using manual commands above.

g++ dev/Packager/packager.cpp -o dev/Packager/Packager.exe

*NOTE: This is not needed if you are compiling manually. Simply open dev/Packager/Packager.exe and follow command prompt instructions to create a new compiled version in /dist/ folder.



# Notes

Run start.exe from distribution folders in /dist/, or compile from source manually with commands above, or using dev/Packager/Packager.exe. Source is provided for both starter & packager programs alongside main source for WAP C++ System Tools.
