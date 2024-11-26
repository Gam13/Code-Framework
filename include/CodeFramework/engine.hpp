#ifndef ENGINE_H
#define ENGINE_H

#include "SDL.h"
#include <iostream>
#include <string>
#include "game.hpp"
namespace CodeFramework
{

    class Engine
    {
    private:
        std::string gameName;
        int screenWidth;
        int screenHeight;
        SDL_Renderer *gameRenderer = nullptr;
        SDL_Window *gameWindow = nullptr;

        Game* game_;
        bool gameRunning = false;

        void initialize();
        void renderer();
        void handleEvents();
        void clean();
    public:
        Engine(Game* game_,const std::string &title, int width, int height);
        ~Engine();

        void run();
        
    };
}
#endif
