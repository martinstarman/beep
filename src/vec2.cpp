#include "vec2.h"

Vec2::Vec2(float x, float y) : mX(x), mY(y)
{
}

Vec2::~Vec2() = default;

float Vec2::Y()
{
  return this->mY;
}

void Vec2::SetY(float y)
{
  this->mY = y;
}
