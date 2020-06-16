#include "lose_scene.h"
#include "player_dead.h"
#include "lose_background.h"

Lose_Scene::Lose_Scene()
	: Scene("Lose")
{
	_background_color.r = 215;
	_background_color.g = 215;
	_background_color.b = 215;

	add_game_object(new Player_Dead("PlayerDead"));
	add_game_object(new Lose_Background("LoseB"));
}

Lose_Scene::~Lose_Scene()
{
}

void Lose_Scene::update(SDL_Window* window)
{
}
