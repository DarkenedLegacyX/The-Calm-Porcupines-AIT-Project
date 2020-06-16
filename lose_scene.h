#pragma once

#include "scene.h"

class Lose_Scene : public Scene
{
public:
	Lose_Scene();
	~Lose_Scene();

	virtual void update(SDL_Window* window) override;
};
