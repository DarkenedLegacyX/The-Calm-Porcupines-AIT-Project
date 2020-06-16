#include "combat_scene.h"
#include "combat_background.h"
#include <SDL_image.h>

Combat_Scene::Combat_Scene()
	: Scene("Combat")
{

	add_game_object(new Combat_Background("Combat"));
}


Combat_Scene::~Combat_Scene()
{
}

void Combat_Scene::update(SDL_Window*)
{
}


