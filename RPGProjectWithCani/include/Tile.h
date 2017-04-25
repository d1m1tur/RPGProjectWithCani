#ifndef TILE_H
#define TILE_H

#define TILE_WIDTH  32
#define TILE_HEIGHT 32
#include "Includes.h"

class Tile
{
    public:
        Tile();
        SDL_Texture* getImage();
        string getName();
        void Load(string _name, int _xPos, int _yPos, int _property, SDL_Texture* _image);
        void Render(SDL_Renderer* renderer);

    protected:

    private:
        //position x y
        //id/name MAT001000000
        string name;
        int xPos;
        int yPos;
        int property;
        SDL_Texture* image;

        //image
};

#endif // TILE_H
