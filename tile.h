#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include "game_object.h"

class Tile : public Game_Object
{
public:
    
    Tile(std::string id, std::string texture_id, Vector_2D translation, int scale);
    ~Tile();
    void simulate_AI(Uint32, Assets*, Input*, Scene*);
   

private:

};
