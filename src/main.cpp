#include <chrono>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "actor.h"
#include "rect.h"
#include "world.h"

const int kWindowWidth = 640;
const int kWindowHeight = 480;

const double kMsPerFrame = 1000.0 / 60.0;

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;

int SDL_main(int argc, char *args[])
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("beep", kWindowWidth, kWindowHeight, SDL_WINDOW_RESIZABLE, &gWindow, &gRenderer))
    {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_SetRenderLogicalPresentation(gRenderer, kWindowWidth, kWindowHeight, SDL_LOGICAL_PRESENTATION_LETTERBOX);

    auto previousTime = std::chrono::system_clock::now();
    double lag = 0.0;

    auto world = new World();
    auto actor = new Actor(10.0, 10.0, 100.0, 100.0);

    world->AddEntity(actor);

    while (true)
    {
        auto currentTime = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = currentTime - previousTime;
        previousTime = currentTime;
        lag += elapsed.count();

        while (lag >= kMsPerFrame)
        {
            world->Update();
            lag -= kMsPerFrame;
        }

        world->Render(gRenderer);
    }

    delete world;
    delete actor;
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);

    return 0;
}
