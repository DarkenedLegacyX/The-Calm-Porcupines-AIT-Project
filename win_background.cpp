#include "input.h"
#include "win_background.h"

Win_Background::Win_Background(std::string id)
	: Game_Object(id, "Texture.Win")
{
	_translation = Vector_2D(0, 0);
	_width = 800;
	_height = 800;
}

Win_Background::~Win_Background()
{
}

void Win_Background::simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene)
{
}
