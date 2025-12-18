#include <SDL3/SDL.h>

#include "actor.h"
#include "rect.h"

Actor::Actor(float x, float y, float w, float h) : mRect(x, y, w, h)
{
}

Actor::~Actor() = default;

void Actor::Update()
{
}

void Actor::Render(SDL_Renderer *renderer)
{
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_FRect rect = (SDL_FRect)this->mRect;
  SDL_RenderFillRect(renderer, &rect);
}
