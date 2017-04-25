#include "Game.h"

bool Game::OnInit()
{
    //Initialize everything in SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }

    //Creating Window             title ,Xpos,Ypos,Width,Height, settings
    if((Window = SDL_CreateWindow("TITLE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MIN_WINDOW_X, MIN_WINDOW_Y,
                                  SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED)) == NULL)
    {
        return false;
    }

    SDL_SetWindowMaximumSize(Window, MAX_WINDOW_X, MAX_WINDOW_Y);
    SDL_SetWindowMinimumSize(Window, MIN_WINDOW_X, MIN_WINDOW_Y);

    SDL_GetWindowSize(Window, &WindowWidth, &WindowHeight);

    Fullscreen = false;

    if((Icon = IMG_Load("./resources/images/favicon.png")) == NULL)
    {
        cout<<"Icon not loaded"<<endl;
        return false;
    }

    SDL_SetWindowIcon(Window, Icon);

    // Creating Renderer
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    //Check Renderer
    if(Renderer == NULL)
    {
        cout << SDL_GetError() << endl;
        return false;
    }

    //Load Images

    if(LoadContent() == false)
    {
        cout<<"Load content failed"<<endl;
        return false;
    }

    return true;
}
