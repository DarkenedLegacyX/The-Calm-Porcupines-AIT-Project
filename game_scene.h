#pragma once

#include "scene.h"
#include "tile.h"

class Game_Scene : public Scene
{
public:
	Game_Scene();
	~Game_Scene();

	virtual void update(SDL_Window* window) override;

private:
	void update_map();
	void delete_tiles();
	std::map<std::string, Tile*> _map_tiles;
	int _tile_scale;
};