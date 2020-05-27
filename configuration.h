#pragma once

struct Configuration
{
	bool should_display_ids = false;
	bool should_display_colliders = false;

	int window_width = 800;
	int window_height = 800;

	//The dimensions of the level
	const int LEVEL_WIDTH = 1600;
	const int LEVEL_HEIGHT = 1600;

	//Tile constants
	const int TILE_WIDTH = 100;
	const int TILE_HEIGHT = 100;
	const int TOTAL_TILES = 256;
	const int TOTAL_TILE_SPRITES = 14;

	//The different tile sprites
	const int TILE_GREEN = 0;
	const int TILE_BLUE = 1;
	const int TILE_BOTTOMLEFT_COR = 2;
	const int TILE_LEFTDOWN = 3;
	const int TILE_LEFT = 4;
	const int TILE_TOPLEFT_COR = 5;
	const int TILE_TOP = 6;
	const int TILE_TOPLEFT = 7;
	const int TILE_TOPRIGHT_COR = 8;
	const int TILE_RIGHT = 9;
	const int TILE_BOTTOMRIGHT = 10;
	const int TILE_BOTTOM = 11;
	const int TILE_TOPRIGHT = 12;
	const int TILE_BOTTOMRIGHT_COR = 13;
};