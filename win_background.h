#pragma once
#include "game_object.h"

class Win_Background : public Game_Object
{
public:
	Win_Background(std::string id);
	~Win_Background();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;

};
