#include "ball.h"
#include <iostream>
#include <string_view>

void print(const Ball &ball) {
  std::cout << "ball: " << ball.get_color() << ", " << ball.get_radius()
            << "\n";
}

int main() {
  Ball def{};
  Ball blue{"blue"};
  Ball twenty{20};
  Ball blueTwenty{"blue", 20};
  print(twenty);
  return 0;
}
