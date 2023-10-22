#include <iostream>
#include <cstdlib>
#include "../FolderScanner/main.h"
#include "main.h"

std::string getEnvUsername() {
    const char* username = std::getenv("USERNAME"); // because of the null pointer, this is a char pointer, not a string
    if (username) {
        return std::string(username); // convert to string for easier use outside
    } else {
        return "";
    }
}

std::string getEnvUsernameDirectory() {
    std::string homeDir = "C:\\Users\\";
    std::string username = getEnvUsername(); // returns current env username or "" as string
    if(username != ""){
        return homeDir + username + "\\";
    }
    return "";
}

std::vector<std::filesystem::path> getUserDirectories(){
    std::string usersFilePath = "C:\\Users\\";
    std::vector<std::filesystem::path> folders = fsGetFolders(usersFilePath);
    return folders;
}
