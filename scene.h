#pragma once

#include <map>
#include <string>
#include <vector>

#include <SDL.h>
#include "vector_2D.h"
#include "text.h"

class Game_Object;

class Scene
{
public:
	Scene(std::string id);
	~Scene();

	virtual void update(SDL_Window* window) = 0;

	Game_Object* get_game_object(std::string id);
	std::vector<Game_Object*> get_game_objects();

	void add_game_object(Game_Object* game_object);
	void remove_game_object(std::string id);

	Vector_2D camera_translation();

	std::string id();

	SDL_Color background_color();

	bool is_won();
	void win();

protected:
	std::map<std::string, Game_Object*> _game_objects;
	std::string                         _id;
	Vector_2D                           _camera_translation;
	SDL_Color                           _background_color;
	bool								_game_win;
};