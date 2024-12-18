#include "output_processor.h"
#include <cctype>

std::string processOutput(const std::vector<std::string>& words) {
    std::string result;
    for (const auto& word : words) {
        if (!word.empty()) {
            result += toupper(word[0]); // Capitalize the first character
            result += word.substr(1);   // Append the rest of the word
            result += ' ';              // Add a space between words
        }
    }

    if (!result.empty()) {
        result.pop_back(); // Remove the last space
    }
    return result;
}
