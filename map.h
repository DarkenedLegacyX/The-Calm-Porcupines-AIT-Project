#pragma once
#include "tile.h"


class Map
{
public:
	Map();
	void renderMap();
private:
	Tile tileset[256];
};

