#include "tile.h"
#include "texture.h"
#include "vector_2D.h"

Tile::Tile(std::string id, std::string texture_id, Vector_2D translation, int scale, int type)
	: Game_Object(id, texture_id)
{
	_translation = translation;
	_width = scale;
	_height = scale;
	_collider.x = translation.x();
	_collider.y = translation.y();
	_collider.w = scale;
	_collider.h = scale;
	_type = type;
}
Tile::~Tile()
{
}
void Tile::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}

int Tile::get_type()
{
	return _type;
}

SDL_Rect Tile::get_collider()
{
	return _collider;
}



