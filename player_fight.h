#pragma once
#include "game_object.h"
#include <stack>

class Player_Fight : public Game_Object
{
public:

	Player_Fight(std::string id);
	~Player_Fight();

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