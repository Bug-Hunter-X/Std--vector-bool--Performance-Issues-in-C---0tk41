#include <iostream>
#include <vector>
#include <bitset>
#include <chrono>

int main() {
  // Using std::vector<bool>
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<bool> boolVector(1000000); 
  for (size_t i = 0; i < boolVector.size(); ++i) {
    boolVector[i] = (i % 2 == 0); 
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "std::vector<bool> time: " << duration.count() << " ms" << std::endl;

  // Using std::bitset
  start = std::chrono::high_resolution_clock::now();
  std::bitset<1000000> bitsetVector;
  for (size_t i = 0; i < 1000000; ++i) {
    bitsetVector[i] = (i % 2 == 0); 
  }
  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "std::bitset time: " << duration.count() << " ms" << std::endl;
  return 0; 
}
