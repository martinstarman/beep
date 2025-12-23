#pragma once

#include <SDL3/SDL.h>

#include "entity.h"
#include "rect.h"
#include "vec2.h"

class Actor : public Entity
{
public:
  Actor(float x, float y, float w, float h);
  ~Actor();
  void Update(double deltaTime) override;
  void Render(SDL_Renderer *renderer) override;

private:
  Rect mRect;
  Vec2 mVelocity;
  float kGravity = 9.8;
};
