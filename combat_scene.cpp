#include "combat_scene.h"
#include <SDL_image.h>

Combat_Scene::Combat_Scene()
	: Scene("Combat")
{
	backgroundTexture = IMG_LoadTexture(renderer, "Assets/beach.png");
}


Combat_Scene::~Combat_Scene()
{
}

void Combat_Scene::update(SDL_Window*)
{
}

void Combat_Scene::draw()
{	//draw background
	SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
}
