#pragma once

#include <SDL3/SDL.h>
#include <vector>

#include "entity.h"

class World
{
public:
  World();
  ~World();
  void AddEntity(Entity *);
  std::vector<Entity *> Entities();
  void Update();
  void Render(SDL_Renderer *renderer);

private:
  std::vector<Entity *> mEntities;
};
