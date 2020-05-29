#pragma once
#pragma once

#include "scene.h"

class Combat_Scene : public Scene
{
public:
	Combat_Scene();
	~Combat_Scene();

	virtual void update(SDL_Window* window) override;
};