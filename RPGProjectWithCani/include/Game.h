#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Includes.h"

class Game
{
    private:

        bool Running;
        SDL_Event Event;

        SDL_Window* Window;
        SDL_Renderer* Renderer;

        SDL_Surface* Icon;

    public:

        Game();

        //Variables for the window

        int WindowHeight;
        int WindowWidth;
        bool Fullscreen;

        Uint32 start;

        //Creating objects

        static bool Draw(SDL_Renderer* Rend,
                  SDL_Texture* Temp,
                  int x = 0, int y = 0, int w = 0, int h = 0,
                  double angle = 0,
                  SDL_RendererFlip Flip = SDL_FLIP_NONE);
        static bool Draw(SDL_Renderer* Rend,
                  SDL_Texture* Temp,
                  int x = 0, int y = 0, int w = 0, int h = 0,
                  int x2 = 0, int y2 = 0, int w2 = 0, int h2 = 0,
                  double angle = 0,
                  SDL_RendererFlip Flip = SDL_FLIP_NONE);
        static SDL_Texture* OnLoad(SDL_Renderer* Rend, char* FILE );

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
};
#endif // GAME_H_INCLUDED
