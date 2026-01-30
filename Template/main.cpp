#include <iostream>

#include "template.h"

int main() {
  std::cout << max_int_only(1, 2) << '\n';
  std::cout << max_multi_type(2, 3.5) << '\n';
  // class type have to use < > when initilizing object
  Pair<double, int> o{5.2, 1};
  std::cout << max_pair(o) << '\n';
  return 0;
}
