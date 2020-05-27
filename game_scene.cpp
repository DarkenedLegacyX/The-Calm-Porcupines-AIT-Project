#include "game_scene.h"
#include "player.h"
#include "tile.h"
#include <iostream>

Game_Scene::Game_Scene()
	: Scene("Game")
{
	int tiles_x = 16;
	int tiles_y = 16;
	int tile_scale = 100;
	int map[16][16] = { {1, 1, 1, 13, 11, 2, 1, 1, 1, 1, 1, 13, 11, 2, 1, 1},
		{1, 1, 13, 10, 0, 3, 11, 11, 11, 11, 2, 9, 0, 4, 1, 1 },
		{1, 1, 9, 0, 0, 0, 0, 0, 0, 0, 3, 10, 0, 3, 2, 1},
		{1, 1, 8, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1},
		{1, 1, 1, 8, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1},
		{1, 1, 1, 1, 8, 12, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1},
		{1, 1, 1, 13, 11, 10, 0, 0, 0, 0, 0, 0, 0, 7, 5, 1},
		{1, 1, 13, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 1},
		{13, 11, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 5, 1, 1},
		{9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 6, 5, 1, 1, 1},
		{9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 11, 11, 11, 2, 1},
		{9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1},
		{9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2},
		{8, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 12, 0, 0, 4},
		{1, 9, 0, 0, 0, 7, 12, 0, 0, 7, 6, 5, 9, 0, 0, 4},
		{1, 8, 6, 6, 6, 5, 8, 6, 6, 5, 1, 1, 8, 6, 6, 5}};
	//Temporary to make it smooth for now.
	for (int y = 0; y < 8; ++y)
	{
		for (int x = 0; x < 8; ++x)
		{
			std::string id = "Tile.X." + std::to_string(x) + ".Y." + std::to_string(y);
			std::string texture_id = "";

			texture_id = "Texture.Tile" + std::to_string(map[y][x]);

			Tile* tile = new Tile(
				id, texture_id,
				Vector_2D((float)x * (float)tile_scale, (float)y * (float)tile_scale),
				tile_scale, map[y][x]);
			_game_objects[tile->id()] = tile;
		}
	}
	/*
	Game_Object* dino = new Dino("Dino");
	_game_objects[dino->id()] = dino;

	Game_Object* dino_walking = new Walking_Dino("Dino.Walking");
	_game_objects[dino_walking->id()] = dino_walking;

	Game_Object* player = new Player("Player");
	_game_objects[player->id()] = player;

	Game_Object* portal_entry = new Portal_Entry();
	_game_objects[portal_entry->id()] = portal_entry;

	Game_Object* portal_exit = new Portal_Exit();
	_game_objects[portal_exit->id()] = portal_exit;
	*/


	add_game_object(new Player("Player"));

}

Game_Scene::~Game_Scene()
{
}

void Game_Scene::update(SDL_Window* window)
{
	Game_Object* player = get_game_object("Player");

	const int border = 350;
	const int lower_border = 1600-450;
	int w, h;
	int movex = player->translation().x();
	int movey = player->translation().y();
	movex = player->translation().x();
	movey = player->translation().y();
	//std::cout << movex;
	SDL_GetWindowSize(window, &w, &h);
//	if(player->translation().x() >= 350 && player->translation().x() >= 350)
//		_camera_translation = Vector_2D(-w / 2.f + player->width() / 2.f, -h / 2.f + player->height() / 2.f) + player->translation();
	if (movex < border)
		movex = border;
	else if (movex > lower_border)
		movex = lower_border;
	if (movey < border)
		movey = border;
	else if (movey > lower_border)
		movey = lower_border;


	_camera_translation = Vector_2D(-w / 2.f + player->width() / 2.f, -h / 2.f + player->height() / 2.f) + Vector_2D(movex, movey);
}