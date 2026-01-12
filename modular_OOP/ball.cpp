#include "ball.h"

// function implmentations are made in .cpp
Ball::Ball(int rad) : Ball{default_color, rad} {}

Ball::Ball(std::string_view color, int rad) : m_color{color}, m_rad{rad} {}
