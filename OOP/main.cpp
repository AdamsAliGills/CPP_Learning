#include <iostream>
#include <string>
#include <string_view>

class Ball {

private:
  std::string m_color{};
  int m_rad{};

public:
  Ball(std::string color, int rad) : m_color{color}, m_rad{rad} {}

  const std::string &get_color() const { return m_color; }
  int get_radius() const { return m_rad; }
};

void print(const Ball &ball) {
  std::cout << "ball: " << ball.get_color() << ", " << ball.get_radius()
            << "\n";
}

int main() {
  Ball blue{"blue", 10};
  print(blue);

  Ball red{"red", 20};
  print(red);
}
