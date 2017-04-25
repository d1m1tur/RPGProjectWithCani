#include "Game.h"

Game::Game()
{
    //ctr

    Window = NULL;

    Icon = NULL;
    Running = true;
    Fullscreen = false;

    frameRate = 0;
}

int Game::OnExecute()
{
    OnStartup();

    if(OnInit() == false)
    {
        Sleep(1000);
        return -1;
    }

    while(Running)
    {
        while(SDL_PollEvent(&Event))
        {
            OnEvent(&Event);
        }
        OnLoop();
        OnRender();
    }

    cout<<"Cleaning started"<<endl;
    Cleanup();
    cout<<"Cleaning ended"<<endl;

    return 0;
}

int main(int argc, char* argv[])
{
    Game theGame;

    return theGame.OnExecute();
}
