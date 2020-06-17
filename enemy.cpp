#include "enemy.h"
#include <iostream>

Enemy::Enemy(std::string id)
	: Game_Object(id, "Texture.Enemy.Idle")
{
	_translation = Vector_2D(525, 550);
	_velocity = Vector_2D(0, 0);
	_width = 150;
	_height = 150;

	hp = 10;
	hpMax = 10;
	str = 4;
	def = 2;
}

Enemy::~Enemy()
{
}

void Enemy::simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene)
{
}

void Enemy::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config, scene);
}

void Enemy::setupStats(int _hp, int _str, int _def)
{
	hp = _hp;
	hpMax = _hp;
	str = _str;
	def = _def;
}

int Enemy::getHP()
{
	return hp;
}

int Enemy::getHPMax()
{
	return hpMax;
}


int Enemy::getDamage()
{
	return str;
}

void Enemy::takeDamage(int dmg)
{
	int dmgAfterDef = dmg - def;
	if (dmgAfterDef < 1)
		dmgAfterDef = 1;

	hp = hp - dmgAfterDef;
}

void Enemy::displayStats()
{
	std::cout << "Name: God" << std::endl;
	std::cout << "hp: " << hp << "/" << hpMax << " str: " << str << " def: " << def << std::endl;
}
