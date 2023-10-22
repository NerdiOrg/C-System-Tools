// FolderScanner.cpp
#include "main.h"
#include <iostream>

std::vector<std::filesystem::path> fsGetFolders(const std::filesystem::path& dir_path) {
    std::vector<std::filesystem::path> folder_list;
    for (const auto& entry : std::filesystem::directory_iterator(dir_path)) {
        if (std::filesystem::is_directory(entry.status())) {
            folder_list.push_back(entry.path());
        }
    }
    return folder_list;
}

std::vector<std::filesystem::path> fsGetFoldersRecursive(const std::filesystem::path& dir_path) {
    std::vector<std::filesystem::path> folder_list;
    folder_list.push_back(dir_path);
    for (const auto& entry : std::filesystem::directory_iterator(dir_path)) {
        if (std::filesystem::is_directory(entry.status())) {
            folder_list.push_back(entry.path());
            std::vector<std::filesystem::path> subfolder_folders = fsGetFoldersRecursive(entry.path());
            folder_list.insert(folder_list.end(), subfolder_folders.begin(), subfolder_folders.end());
        }
    }
    return folder_list;
}

std::vector<std::filesystem::path> fsGetFiles(const std::filesystem::path& dir_path){
    std::vector<std::filesystem::path> file_list;
    for (const auto& entry : std::filesystem::directory_iterator(dir_path)) {
        if (std::filesystem::is_regular_file(entry.status())) { // not a directory, symlink, device, or empty file with no data
            file_list.push_back(entry.path());
        }
    }
    return file_list;
}

std::vector<std::filesystem::path> fsGetFilesRecursive(const std::filesystem::path& dir_path){
    std::vector<std::filesystem::path> file_list;
    for (const auto& entry : std::filesystem::directory_iterator(dir_path)) {
        if (std::filesystem::is_directory(entry.status())) { // not a directory, symlink, device, or empty file with no data
            std::vector<std::filesystem::path> subfolder_files = fsGetFilesRecursive(entry.path());
            file_list.insert(file_list.end(), subfolder_files.begin(), subfolder_files.end());
        } else if (std::filesystem::is_regular_file(entry.status())) { // not a directory, symlink, device, or empty file with no data
            file_list.push_back(entry.path());
        }
    }
    return file_list;
}
