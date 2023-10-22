cmake_minimum_required(VERSION 3.10)

# Set the project name
project(WAP-CPP-System-Tools)

add_library(FolderScanner STATIC lib/FolderScanner/main.cpp) # Define a static library
target_include_directories(FolderScanner PUBLIC lib/FolderScanner) # Include directories for the library

add_library(SystemUser STATIC lib/SystemUser/main.cpp) # Define a static library
target_include_directories(SystemUser PUBLIC lib/SystemUser) # Include directories for the library

add_library(Random STATIC lib/Random/main.cpp) # Define a static library
target_include_directories(Random PUBLIC lib/Random) # Include directories for the library

add_executable(run main.cpp)

# Link the library with the executable
target_link_libraries(run PRIVATE FolderScanner)
target_link_libraries(run PRIVATE SystemUser)
target_link_libraries(run PRIVATE Random)

add_executable(start starter.cpp)

set_target_properties(run PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/pkg
)
