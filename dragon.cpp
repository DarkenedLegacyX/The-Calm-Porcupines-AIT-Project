#include "dragon.h"

Dragon::Dragon(std::string id)
	: Game_Object(id, "Texture.Dragon")
{
	_translation = Vector_2D(300, 100);
	_velocity = Vector_2D(0, 0);
	_width = 220;
	_height = 200;
}
Dragon::~Dragon()
{
}

void Dragon::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}

void Dragon::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config, scene);
}

