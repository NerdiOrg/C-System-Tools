#include <iostream>
#include <fstream>
#include <string>
#include "../../lib/FolderScanner/main.h"

// run with g++ packager.cpp -o Packager.exe

int main() {
    // Welcome message
    std::cout << "WAP C++ Hacker Tools Packager" << std::endl << "===================" << std::endl;

    while(true){
        std::cout << std::endl << "Type in a version number. Please note that this will overwrite all files/folders if a previous distribution exists." << std::endl << "Your files will be compiled in /dist/0.0.*/ folder, where the sub-folder of /dist is your version number input." << std::endl;
        std::string versionNumber;
        std::string distPath;
        while(true){
            std::cout << "What is the new version number / distribution name? ( e.g. enter 0.0.4 for dist/0.0.4/ )" << std::endl;
            std::getline(std::cin, versionNumber);
            distPath = "../../dist/" + versionNumber + "/";
            std::cout << "Target distribution path: " << distPath << std::endl;
            std::cout << "Continue?" << std::endl << "1. Continue with distribution" << std::endl << "2. Restart" << std::endl;
            std::string continueAnswer;
            std::getline(std::cin, continueAnswer);
            if(continueAnswer == "1"){
                break;
            }
        }

        

        if(std::filesystem::exists(distPath)){
            std::cout << "Directory already exists. Overwriting..." << std::endl;
            try {
                std::filesystem::remove_all(distPath);
                std::cout << "Removed existing distribution completely." << std::endl;
            } catch(std::filesystem::filesystem_error& e) {
                std::cerr << "Filesystem error: " << e.what() << std::endl;
                std::cout << "Please note that we will continue with packaging, but some files or folders from existing distribution version could not be deleted." << std::endl;
            }
        }

        try {
            if(!std::filesystem::exists(distPath)){
                std::filesystem::create_directories(distPath);
                std::cout << "Successfully created distribution path: " << distPath << std::endl;
            } else {
                std::cout << "Using existing distribution path: " << distPath << std::endl;
            }
            if(!std::filesystem::exists(distPath + "pkg")){
                std::filesystem::create_directories(distPath + "pkg");
                std::cout << "Successfully created distribution pkg path: " << distPath + "pkg" << std::endl;
            } else {
                std::cout << "Using existing distribution pkg path: " << distPath + "pkg" << std::endl;
            }
        } catch(std::filesystem::filesystem_error& e){
            std::cerr << "Filesystem error: " << e.what() << std::endl;
            std::cout << "We could not create necessary distribution files. Please check your permissions and try again." << std::endl;
            break;
        }

        std::string command_createResObj = "windres ../../config/sysAccess.rc -O coff -o ../../config/sysAccess.res";
        std::cout << "Creating res object:" << std::endl << command_createResObj << std::endl;
        system(command_createResObj.c_str());

        std::string command_compileMain = "g++ -std=c++17 ../../main.cpp ../../lib/FolderScanner/main.cpp ../../lib/Random/main.cpp ../../lib/SystemUser/main.cpp ../../config/sysAccess.res -o " + distPath + "pkg/run.exe";
        std::cout << "Compiling WAP C++ Hacker Tools (pkg/run.exe)" << std::endl;
        system(command_compileMain.c_str());

        std::string command_createStarter = "g++ ../../starter.cpp -o " + distPath + "start.exe";
        std::cout << "Compiling WAP C++ Hacker Tools Starter (start.exe)" << std::endl;
        system(command_createStarter.c_str());

        std::string command_moveReadme = "move ../../readme.md.template " + distPath + "readme.md";
        std::cout << "Adding readme.md to distribution" << std::endl;
        system(command_moveReadme.c_str());
    }

    std::cout << "Packaging is complete." << std::endl;
    return 0;
}
