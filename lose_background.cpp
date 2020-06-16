#include "menu_background.h"
#include "input.h"
#include "lose_background.h"

Lose_Background::Lose_Background(std::string id)
	: Game_Object(id, "Texture.Lose")
{
	_translation = Vector_2D(0, 0);
	_width = 800;
	_height = 800;
}

Lose_Background::~Lose_Background()
{
}

void Lose_Background::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}


