# WAP C++ System Tools

Learning how to access directories, return file & folder lists, read files, save files, run sub-programs, use C++ headers, etc.

## INSTRUCTIONS

# Create a starter executable:

This only needs to be done once. This will automatically request admin permissions for the run.exe, to support all operations.

g++ starter.cpp -o dist/alpha-0.0.1/start.exe

*NOTE: This is not needed if you are using the Packager.exe for a version distribution (this command is ran automatically from Packager)


# Compile the Resource Script

Run the following command to compile the resource script into a COFF object file:

windres config/sysAccess.rc -O coff -o config/sysAccess.res

*NOTE: This is not needed if you are using the Packager.exe for a version distribution (this command is ran automatically from Packager)


# Compile the program:

g++ -std=c++17 main.cpp lib/FolderScanner/main.cpp lib/Random/main.cpp lib/SystemUser/main.cpp config/sysAccess.res -o dist/alpha-0.0.4/pkg/run.exe

The version of gcc must be 8+ to use filesystem dependencies. I am using 'gcc.exe (x86_64-posix-seh-rev0, Built by MinGW-Builds project) 13.2.0' at this time.

*NOTE: This is not needed if you are using the Packager.exe for a version distribution (this command is ran automatically from Packager)


# Notes

Run start.exe from distribution folders in /dist/, or compile from source manually with commands above, or using dev/Packager/Packager.exe. Source is provided for both starter & packager programs alongside main source for WAP C++ System Tools.
