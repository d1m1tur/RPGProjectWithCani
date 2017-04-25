#include "Game.h"

void Game::OnRender()
{
    SDL_RenderClear(Renderer);

    map1.Render(Renderer);

    SDL_RenderPresent(Renderer);
}
