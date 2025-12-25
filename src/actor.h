#pragma once

#include <SDL3/SDL.h>

#include "entity.h"
#include "vec2.h"

class Actor : public Entity
{
public:
  Actor(Vec2 position, Vec2 size);
  ~Actor();
  void Update(double deltaTime) override;
  void Render(SDL_Renderer *renderer) override;

private:
  Vec2 mPosition;
  Vec2 mSize;
  Vec2 mVelocity;
  float kGravity = 9.8;
};
