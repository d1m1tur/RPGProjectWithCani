#include "Game.h"

void Game::Cleanup()
{

    ///Free memory


    //SDL

    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_FreeSurface(Icon);
    SDL_Quit();
}
