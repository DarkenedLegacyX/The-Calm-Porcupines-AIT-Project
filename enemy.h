#pragma once


class Enemy 
{
protected:
	int hp, hpMax, str, def;
public:

	Enemy();
	~Enemy();

	void setupStats(int _hp, int _str, int _def);

	int getHP();
	int getHPMax();


	int getDamage();
	void takeDamage(int dmg);

	void displayStats();
};