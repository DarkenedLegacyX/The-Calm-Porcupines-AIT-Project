#pragma once
#include "game_object.h"

class Menu_background : public Game_Object
{
public:
	Menu_background(std::string id);
	~Menu_background();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;

};

