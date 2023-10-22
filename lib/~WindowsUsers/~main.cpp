#include "main.h"
#include <string>
#include <cstdlib>
#include <ctime>

std::string random_aZ09(size_t length, std::string prefix, std::string suffix) {
    const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string result;
    result.resize(length);
    std::srand(std::time(0)); // Use current time as seed for random generator
    for (size_t i = 0; i < length; i++) {
        int randomIndex = std::rand() % charset.size(); // Generate a random index
        result[i] = charset[randomIndex];
    }
    if(prefix != ""){
        result = prefix + result;
    }
    if(suffix != ""){
        result = result + suffix;
    }
    return result;
}