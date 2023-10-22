#pragma once
#include <vector>
#include <filesystem>
std::vector<std::filesystem::path> fsGetFolders(const std::filesystem::path& dir_path); // returns list of folder paths found in given dir
std::vector<std::filesystem::path> fsGetFoldersRecursive(const std::filesystem::path& dir_path); // returns list of folders in given dir, and all subfolders - unlimited depth
std::vector<std::filesystem::path> fsGetFiles(const std::filesystem::path& dir_path); // returns list of file paths found in given dir, for regular files
std::vector<std::filesystem::path> fsGetFilesRecursive(const std::filesystem::path& dir_path); // returns list of files in given dir, and from all subfolders - unlimited depth