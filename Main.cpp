#include <iostream>
#include <chrono>
#include <thread>
#include <stack>

#include "engine.h"
#include "assets.h"
#include "game_scene.h"
#include "combat_scene.h"
#include "input.h"
#include "configuration.h"
#include "menu_scene.h"
#include "win_scene.h"
#include "pause_scene.h"
#include "lose_scene.h"
#include "player_fight.h"
#include <ctime>
#include <random>



int main(void)
{
	Configuration* config = new Configuration();
	Engine* engine = new Engine("ShatteredLegend", config);
	Assets* assets = new Assets(engine->renderer());
	Input* input = new Input();

	std::stack<Scene*> scenes;
	scenes.push(new Menu_Scene());

	const Uint32 milliseconds_per_seconds = 1000;
	const Uint32 frames_per_second = 60;
	const Uint32 frame_time_ms = milliseconds_per_seconds / frames_per_second;

	bool is_played = false;
	bool in_combat = false;
	bool end_game = false;
	clock_t start;
	double duration;
	int seed = 1337;
	std::minstd_rand0 generator(seed);
	int turn = 1;
	int enemy_hp;
	int player_hp;
	int r;



	Uint32 frame_start_time_ms = 0;
	Uint32 frame_end_time_ms = frame_time_ms;
	while (!input->is_button_state(Input::Button::QUIT, Input::Button_State::PRESSED))
	{
			Uint32 previous_frame_duration = frame_end_time_ms - frame_start_time_ms;
			frame_start_time_ms = SDL_GetTicks();
			input->get_input();
			if (input->is_button_state(Input::Button::SPACE, Input::Button_State::PRESSED) && is_played == false)
			{
				std::cout << "Play" << std::endl;
				is_played = true;
				scenes.push(new Game_Scene);
				player_hp = 100;
				std::cout << "You have " << player_hp << " Health!" << std::endl;
			}

			if (is_played && scenes.top()->is_won())
			{
				std::cout << "Win!" << std::endl;
				end_game = true;
				scenes.push(new Win_Scene);
			}
			if (input->is_button_state(Input::Button::SPACE, Input::Button_State::PRESSED) && end_game == true)
			{
				std::cout << "Returning to menu" << std::endl;
				end_game = false;
				is_played = false;
				scenes.push(new Menu_Scene());
			}
			if (input->is_button_state(Input::Button::PAUSE, Input::Button_State::PRESSED) && is_played == true)
			{
				in_combat = true;
				const bool is_paused = scenes.top()->id() == "Pause";
				std::cout << "pause" << std::endl;
				if (is_paused)
				{
					Pause_Scene* pause_scene = (Pause_Scene*)scenes.top();
					scenes.pop();
					delete pause_scene;
					in_combat = false;
				}
				else
				{
					scenes.push(new Pause_Scene);
					
				}
			}


			if (input->is_button_state(Input::Button::COMBAT, Input::Button_State::PRESSED) && is_played == true)
					{
						std::cout << "BATTLE!" << std::endl;
						in_combat = true;
						enemy_hp = 50;
						const bool is_paused = scenes.top()->id() == "Combat";
						if (is_paused)
						{
							Combat_Scene* combat_scene = (Combat_Scene*)scenes.top();
							scenes.pop();
							delete combat_scene;
							in_combat = false;
						}
						else
						{
							scenes.push(new Combat_Scene);
						}
			}

			if (input->is_button_state(Input::Button::UP, Input::Button_State::PRESSED) && is_played == true && in_combat == false && end_game == false) {
				start = clock();
			}
			if (input->is_button_state(Input::Button::UP, Input::Button_State::RELEASED) && is_played == true && in_combat == false && end_game == false) {
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				std::cout << "Button Held duration: " << duration << '\n';


				if (duration > 0.75) {
					float random_number = (float)generator() / generator.max();
					if (random_number > 0.75) {
					std::cout << "BATTLE!!!!!!!!" << std::endl;
					in_combat = true;
					enemy_hp = 50;
					const bool is_paused = scenes.top()->id() == "Combat";
					if (is_paused)
					{
						Combat_Scene* combat_scene = (Combat_Scene*)scenes.top();
						scenes.pop();
						delete combat_scene;
						in_combat = false;
					}
					else
					{
						scenes.push(new Combat_Scene);
					}
					}
					else {
						std::cout << "No Battle." << std::endl;
					}
				}
				else {
					std::cout << "Button not held on long enough to proc RNG" << std::endl;
				}
			}

			if (input->is_button_state(Input::Button::DOWN, Input::Button_State::PRESSED) && is_played == true && in_combat == false && end_game == false) {
				start = clock();
			}
			if (input->is_button_state(Input::Button::DOWN, Input::Button_State::RELEASED) && is_played == true && in_combat == false && end_game == false) {
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				std::cout << "Button Held duration: " << duration << '\n';


				if (duration > 0.75) {
					float random_number = (float)generator() / generator.max();
					if (random_number > 0.75) {
						std::cout << "BATTLE!!!!!!!!" << std::endl;
						in_combat = true;
						enemy_hp = 50;
						const bool is_paused = scenes.top()->id() == "Combat";
						if (is_paused)
						{
							Combat_Scene* combat_scene = (Combat_Scene*)scenes.top();
							scenes.pop();
							delete combat_scene;
							in_combat = false;
						}
						else
						{
							scenes.push(new Combat_Scene);
						}
					}
					else {
						std::cout << "No Battle." << std::endl;
					}
				}
				else {
					std::cout << "Button not held on long enough to proc RNG" << std::endl;
				}
			}

			if (input->is_button_state(Input::Button::LEFT, Input::Button_State::PRESSED) && is_played == true && in_combat == false && end_game == false) {
				start = clock();
			}
			if (input->is_button_state(Input::Button::LEFT, Input::Button_State::RELEASED) && is_played == true && in_combat == false && end_game == false) {
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				std::cout << "Button Held duration: " << duration << '\n';


				if (duration > 0.75) {
					float random_number = (float)generator() / generator.max();
					if (random_number > 0.75) {
						std::cout << "BATTLE!!!!!!!!" << std::endl;
						in_combat = true;
						enemy_hp = 50;
						const bool is_paused = scenes.top()->id() == "Combat";
						if (is_paused)
						{
							Combat_Scene* combat_scene = (Combat_Scene*)scenes.top();
							scenes.pop();
							delete combat_scene;
							in_combat = false;
						}
						else
						{
							scenes.push(new Combat_Scene);
						}
					}
					else {
						std::cout << "No Battle." << std::endl;
					}
				}
				else {
					std::cout << "Button not held on long enough to proc RNG" << std::endl;
				}
			}

			if (input->is_button_state(Input::Button::RIGHT, Input::Button_State::PRESSED) && is_played == true && in_combat == false && end_game == false) {
				start = clock();
			}
			if (input->is_button_state(Input::Button::RIGHT, Input::Button_State::RELEASED) && is_played == true && in_combat == false && end_game == false) {
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				std::cout << "Button Held duration: " << duration << '\n';


				if (duration > 0.75) {
					float random_number = (float)generator() / generator.max();
					if (random_number > 0.75) {
						std::cout << "BATTLE!!!!!!!!" << std::endl;
						in_combat = true;
						enemy_hp = 50;
						const bool is_paused = scenes.top()->id() == "Combat";
						if (is_paused)
						{
							Combat_Scene* combat_scene = (Combat_Scene*)scenes.top();
							scenes.pop();
							delete combat_scene;
							in_combat = false;
						}
						else
						{
							scenes.push(new Combat_Scene);
						}
					}
					else{
						std::cout << "No Battle." << std::endl;
					}
				}
				else {
					std::cout << "Button not held on long enough to proc RNG" << std::endl;
				}
			}

			if (input->is_button_state(Input::Button::SPACE, Input::Button_State::PRESSED) && turn == 1 && in_combat == true) {
				if (player_hp <= 0 && in_combat == true) {
					std::cout << "You Lose " << std::endl;
					in_combat = false;
					end_game = true;
					scenes.push(new Lose_Scene);
				}
				else {
					r = rand() % 25 + 1;
					std::cout << "Enemy has taken " << r << " damage!" << std::endl;
					enemy_hp = enemy_hp - r;
					std::cout << "Enemy has " << enemy_hp << " HP!" << std::endl;
					turn = 2;
				}
			}

			if (turn == 2 && in_combat == true) {
				if (enemy_hp <= 0 && in_combat == true) {
					std::cout << "You win " << std::endl;
					Combat_Scene* combat_scene = (Combat_Scene*)scenes.top();
					scenes.pop();
					delete combat_scene;
					in_combat = false;
					turn = 1;
				}
				else {
					r = rand() % 25 + 1;
					std::cout << "You have taken " << r << " damage!" << std::endl;
					player_hp = player_hp - r;
					std::cout << "You have " << player_hp << " hp!" << std::endl;
					turn = 1;
				}
			}



			scenes.top()->update(engine->window());
			engine->simulate(previous_frame_duration, assets, scenes.top(), input, config);

			const Uint32 current_time_ms = SDL_GetTicks();
			const Uint32 frame_duration_ms = current_time_ms - frame_start_time_ms;
			if (frame_duration_ms < frame_time_ms)
			{
				const Uint32 time_to_sleep_for = frame_time_ms - frame_duration_ms;
				std::this_thread::sleep_for(std::chrono::milliseconds(time_to_sleep_for));
			}		
			frame_end_time_ms = SDL_GetTicks();
	}
		return 0;
}
