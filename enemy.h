#pragma once
#include "game_object.h"
#include <stack>

class Enemy : public Game_Object
{
public:

	Enemy(std::string id);
	~Enemy();


	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
	virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene) override;

	enum class State
	{
		Idle,
		Attack
	};

	void push_state(State state, Assets* assets);
	void pop_state(Assets* assets);

private:
	void handle_enter_state(State state, Assets* assets);
	void handle_exit_state(State state, Assets* assets);

	std::stack<State> _state;

};