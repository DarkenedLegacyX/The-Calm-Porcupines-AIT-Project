#include "enemy.h"
#include <iostream>

Enemy::Enemy(std::string id)
	: Game_Object(id, "Texture.Enemy.Idle")
{
	_translation = Vector_2D(525, 550);
	_velocity = Vector_2D(0, 0);
	_width = 150;
	_height = 150;
	_state.push(State::Idle);
}

Enemy::~Enemy()
{
}

void Enemy::simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene)
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

void Enemy::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config, scene);
}

void Enemy::push_state(State state, Assets* assets)
{
	_state.push(state);
	handle_enter_state(_state.top(), assets);
}

void Enemy::pop_state(Assets* assets)
{
	_state.pop();
	handle_enter_state(_state.top(), assets);
}

void Enemy::handle_enter_state(State state, Assets* assets)
{
	switch (state)
	{
	case State::Idle:
		_texture_id = "Texture.Enemy.Idle";
		break;
	case State::Attack:
		_texture_id = "Texture.Enemy.Attack";
		break;
	}
}

void Enemy::handle_exit_state(State state, Assets* assets)
{
	switch (state)
	{
	case State::Idle:
		break;
	case State::Attack:
		break;
	}
}

