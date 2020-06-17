#include "combat_scene.h"
#include "combat_background.h"
#include "player_fight.h"
#include "enemy.h"
#include "input.h"
#include <SDL_image.h>
#include <iostream>

Combat_Scene::Combat_Scene()
	: Scene("Combat")
{

	add_game_object(new Enemy("Enemy"));
	add_game_object(new Player_Fight("Player_Fight"));
	add_game_object(new Combat_Background("Combat"));

}


Combat_Scene::~Combat_Scene()
{
}

void Combat_Scene::update(SDL_Window*)
{

}



