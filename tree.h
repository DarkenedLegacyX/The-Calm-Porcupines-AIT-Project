#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include "game_object.h"

class Tree : public Game_Object
{
public:

    Tree(std::string id, std::string texture_id, Vector_2D translation, int scale);
    ~Tree();
    virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;

};

