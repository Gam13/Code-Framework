#ifndef GAME_H
#define GAME_H

namespace CodeFramework
{
    class Game {
public:
    virtual ~Game() = default;

    virtual void handleEvents(); // Gerenciar eventos (entrada do jogador)
    virtual void update();     // Atualizar a lógica do jogo
    virtual void render();      // Renderizar os gráficos
};
} // namespace CodeFramework

#endif