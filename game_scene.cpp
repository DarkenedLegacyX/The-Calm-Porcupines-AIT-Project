#include "game_scene.h"
#include "player.h"
#include "tile.h"
#include <iostream>

Game_Scene::Game_Scene()
	: Scene("Game")
{

	_tile_scale = 100;
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
	for (int y = 0; y < 16; ++y)
	{
		for (int x = 0; x < 16; ++x)
		{
			std::string id = "Tile.X." + std::to_string(x) + ".Y." + std::to_string(y);
			std::string texture_id = "";

			texture_id = "Texture.Tile" + std::to_string(map[y][x]);

			Tile* tile = new Tile(
				id, texture_id,
				Vector_2D((float)x * (float)_tile_scale, (float)y * (float)_tile_scale),
				_tile_scale, map[y][x]);
			_map_tiles[tile->id()] = tile;
			
		}
	}
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
	float movex = player->translation().x();
	float movey = player->translation().y();
	movex = player->translation().x();
	movey = player->translation().y();

	SDL_GetWindowSize(window, &w, &h);
	if(player->translation().x() >= 350 && player->translation().x() >= 350)
		_camera_translation = Vector_2D(-w / 2.f + player->width() / 2.f, -h / 2.f + player->height() / 2.f) + player->translation();
	if (movex < border)
		movex = border;
	else if (movex > lower_border)
		movex = lower_border;
	if (movey < border)
		movey = border;
	else if (movey > lower_border)
		movey = lower_border;


	_camera_translation = Vector_2D(-w / 2.f + player->width() / 2.f, -h / 2.f + player->height() / 2.f) + Vector_2D(movex, movey);
	update_map();
	delete_tiles();
}

void Game_Scene::update_map()
{
	for (auto key_value : _map_tiles)
	{
		if (key_value.second->is_active())
		{
			continue;
		}
		if ((key_value.second->translation().x() - _camera_translation.x() > -100) &&
			(key_value.second->translation().x() - _camera_translation.x() < 800) &&
			(key_value.second->translation().y() - _camera_translation.y() > -100) &&
			(key_value.second->translation().y() - _camera_translation.y() < 800)
			)
		{
			key_value.second->activate_tile();
			add_game_object(key_value.second);
		}
	}
}

void Game_Scene::delete_tiles()
{
	for (Game_Object* game_object : get_game_objects())
	{
		if( (game_object->translation().x() - _camera_translation.x() < -100) || 
			(game_object->translation().x() - _camera_translation.x() > 800) || 
			(game_object->translation().y() - _camera_translation.y() < -100) ||
			(game_object->translation().y() - _camera_translation.y() > 800)
			)
		{
			remove_game_object(game_object->id());
			_map_tiles[game_object->id()]->deactivate_tile();
		}
	}
}

