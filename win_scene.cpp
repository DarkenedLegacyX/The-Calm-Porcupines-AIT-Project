#include "win_scene.h"
#include "dragon.h"
#include "win_background.h"

Win_Scene::Win_Scene()
	: Scene("Win")
{
	_background_color.r = 215;
	_background_color.g = 215;
	_background_color.b = 215;

	add_game_object(new Dragon("Dragon"));
	add_game_object(new Win_Background("Win"));
}

Win_Scene::~Win_Scene()
{
}

void Win_Scene::update(SDL_Window*)
{
}