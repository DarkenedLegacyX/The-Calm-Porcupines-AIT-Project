#pragma once

#include "scene.h"
#include "enemy.h"
#include "player.h"

class Combat_Scene : public Scene
{
public:
	Combat_Scene();

	~Combat_Scene();
	   
	virtual void update(SDL_Window* window) override;

	SDL_Texture* backgroundTexture;

	Player* hero;

	Enemy* enemy;

	SDL_Renderer* renderer;

	void draw();
};