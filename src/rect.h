#pragma once

#include <SDL3/SDL.h>

class Rect
{
public:
  Rect(float x, float y, float w, float h);
  ~Rect();
  operator SDL_FRect() { return {this->mX, this->mY, this->mW, this->mH}; };

private:
  float mX;
  float mY;
  float mW;
  float mH;
};
