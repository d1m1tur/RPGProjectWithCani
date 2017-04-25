#ifndef MAP_H
#define MAP_H

#include "Includes.h"
#include "Tile.h"

class Map
{
    public:
        Map();
        bool Load(SDL_Renderer *renderer, char *map_name);
        void Render(SDL_Renderer *renderer);

    protected:

    private:

        vector <SDL_Texture*> tile_images;
        SDL_Surface *map_data;
        //Tile *tile_array;
        Tile tiles[10][10];
        int width;
        int height;

        Tile *getTileByName(string _name);


};

#endif // MAP_H
