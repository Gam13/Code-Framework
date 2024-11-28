#ifndef ENGINE_H
#define ENGINE_H

#include "SDL.h"
#include <iostream>
#include <string>

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

        bool gameRunning = false;

        void initialize();
        void renderer();
        void handleEvents();
        void clean();
    public:
        Engine(const std::string &title, int width, int height);
        ~Engine();

        void run();
        
    };
}
#endif
