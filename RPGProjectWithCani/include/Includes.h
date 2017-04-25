#ifndef INCLUDES_H_INCLUDED
#define INCLUDES_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <typeinfo>
#include <fstream>
#include <sstream>
#include <math.h>
#include <string.h>
#include <vector>

#define MAX_WINDOW_X 1367
#define MIN_WINDOW_X 512
#define MAX_WINDOW_Y 768
#define MIN_WINDOW_Y 512
#define IMAGES_TILES "./resources/images/tiles"

const int FPS_RATE = 60;

using namespace std;

static bool Draw(SDL_Renderer* Rend,
            SDL_Texture* Temp,
            int x = 0, int y = 0, int w = 0, int h = 0,
            int x2 = 0, int y2 = 0, int w2 = 0, int h2 = 0,
            double angle = 0,
            SDL_RendererFlip Flip = SDL_FLIP_NONE);
static SDL_Texture* LoadTexture(SDL_Renderer* Rend, char* FILE );

SDL_Texture* LoadTexture(SDL_Renderer* Rend, char* File)
{
    SDL_Surface* Surf_Temp = NULL;
    SDL_Texture* Text_Return = NULL;

    if((Surf_Temp = IMG_Load(File)) == NULL)
    {
        cout<<"Surface not loaded"<<endl;
        return NULL;
    }

    if((Text_Return = SDL_CreateTextureFromSurface(Rend, Surf_Temp)) == NULL)
    {
        cout<<"Creating texture from surface failed! Check your Renderer."<<endl;
        return NULL;
    }

    SDL_FreeSurface(Surf_Temp);

    return Text_Return;
}

/// Draw Functions ...

bool Draw(SDL_Renderer* Rend,
                SDL_Texture* Temp,
/*Location*/    int x, int y, int w, int h,
/*  Part  */    int x2, int y2, int w2, int h2,
                double angle,
                SDL_RendererFlip Flip)
{
    //Rectangle for position
    SDL_Rect dstrect = {x, y, w, h};
    //Rectangle for part of an image
    SDL_Rect srtrect;

    //Texture is empty
    if(Temp == NULL)
    {
        return false;
    }


    srtrect.x = x2;
    srtrect.y = y2;
    srtrect.w = w2;
    srtrect.h = h2;

    //Draw on the screen
	SDL_RenderCopyEx(Rend, Temp, NULL, &dstrect, angle, NULL, Flip);

	return true;
}

#endif // INCLUDES_H_INCLUDED
