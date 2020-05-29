#include "menu_scene.h"

Menu_Scene::Menu_Scene()
	: Scene("Menu")
{
	_background_color.r = 255;
	_background_color.g = 0;
	_background_color.b = 0;
}

Menu_Scene::~Menu_Scene()
{
}

void Menu_Scene::update(SDL_Window* window)
{
}
