#include "player_fight.h"
#include <iostream>

Player_Fight::Player_Fight(std::string id)
	: Game_Object(id, "Texture.Player.Fight")
{
	_translation = Vector_2D(125, 560);
	_velocity = Vector_2D(0, 0);
	_width = 150;
	_height = 150;
	_state.push(State::Idle);
}

Player_Fight::~Player_Fight()
{
}

void Player_Fight::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config, scene);

}

void Player_Fight::push_state(State state, Assets* assets)
{
	handle_exit_state(_state.top(), assets);

	_state.push(state);
	handle_enter_state(_state.top(), assets);
}

void Player_Fight::pop_state(Assets* assets)
{
	handle_exit_state(_state.top(), assets);

	_state.pop();
	handle_enter_state(_state.top(), assets);
}



void Player_Fight::simulate_AI(Uint32, Assets* assets, Input* input, Scene*)
{
	switch (_state.top())
	{
	case State::Idle:
		if (input->is_button_state(Input::Button::SPACE, Input::Button_State::PRESSED))
		{
			push_state(State::Attack, assets);
		}
	case State::Attack:
		if (input->is_button_state(Input::Button::SPACE, Input::Button_State::RELEASED))
		{
			pop_state(assets);
		}
	}

}

void Player_Fight::handle_enter_state(State state, Assets* assets)
{
	switch (state)
	{
	case State::Idle:
		_texture_id = "Texture.Player.Fight";
		break;
	case State::Attack:
		_texture_id = "Texture.Player.Attack";
		break;
	}
}

void Player_Fight::handle_exit_state(State state, Assets* assets)
{
	switch (state)
	{
	case State::Idle:
		break;
	case State::Attack:
		break;
	}
}
