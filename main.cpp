#include <iostream>
#include <fstream>
#include <string>
#include "lib/FolderScanner/main.h"
#include "lib/Random/main.h"
#include "lib/SystemUser/main.h"

int main() {
    // Welcome message
    std::cout << "WAP C++ Hack Tools (Alpha v0.0.4)" << std::endl << "===================" << std::endl;

    randomSeed(); // call random seed to initiate random number generator

    while(true){
        std::cout << std::endl << "What would you like to do?"  << std::endl << "1. Save in C:/"  << std::endl << "2. Read file in C:/" << std::endl << "3. System Users"  << std::endl <<  "4. Pictures"  << std::endl <<  "5. Confusing Filenames"  << std::endl << "6. Exit" << std::endl << "Type # [1-6] and press Enter to continue..." << std::endl;
        std::string mainPromptAnswer; // Used for a prompt
        std::getline(std::cin, mainPromptAnswer);

        std::string rootFilePath = "C:\\";
        std::string usersFilePath = "C:\\Users\\";
        std::string wapFilePath = "C:\\wap.md";
        std::string userPicturesPath = getEnvUsernameDirectory() + "Pictures";
        std::ifstream file;

        if(mainPromptAnswer == "1"){ // save md file in root 
            std::cout << std::endl << "Saving file..." << std::endl << std::endl;
            std::ofstream file(wapFilePath);
            if (!file.is_open()) {
                std::cerr << "Failed to open the file in C:/" << std::endl;
                return 1;
            }
            file << "Hello, from WAP.";
        } else if(mainPromptAnswer == "2"){ // read md file from Root
            std::cout << std::endl << "Opening file..." << std::endl << std::endl;
            file.open(wapFilePath);
            if (!file.is_open()) {
                std::cerr << "Failed to open the file." << std::endl;
                return 1;
            }
            // Read and display the file content
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }

            // Close the file
            file.close();
        } else if(mainPromptAnswer == "3"){ // system users 
            while(true){
                std::string subPromptAnswer3;
                std::cout << std::endl << "===================" << std::endl <<  "System Users" << std::endl << "1. View User Folders." << std::endl << "2. Get Current Username" << std::endl << "3. Get Current User Directory Path" << std::endl << "4. Return to Main Menu" << std::endl << "Type # [1-4] and press Enter to continue..." << std::endl;
                std::getline(std::cin, subPromptAnswer3);
                if(subPromptAnswer3 == "1"){
                    std::cout << std::endl << "List of User Folders:" << std::endl << std::endl;
                    std::vector<std::filesystem::path> folders = getUserDirectories();
                    for (const auto& folder : folders) {
                        std::cout << folder << std::endl;
                    }
                } else if(subPromptAnswer3 == "2"){
                    std::cout << std::endl << "Current Username: " << getEnvUsername() << std::endl;
                } else if(subPromptAnswer3 == "3"){
                    std::cout << std::endl << "Current User Directory: " << getEnvUsernameDirectory() << std::endl;
                } else if (subPromptAnswer3 == "4") {
                    break;  // Exit to the main menu
                } else {
                    std::cout << std::endl << "Invalid option selected." << std::endl;
                }
                
            }
        } else if(mainPromptAnswer == "4"){
            while(true){
                std::cout << "===================" << std::endl << "Pictures" << std::endl;
                std::string subPromptAnswer4;
                std::cout << std::endl << "Please select from the following options. Type [1-3] and then press Enter to continue..." << std::endl << "1. Get list of current user Pictures." << std::endl << "2. Delete current user Pictures." << std::endl << "3. Return to main menu" << std::endl;
                std::getline(std::cin, subPromptAnswer4);
                if(subPromptAnswer4 == "1"){
                    std::cout << std::endl << "List all user's pictures:" << std::endl;
                    const std::vector<std::filesystem::path> files = fsGetFilesRecursive(userPicturesPath);
                    for(const auto& file : files){
                        std::cout << file << std::endl;
                    }
                } else if(subPromptAnswer4 == "2"){
                    std::cout << std::endl << "===================" << std::endl << "Deleting all current user's pictures." << std::endl;
                    std::vector<std::filesystem::path> folders = fsGetFoldersRecursive(userPicturesPath); // get all subfolders & delete those first
                    for (const auto& folder : folders) {
                        try {
                            // Try to remove the folder and its contents
                            std::filesystem::remove_all(folder);
                            std::cout << "Successfully removed sub-directory and all included files/folders: " << folder << std::endl;
                        } catch (const std::filesystem::filesystem_error& e) {
                            std::cerr << "Filesystem error: " << e.what() << std::endl;
                            // std::cerr << "Code: " << e.code() << std::endl;
                            // std::cerr << "Additional Info: " << e.code().message() << std::endl;
                        } catch (const std::exception& e) {
                            std::cerr << "An exception occurred: " << e.what() << std::endl;;
                        } catch (...) {
                            std::cerr << "An unknown exception occurred." << std::endl;
                        }
                    }
                    std::vector<std::filesystem::path> files = fsGetFilesRecursive(userPicturesPath); // get all files & delete those next 
                    for(const auto& file : files){
                        if(std::filesystem::remove(file)){
                            std::cout << "Successfully removed file " << file << std::endl;
                        } else {
                            std::cout << "ERROR: Could not remove file " << file << std::endl;
                        }
                    }
                } else if(subPromptAnswer4 == "3"){
                    break;  // Exit to the main menu
                } else {
                    std::cout << "Invalid option selected." << std::endl << std::endl;
                } 
            }
        } else if(mainPromptAnswer == "5"){ // scramble filenames on Desktop
            while(true){
                std::cout << "===================" << std::endl << "Confusing Filenames" << std::endl;
                std::string answer6;
                std::cout << std::endl << "Would you like to scramble Desktop filenames recursively (including all sub-folders), or only files directly on the Desktop? (Type [1-3] and press Enter to continue...)" << std::endl << "1. On-Desktop Files" << std::endl << "2. All Desktop Folders & Files" << std::endl << "3. Return to main menu" << std::endl;
                std::getline(std::cin, answer6);
                std::vector<std::filesystem::path> files;
                if(answer6 == "1"){
                    std::cout << std::endl << "Scrambling files found directly on current user's Desktop:" << std::endl;
                    files = fsGetFiles(getEnvUsernameDirectory() + "Desktop\\test55"); // get all files directly on desktop
                } else if(answer6 == "2"){
                    std::cout << std::endl << "Scrambling files found on current user's Desktop and in sub-folders:" << std::endl;
                    files = fsGetFilesRecursive(getEnvUsernameDirectory() + "Desktop\\test55"); // get all files and subfolders->files, recursively on desktop
                } else if(answer6 == "3"){
                    break;  // Exit to the main menu
                } else {
                    std::cout << std::endl << "Invalid option selected." << std::endl;
                    break;
                }
                if(files.size() > 0){
                    size_t index = 0;
                    for(const auto& file : files){
                        // get file extension 
                        std::string fileExtension = file.extension().string();
                        std::string newFileName = random_aZ09("CPP-HT-", 32, "-DEMO-") + std::to_string(index) + fileExtension;
                        std::string newFilePath = file.parent_path().string() + "\\" + newFileName;
                        std::cout << "Renaming " << file << " to " << newFilePath << std::endl;
                        std::filesystem::rename(file, newFilePath);
                        ++index;
                    }
                } else {
                    std::cout << "No files found..." << std::endl;
                }
            }
        } else if(mainPromptAnswer == "6"){
            std::cout << std::endl << std::endl << "===================" << std::endl << "===================" << std::endl <<  "Shutdown Initiated - Copy any logs as-needed, or Press Enter to exit...";
            std::cin.get();  // Wait for user to press Enter
            break;  // Exit the program
        } else {
            std::cout << "Invalid option selected." << std::endl << std::endl;
        }
    }
}
