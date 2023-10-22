#pragma once
#include <string>
std::string getEnvUsername(); // returns current env username
std::string getEnvUsernameDirectory(); // returns current env username directory
std::vector<std::filesystem::path> getUserDirectories(); // returns list of user directories