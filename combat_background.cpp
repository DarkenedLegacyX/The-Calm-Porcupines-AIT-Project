#include "menu_background.h"
#include "text.h"
#include "combat_background.h"

Combat_Background::Combat_Background(std::string id) : Game_Object(id, "Texture.Combat")
{
	_translation = Vector_2D(0, 0);
	_width = 800;
	_height = 800;
}

Combat_Background::~Combat_Background()
{
}

void Combat_Background::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}
