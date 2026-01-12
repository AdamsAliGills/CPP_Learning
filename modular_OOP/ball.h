#ifndef BALL
#define BALL

#include <string>
#include <string_view>

class Ball {

private:
  // variable definitions are implmented in .h
  static constexpr std::string_view default_color = "black";
  static constexpr int default_rad{10};

  std::string m_color;
  int m_rad;

public:
  // defaults are only defined in the .h at least in the copy value form
  // x=x_default
  Ball(int rad);
  Ball(std::string_view color = default_color, int rad = default_rad);

  // getter are completley defined .h but function and constroctor
  // implementations in .cpp
  const std::string &get_color() const { return m_color; }
  int get_radius() const { return m_rad; }
};

#endif
