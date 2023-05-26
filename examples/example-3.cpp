// `stats.hpp` depends on `https://github.com/kthohr/gcem`
// we add -idirafter to expose it
// notice `stats.hpp` includes stuff in `stats_incl/` dir
// that was found without needing to expand the include search list
// c++ -std=c++17 -O3 example-3.cpp -idirafter "/usr/include/https://raw.githubusercontent.com/kthohr/gcem/master/include"
#include <iostream>
#include "https://raw.githubusercontent.com/kthohr/stats/master/include/stats.hpp"

int main(){
  std::cout << stats::dnorm(1.0, 0.0, 1.0) << std::endl;
  return 0;
}
