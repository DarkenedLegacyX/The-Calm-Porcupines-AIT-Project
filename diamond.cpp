#include "diamond.h"

Diamond::Diamond(std::string id, std::string texture_id, Vector_2D translation, int scale)
	: Game_Object(id, texture_id)
{
	_translation = translation;
	_width = scale;
	_height = scale;
	_collider.set_radius(_width / 3.5f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height / 1.5f));
}

Diamond::~Diamond()
{
}

void Diamond::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}
