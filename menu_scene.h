#pragma once

#include "scene.h"

class Menu_Scene : public Scene
{
public:
	Menu_Scene();
	~Menu_Scene();

	virtual void update(SDL_Window* window) override;
};