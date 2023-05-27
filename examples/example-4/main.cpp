// c++ -std=c++17 -O3 -idirafter "stats-include" -idirafter "gcem-include" main.cpp
#include <iostream>
#include "stats.hpp"

int main(){
  std::cout << stats::dnorm(1.0, 0.0, 1.0) << std::endl;
  return 0;
}
