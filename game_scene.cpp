#include "game_scene.h"
#include "player.h"
#include "tile.h"
#include "tree.h"
#include <iostream>
#include <time.h>  

Game_Scene::Game_Scene()
	: Scene("Game")
{
	srand(time(NULL));
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
	
	int number_trees = 20;
	Vector_2D tree_vectors[] = { Vector_2D(650, 500), Vector_2D(950, 700), Vector_2D(750, 200), Vector_2D(1050, 400),Vector_2D(1050, 1050),
		Vector_2D(850, 900), Vector_2D(900, 1200), Vector_2D(350, 800),Vector_2D(750, 1100), Vector_2D(500, 300), Vector_2D(150, 1100),
		Vector_2D(850, 600),Vector_2D(1150, 300), Vector_2D(600, 800), Vector_2D(250, 1200), Vector_2D(1300, 1100),Vector_2D(350,1000),
		Vector_2D(720, 1350), Vector_2D(400,80), Vector_2D(1200 , 650) };

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

	int r;
	for (int i = 0; i < number_trees; ++i)
	{
		r = rand() % 4 + 1;
		add_game_object(new Tree("Tree" + std::to_string(i), "Texture.Tree" + std::to_string(r), tree_vectors[i], 100));
	}
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
	float move_player_x = player->translation().x();
	float move_player_y = player->translation().y();
	move_player_x = player->translation().x();
	move_player_y = player->translation().y();

	// std::cout << move_player_x << "           " << move_player_y << std::endl;

	SDL_GetWindowSize(window, &w, &h);
	if(player->translation().x() >= 350 && player->translation().x() >= 350)
		_camera_translation = Vector_2D(-w / 2.f + player->width() / 2.f, -h / 2.f + player->height() / 2.f) + player->translation();
	if (move_player_x < border)
		move_player_x = border;
	else if (move_player_x > lower_border)
		move_player_x = lower_border;
	if (move_player_y < border)
		move_player_y = border;
	else if (move_player_y > lower_border)
		move_player_y = lower_border;


	_camera_translation = Vector_2D(-w / 2.f + player->width() / 2.f, -h / 2.f + player->height() / 2.f) + Vector_2D(move_player_x, move_player_y);
	update_map();
	delete_tiles();
}

void Game_Scene::update_map()
{
	for (auto key_value : _map_tiles)
	{
		if (key_value.second == nullptr)
		{
			continue;
		}
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
		if (game_object->id().find("Tile") == std::string::npos)
		{
			continue;
		}
		if( (game_object->translation().x() - _camera_translation.x() < -100) || 
			(game_object->translation().x() - _camera_translation.x() > 800) || 
			(game_object->translation().y() - _camera_translation.y() < -100) ||
			(game_object->translation().y() - _camera_translation.y() > 800)
			)
		{
			remove_game_object(game_object->id());
			if (_map_tiles[game_object->id()] != nullptr)
			{
				_map_tiles[game_object->id()]->deactivate_tile();
			}
		}
	}
}

