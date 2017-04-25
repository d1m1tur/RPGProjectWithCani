#include "Tile.h"

Tile::Tile()
{
    //ctor
    xPos = 0;
    yPos = 0;
    property = 0;
    image = NULL;
}

//rgb, x , y
void Tile::Load(string _name, int _xPos, int _yPos, int _property, SDL_Texture* _image)
{
    name = _name;
    xPos = _xPos;
    yPos = _yPos;
    property = _property;
    image = _image;
}

string Tile::getName()
{
    return name;
}

SDL_Texture* Tile::getImage()
{
    return image;
}

void Tile::Render(SDL_Renderer* renderer)
{
    if(image == NULL) return;

    cout << xPos << " |POS| " << yPos <<endl;

    Draw(renderer, image, xPos, yPos, TILE_WIDTH, TILE_HEIGHT);
}
