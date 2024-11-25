#include "CodeFramework/engine.hpp"

Engine::Engine(const std::string& title, int width, int height)
    : gameName(title), screenWidth(width), screenHeight(height) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "O SDL não pôde ser iniciado: " << SDL_GetError() << std::endl;
        gameRunning = false;
    } else {
        gameRunning = true;
    }
}

Engine::~Engine() {
    clean();
    SDL_Quit();
}

void Engine::initialize() {

    gameWindow = SDL_CreateWindow(
        gameName.c_str(),
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        screenWidth, screenHeight,
        SDL_WINDOW_SHOWN
    );

    if (gameWindow == nullptr) {
        std::cerr << "Janela do SDL não pôde ser criada: " << SDL_GetError() << std::endl;
        gameRunning = false;
        return;
    }

    gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gameRenderer == nullptr) {
        std::cerr << "Renderer do SDL não pôde ser criado: " << SDL_GetError() << std::endl;
        gameRunning = false;
    }
}

void Engine::handleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            gameRunning = false;
        }
    }
}

void Engine::renderer() {
    SDL_SetRenderDrawColor(gameRenderer, 100, 42, 100, 255);
    SDL_RenderClear(gameRenderer);
    SDL_RenderPresent(gameRenderer);
}

void Engine::clean() {
    if (gameRenderer != nullptr) {
        SDL_DestroyRenderer(gameRenderer);
        gameRenderer = nullptr;
    }
    if (gameWindow != nullptr) {
        SDL_DestroyWindow(gameWindow);
        gameWindow = nullptr;
    }
}

bool Engine::isRunning() const {
    return gameRunning;
}
