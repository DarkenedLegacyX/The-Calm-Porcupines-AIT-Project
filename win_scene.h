#pragma once

#include "scene.h"

class Win_Scene : public Scene
{
public:
	Win_Scene();
	~Win_Scene();

	virtual void update(SDL_Window* window) override;
};
