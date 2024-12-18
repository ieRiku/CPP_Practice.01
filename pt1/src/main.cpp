#include <iostream>
#include <string>
#include "input_processor.h"
#include "output_processor.h"

int main() {
    std::string input;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    auto words = preprocessInput(input);  // Function from input_processor.h
    std::string result = processOutput(words);  // Function from output_processor.h

    std::cout << "Processed sentence: " << result << std::endl;
    return 0;
}
