#include "input_processor.h"
#include <sstream>

std::vector<std::string> preprocessInput(const std::string& input) {
    std::vector<std::string> words;
    std::stringstream ss(input);
    std::string word;

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}
