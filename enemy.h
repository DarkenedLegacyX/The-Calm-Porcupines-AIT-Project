#pragma once
#include "game_object.h"

class Enemy : public Game_Object
{
protected:
	int hp, hpMax, str, def;
public:

	Enemy(std::string id);
	~Enemy();


	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
	virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene) override;

	void setupStats(int _hp, int _str, int _def);

	int getHP();
	int getHPMax();


	int getDamage();
	void takeDamage(int dmg);

	void displayStats();
};