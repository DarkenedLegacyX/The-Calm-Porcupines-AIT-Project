#pragma once
#include "game_object.h"

class Player_Dead : public Game_Object
{
public:
	Player_Dead(std::string id);
	~Player_Dead();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
	virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene) override;
};