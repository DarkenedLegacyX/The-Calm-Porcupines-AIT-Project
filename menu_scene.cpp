#include "menu_scene.h"
#include "menu_background.h"
#include "text.h"

Menu_Scene::Menu_Scene()
	: Scene("Menu")
{
	_background_color.r = 255;
	_background_color.g = 0;
	_background_color.b = 0;

	add_game_object(new Menu_background("menu"));
}

Menu_Scene::~Menu_Scene()
{
}

void Menu_Scene::update(SDL_Window* window)
{

}
