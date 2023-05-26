// c++ -std=c++17 -O3 example-2.cpp -idirafter "/usr/include/https://raw.githubusercontent.com/nlohmann/json/develop/include"
#include <iostream>
#include <nlohmann/json.hpp>

int main(){
  nlohmann::json j;
  std::cin >> j;
  std::cout << j.dump(2) << std::endl;
  return 0;
}
