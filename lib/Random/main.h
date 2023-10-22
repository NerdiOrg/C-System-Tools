#pragma once
#include <string>
std::string random_aZ09(std::string prefix, size_t length, std::string suffix); // returns random string (using time(0)) with optional prefix/suffix
void randomSeed(); // seeds random generator with time(0)