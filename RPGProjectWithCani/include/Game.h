#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Includes.h"
#include "Map.h"

class Game
{
    private:

        bool Running;
        SDL_Event Event;

        SDL_Window* Window;
        SDL_Renderer* Renderer;

        SDL_Surface* Icon;

        int frame;
        int frameRate;

    public:

        Game();

        //Variables for the window

        int WindowHeight;
        int WindowWidth;
        bool Fullscreen;

        Uint32 start;
        Map map1;

        //Other functions

        int OnExecute();

        bool OnInit();
        bool LoadContent();

        void OnEvent(SDL_Event* Event);
        void OnLoop();
        void OnRender();
        void Cleanup();
        void OnStartup();
        void FrameRate(int FPS);
        void CheckFrameRate();

        //----------------------------------------------------------------

};
#endif // GAME_H_INCLUDED
