#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include "game_object.h"

class Tile : public Game_Object
{
public:
    
    Tile(std::string id, std::string texture_id, Vector_2D translation, int scale, int type);
    ~Tile();
    virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
   
    int get_type();

    void activate_tile();
    void deactivate_tile();
    bool is_active();
private:
    int _type;
    bool _active;
};
