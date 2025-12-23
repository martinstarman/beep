#pragma once

#include <SDL3/SDL.h>

class Entity
{
public:
  virtual void Update(double deltaTime) = 0;
  virtual void Render(SDL_Renderer *renderer) = 0;
};
