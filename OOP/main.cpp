#include <iostream>
#include <string>
#include <string_view>

class Ball {

private:
  /*
   defaults for clean code

   static is used for the copying of the defaults to be quick coming
   the same memory address

   constexpr: as a saftey so the data is immutable (constant) and used a
   compile time constant (so initlization happens when we make the build not
   when running)

   string_view (read only refrence) is used as string is a dynamic data type
   */
  static constexpr std::string_view default_color = "black";
  static constexpr int default_rad{10};

  std::string m_color;
  int m_rad;

public:
  // deligation so a ball object can be made just by initilizing rad (number)
  Ball(int rad) : Ball{default_color, rad} {}

  Ball(std::string_view color = default_color, int rad = default_rad)
      : m_color{color}, m_rad{rad} {}

  const std::string &get_color() const { return m_color; }
  int get_radius() const { return m_rad; }
};

// pasing the object refrence(hold the memory adress similar to pointers) from
// ball class however refrence don't change once used
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
