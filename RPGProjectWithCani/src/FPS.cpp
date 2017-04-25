#include "Game.h"

void Game::OnStartup()
{
    start = SDL_GetTicks();
}

void Game::FrameRate(int FPS)
{
    cout << SDL_GetTicks() - start <<endl;
    cout << 1000/FPS <<endl;

    if(1000/FPS > ((SDL_GetTicks() - start) + 1)/FPS)
    {
        SDL_Delay(1000/FPS - (SDL_GetTicks() - start));
    }
}

void Game::CheckFrameRate()
{
    cout << frameRate <<endl;
    frame++;

    if(SDL_GetTicks() - start > 1000)
    {
        start = SDL_GetTicks();
        frameRate = frame;
        frame = 0;
    }
}

