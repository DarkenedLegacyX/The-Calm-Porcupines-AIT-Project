#include "player_dead.h"

Player_Dead::Player_Dead(std::string id)
	: Game_Object(id, "Texture.Player.Dead")
	{
		_translation = Vector_2D(300, 100);
		_velocity = Vector_2D(0, 0);
		_width = 200;
		_height = 200;
}

Player_Dead::~Player_Dead()
{
}

void Player_Dead::simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene)
{
}

void Player_Dead::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config, scene);
}
