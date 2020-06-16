#pragma once
#include "game_object.h"

class Combat_Background : public Game_Object
{
public:
	Combat_Background(std::string id);
	~Combat_Background();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
};

