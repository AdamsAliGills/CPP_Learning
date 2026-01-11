#include <iostream>
#include <string>
#include <string_view>

class Ball {

private:
  static constexpr std::string_view default_color = "black";
  static constexpr int default_rad{10};
  std::string m_color;
  int m_rad;

public:
  Ball(int rad) : Ball{default_color, rad} {}

  Ball(std::string_view color = default_color, int rad = default_rad)
      : m_color{color}, m_rad{rad} {}

  const std::string &get_color() const { return m_color; }
  int get_radius() const { return m_rad; }
};

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
