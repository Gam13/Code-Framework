#ifndef GAME_H
#define GAME_H

namespace CodeFramework
{
    class Game {
public:
    virtual ~Game() = default;

    virtual void handleEvents() = 0; // Gerenciar eventos (entrada do jogador)
    virtual void update() = 0;      // Atualizar a lógica do jogo
    virtual void render() = 0;      // Renderizar os gráficos
};
} // namespace CodeFramework

#endif