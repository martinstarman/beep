#include <SDL3/SDL.h>
#include <vector>

#include "entity.h"
#include "world.h"

World::World()
{
}

World::~World()
{
  for (int i = 0; i < this->mEntities.size(); i++)
  {
    delete this->mEntities.at(i);
  }
}

void World::AddEntity(Entity *entity)
{
  this->mEntities.push_back(entity);
}

std::vector<Entity *> World::Entities()
{
  return this->mEntities;
}

void World::Update()
{
  for (int i = 0; i < this->mEntities.size(); i++)
  {
    this->mEntities.at(i)->Update();
  }
}

void World::Render(SDL_Renderer *renderer)
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);

  for (int i = 0; i < this->mEntities.size(); i++)
  {
    this->mEntities.at(i)->Render(renderer);
  }

  SDL_RenderPresent(renderer);
}
