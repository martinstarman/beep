#include <SDL3/SDL.h>

#include "actor.h"
#include "rect.h"
#include "vec2.h"

Actor::Actor(float x, float y, float w, float h) : mRect(x, y, w, h), mVelocity(0.0, 0.0)
{
}

Actor::~Actor() = default;

void Actor::Update(double deltaTime)
{
  this->mVelocity.SetY(this->mVelocity.Y() + (this->kGravity * deltaTime));
  this->mRect.SetY(this->mRect.Y() + (this->mVelocity.Y() * (float)deltaTime));
}

void Actor::Render(SDL_Renderer *renderer)
{
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_FRect rect = (SDL_FRect)this->mRect;
  SDL_RenderFillRect(renderer, &rect);
}
