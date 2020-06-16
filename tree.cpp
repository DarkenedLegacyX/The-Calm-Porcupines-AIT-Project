#include "tree.h"

Tree::Tree(std::string id, std::string texture_id, Vector_2D translation, int scale)
	: Game_Object(id, texture_id)
{
	_translation = translation;
	_width = 98 * scale/100;
	_height = 145 * scale / 100;
	_collider.set_radius(_width / 3.5f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height / 1.5f + 20.0f));
}

Tree::~Tree()
{
}

void Tree::simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene)
{
}
