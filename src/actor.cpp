#include <SDL3/SDL.h>

#include "actor.h"
#include "vec2.h"

Actor::Actor(Vec2 position, Vec2 size) : mPosition(position), mSize(size), mVelocity(0.0, 0.0)
{
}

Actor::~Actor() = default;

void Actor::Update(double deltaTime)
{
  this->mVelocity.SetY(this->mVelocity.Y() + (this->kGravity * deltaTime));
  this->mPosition.SetY(this->mPosition.Y() + (this->mVelocity.Y() * (float)deltaTime));
}

void Actor::Render(SDL_Renderer *renderer)
{
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_FRect rect = SDL_FRect{this->mPosition.X(), this->mPosition.Y(), this->mSize.X(), this->mSize.Y()};
  SDL_RenderFillRect(renderer, &rect);
}
