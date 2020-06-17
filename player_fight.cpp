#include "player_fight.h"
#include <iostream>

Player_Fight::Player_Fight(std::string id)
	: Game_Object(id, "Texture.Player.Fight")
{
	_translation = Vector_2D(125, 560);
	_velocity = Vector_2D(0, 0);
	_width = 150;
	_height = 150;

	hp = 100;
	hpMax = 10;
	str = 4;
	def = 2;
}

Player_Fight::~Player_Fight()
{
}

void Player_Fight::simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene)
{
}

void Player_Fight::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config, scene);

}

void Player_Fight::setupStats(int _hp, int _str, int _def)
{
	hp = _hp;
	hpMax = _hp;
	str = _str;
	def = _def;
}

int Player_Fight::getHP()
{
	return hp;
}

int Player_Fight::getHPMax()
{
	return hpMax;
}


int Player_Fight::getDamage()
{
	return str;
}

void Player_Fight::takeDamage(int dmg)
{
	int dmgAfterDef = dmg - def;
	if (dmgAfterDef < 1)
		dmgAfterDef = 1;

	hp = hp - dmgAfterDef;
}

void Player_Fight::displayStats()
{
	std::cout << "Name: ZuzaNesh" << std::endl;
	std::cout << "hp: " << hp << "/" << hpMax << " str: " << str << " def: " << def << std::endl;
}