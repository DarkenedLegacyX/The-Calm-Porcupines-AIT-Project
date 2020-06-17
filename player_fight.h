#pragma once
#include "game_object.h"

class Player_Fight : public Game_Object
{
public:

	Player_Fight(std::string id);
	~Player_Fight();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
	virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene) override;

protected:
	int hp, hpMax, str, def;

	void setupStats(int _hp, int _str, int _def);

	int getHP();
	int getHPMax();


	int getDamage();
	void takeDamage(int dmg);

	void displayStats();
};