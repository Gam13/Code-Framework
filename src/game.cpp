#include "CodeFramework/game.hpp"

namespace CodeFramework
{

    Game::virtual void handleEvents(){} // Gerenciar eventos (entrada do jogador)
    Game::virtual void update(){}    // Atualizar a lógica do jogo
    Game::virtual void render(){}      // Renderizar os gráficos

}