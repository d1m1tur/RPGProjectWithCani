#include "Game.h"

void Game::OnLoop()
{
    //Gets the start ticks
    OnStartup();


    //Caps the frame rate depending on the ticks that have past
    FrameRate(FPS);
}

