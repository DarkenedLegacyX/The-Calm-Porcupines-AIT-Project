#include "enemy.h"
#include <iostream>

Enemy::Enemy()
{
	hp = 10;
	hpMax = 10;
	str = 4;
	def = 2;
	agi = 3;
}

Enemy::~Enemy()
{
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
