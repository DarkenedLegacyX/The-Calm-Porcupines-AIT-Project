#include "tile.h"
#include "texture.h"
#include "vector_2D.h"

Tile::Tile(std::string id, std::string texture_id, Vector_2D translation, int scale, int type)
	: Game_Object(id, texture_id)
{
	_translation = translation;
	_width = scale;
	_height = scale;
	_collider.set_radius(_width / 2.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height / 1.5f));
	_type = type;
	_active = false;
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

void Tile::activate_tile()
{
	_active = true;
}

void Tile::deactivate_tile()
{
	_active = false;
}

bool Tile::is_active()
{
	return _active;
}




