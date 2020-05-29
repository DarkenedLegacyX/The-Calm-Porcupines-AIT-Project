#include "combat_scene.h"

Combat_Scene::Combat_Scene()
	: Scene("Combat")
{
	_background_color.r = 0;
	_background_color.g = 255;
	_background_color.b = 0;
}

Combat_Scene::~Combat_Scene()
{
}

void Combat_Scene::update(SDL_Window*)
{
}