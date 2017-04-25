#include "Map.h"

Uint32 get_pixel32( SDL_Surface *surface, int x, int y )
{
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;

    //Get the requested pixel
    return pixels[ ( y * surface->w ) + x ];
}

const char* getName(Uint32 pixel)
{
    Uint8 *rgba = (Uint8 *)&pixel;

    stringstream ss;
    ss << "MAT";
    ss << (Uint32) rgba[0]; // R
    ss << (Uint32) rgba[1]; // G
    ss << (Uint32) rgba[2]; // B
    string temp = ss.str();

    const char* retval = temp.c_str();

    return retval;
}

const char* getTilePath(string name)
{
    stringstream ss;
    ss << IMAGES_TILES;
    ss << "/";
    ss << name;
    ss << ".png";
    string retval = ss.str();

    return retval.c_str();
}

int getProperty(Uint32 pixel)
{
    Uint8 *rgba = (Uint8 *)&pixel;

    int property = (int) rgba[2];

    return property;
}

Map::Map()
{
    //ctor
}

//map_path  name
bool Map::Load(SDL_Renderer* renderer, char* map_name)
{
    if((map_data = IMG_Load(map_name)) == NULL)
    {
        cout << "Map not loaded: " << SDL_GetError() << endl;
        return false;
    }

    width = map_data->w;
    height = map_data->h;

    //Tile tiles[width][height];
    //tile_array = &tiles[0][0];

    for (int i = 0; i < map_data->w; i ++)
    {
        for (int j = 0; j < map_data->h; j ++)
        {
            Uint32 pixel = get_pixel32(map_data, i, j);

            string name = getName(pixel);
            int xPos = i * TILE_WIDTH;
            int yPos = j * TILE_HEIGHT;
            int property = getProperty(pixel);
            SDL_Texture* image = NULL;

            cout << xPos << " |POS| " << yPos <<endl;

            if(getTileByName(name) == NULL)
            {
                char* tile_path = (char*) getTilePath(name);
                cout << tile_path << "   " << i << "   " << j <<endl;
                image = LoadTexture(renderer, tile_path);
                tile_images.push_back(image);
            }
            else
            {
                image = getTileByName(name)->getImage();
            }

            tiles[i][j].Load(name, xPos, yPos, property, image);
        }
    }

    return true;
}

Tile *Map::getTileByName(string _name)
{
    for (int i = 0; i < width; i ++)
    {
        for (int j = 0; j < height; j ++)
        {
            /*if(tile_array[i * j].getName() == _name)
            {
                return &tile_array[i * j];
            }*/
        }
    }

    return NULL;
}

void Map::Render(SDL_Renderer* renderer)
{
    for (int i = 0; i < 10; i ++)
    {
        for (int j = 0; j < 10; j ++)
        {
            cout << i << " || " << j <<endl;
            //tile_array[i * j].Render(renderer);
            tiles[i][j].Render(renderer);
        }
    }
}

