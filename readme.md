## SYSTEMACCESS

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

Alpha 0.0.5 will include a sub-program for developers that copies project files/folders and adds to the dist folder under 'source' for proper version history.

Alpha 0.0.4 has a critical upgrade to use a while(true) loop for the main menu & all sub-menus, to allow continuous use of the program. Up until now the program has quit after 1 option is completed. Unfortunately during this process, alpha 0.0.3b was overwritten by 0.0.4's first distribution release locally.

Alpha 0.0.3b and 0.0.3c introduce new formats for sub-prompt questions to combine options (from main menu), all \n usage is replaced with std::endl, and the random seed is generated at start instead of inside the random function itself which was causing the same random string to be provided each time.