#pragma once
#include "game_object.h"

class Lose_Background : public Game_Object
{
public:
	Lose_Background(std::string id);
	~Lose_Background();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;

};

