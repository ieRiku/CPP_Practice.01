#include <iostream>
#include <fstream>
#include <random>

const std::string characters = "ATGC";

void compose() {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> distribution(0, characters.size() - 1);

  std::ofstream file("Abcd.txt");
  if (!file.is_open()) {
    std::cerr << "Error opening file Abcd.txt" << std::endl;
    return;
  }

  for (int i = 0; i < 100; ++i) {
    int random_index = distribution(generator);
    file << characters[random_index];
  }

  file.close();

  std::cout << "Successfully created Abcd.txt with 100 random characters." << std::endl;
}