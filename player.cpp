#pragma once

#include "player.h"
#include "tile.h"
//#include "sound.h"

#include <iostream>

#include <SDL_mixer.h>

Player::Player(std::string id)
	: Game_Object(id, "Texture.Player.Idle")
{
	_speed = 0.1f;

	_translation = Vector_2D(300,200);

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));

	_state.push(State::Idle);
}
Player::~Player()
{
}

void Player::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config, scene);
}

void Player::simulate_physics(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene)
{
	Game_Object::simulate_physics(milliseconds_to_simulate, assets, scene);

	for (Game_Object* game_object : scene->get_game_objects())
	{
		if (game_object->id() == _id)
		{
			continue;
		}
		if (game_object->id().find("Tile") != std::string::npos)
		{
			Tile* tile = (Tile*)game_object;
			if (tile->get_type() == 0)
			{
				continue;
			}
			Circle_2D collider = Circle_2D(_collider.radius(), _collider.translation() + _translation);
			Circle_2D other_collider = Circle_2D(game_object->collider().radius(), game_object->collider().translation() + game_object->translation());
			float intersection_depth = collider.intersection_depth(other_collider);

			if (intersection_depth > 0.0f)
			{
				Vector_2D other_collider_to_collider = collider.translation() - other_collider.translation();
				other_collider_to_collider.normalize();
				other_collider_to_collider.scale(intersection_depth);
				_translation += other_collider_to_collider;

			}
		}
		else if (game_object->id().find("Tree") != std::string::npos)
		{
			Circle_2D collider = Circle_2D(_collider.radius(), _collider.translation() + _translation);
			Circle_2D other_collider = Circle_2D(game_object->collider().radius(), game_object->collider().translation() + game_object->translation());
			float intersection_depth = collider.intersection_depth(other_collider);

			if (intersection_depth > 0.0f)
			{
				Vector_2D other_collider_to_collider = collider.translation() - other_collider.translation();
				other_collider_to_collider.normalize();
				other_collider_to_collider.scale(intersection_depth);
				_translation += other_collider_to_collider;
			}
		}
		else if (game_object->id().find("Diamond") != std::string::npos)
		{
			Circle_2D collider = Circle_2D(_collider.radius(), _collider.translation() + _translation);
			Circle_2D other_collider = Circle_2D(game_object->collider().radius(), game_object->collider().translation() + game_object->translation());
			float intersection_depth = collider.intersection_depth(other_collider);

			if (intersection_depth > 0.0f)
			{
				scene->win();
			}
		}
	}
}

void Player::simulate_AI(Uint32, Assets* assets, Input* input, Scene*)
{
	switch (_state.top())
	{
	case State::Idle:
		if (input->is_button_state(Input::Button::RUNNING, Input::Button_State::DOWN) && _velocity.magnitude() > 0.0f)
		{
			push_state(State::Running, assets);
		}
		else if (input->is_button_state(Input::Button::LEFT, Input::Button_State::DOWN) || input->is_button_state(Input::Button::RIGHT, Input::Button_State::DOWN) && _velocity.magnitude() > 0.0f)
		{
			push_state(State::Walking, assets);
		}
		else if (input->is_button_state(Input::Button::UP, Input::Button_State::DOWN) && _velocity.magnitude() > 0.0f)
		{
			push_state(State::WalkingUp, assets);
		}
		else if (input->is_button_state(Input::Button::DOWN, Input::Button_State::DOWN) && _velocity.magnitude() > 0.0f)
		{
			push_state(State::WalkingDown, assets);
		}
		break;
	case State::Walking:
		if (_velocity.magnitude() == 0.0f)
		{
			pop_state(assets);
		}
		else if (input->is_button_state(Input::Button::RUNNING, Input::Button_State::PRESSED))
		{
			push_state(State::Running, assets);
		}
		break;
	case State::WalkingUp:
		if (_velocity.magnitude() == 0.0f)
		{
			pop_state(assets);
		}
		else if (input->is_button_state(Input::Button::RUNNING, Input::Button_State::PRESSED))
		{
			push_state(State::Running, assets);
		}
		break;
	case State::WalkingDown:
		if (_velocity.magnitude() == 0.0f)
		{
			pop_state(assets);
		}
		else if (input->is_button_state(Input::Button::RUNNING, Input::Button_State::PRESSED))
		{
			push_state(State::Running, assets);
		}
		break;
	case State::Running:
		if (_velocity.magnitude() == 0.0f)
		{
			pop_state(assets);
		}
		else if (input->is_button_state(Input::Button::RUNNING, Input::Button_State::RELEASED))
		{
			pop_state(assets);
		}
		break;
	}

	_velocity = Vector_2D(0, 0);

	if (input->is_button_state(Input::Button::RIGHT, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(1.0f, 0);
	}

	if (input->is_button_state(Input::Button::LEFT, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(-1.0f, 0);
	}

	if (input->is_button_state(Input::Button::UP, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(0, -1.0f);
	}

	if (input->is_button_state(Input::Button::DOWN, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(0, 1.0f);
	}

	_velocity.normalize();
	_velocity.scale(_speed);
}

void Player::set_speed(float speed)
{
	_speed = speed;
}
float Player::speed()
{
	return _speed;
}

void Player::push_state(State state, Assets* assets)
{
	handle_exit_state(_state.top(), assets);

	_state.push(state);
	handle_enter_state(_state.top(), assets);
}
void Player::pop_state(Assets* assets)
{
	handle_exit_state(_state.top(), assets);

	_state.pop();
	handle_enter_state(_state.top(), assets);
}




void Player::handle_enter_state(State state, Assets* assets)
{
	switch (state)
	{
	case State::Idle:
		_texture_id = "Texture.Player.Idle";
		break;
	case State::Walking:
	{
		_texture_id = "Texture.Player.Walking";
		_speed = 0.15f;
		/*const int walking_channel = 1;
		Sound* sound = (Sound*)assets->get_asset("Sound.Walking");
		Mix_PlayChannel(walking_channel, sound->data(), -1);*/
		break;
	}
	case State::WalkingUp:
	{
		_texture_id = "Texture.Player.Walking.Up";
		_speed = 0.15f;
		/*const int walking_channel = 1;
		Sound* sound = (Sound*)assets->get_asset("Sound.Walking");
		Mix_PlayChannel(walking_channel, sound->data(), -1);*/
		break;
	}

	case State::WalkingDown:
	{
		_texture_id = "Texture.Player.Walking.Down";
		_speed = 0.15f;
		/*const int walking_channel = 1;
		Sound* sound = (Sound*)assets->get_asset("Sound.Walking");
		Mix_PlayChannel(walking_channel, sound->data(), -1);*/
		break;
	}
	case State::Running:
	{
		_texture_id = "Texture.Player.Running";
		_speed = 0.3f;
	/*	const int running_channel = 2;
		Sound* sound = (Sound*)assets->get_asset("Sound.Running");
		Mix_PlayChannel(running_channel, sound->data(), -1);*/
		break;
	}
	}
}

void Player::handle_exit_state(State state, Assets*)
{
	switch (state)
	{
	case State::Idle:
		break;
	case State::Walking:
	{
		/*const int walking_channel = 1;
		Mix_HaltChannel(walking_channel);*/
		break;
	}
	case State::Running:
	{
		/*const int running_channel = 2;
		Mix_HaltChannel(running_channel);*/
		break;
	}
	}
}