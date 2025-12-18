#pragma once

#include <SDL3/SDL.h>

#include "entity.h"
#include "rect.h"

class Actor : public Entity
{
public:
  Actor(float x, float y, float w, float h);
  ~Actor();
  void Update() override;
  void Render(SDL_Renderer *renderer) override;

private:
  Rect mRect;
};
