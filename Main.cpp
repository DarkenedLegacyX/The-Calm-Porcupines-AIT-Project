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
#include "pause_scene.h"
#include <ctime>
#include <random>



int main(void)
{
	Configuration* config = new Configuration();
	Engine* engine = new Engine("Game", config);
	Assets* assets = new Assets(engine->renderer());
	Input* input = new Input();

	std::stack<Scene*> scenes;
	scenes.push(new Menu_Scene());

	const Uint32 milliseconds_per_seconds = 1000;
	const Uint32 frames_per_second = 60;
	const Uint32 frame_time_ms = milliseconds_per_seconds / frames_per_second;

	bool is_played = false;
	bool in_combat = false;
	clock_t start;
	double duration;
	int seed = 1337;
	std::minstd_rand0 generator(seed);


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
			}

			if (input->is_button_state(Input::Button::PAUSE, Input::Button_State::PRESSED) && is_played == true)
			{
				const bool is_paused = scenes.top()->id() == "Pause";
				std::cout << "pause" << std::endl;
				if (is_paused)
				{
					Pause_Scene* pause_scene = (Pause_Scene*)scenes.top();
					scenes.pop();
					delete pause_scene;
					in_combat = true;
				}
				else
				{
					scenes.push(new Pause_Scene);
					
				}
			}	

			if (input->is_button_state(Input::Button::COMBAT, Input::Button_State::PRESSED) && is_played == true)
					{
						in_combat = true;
						const bool is_paused = scenes.top()->id() == "Combat";
						std::cout << "Battle" << std::endl;
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

			if (input->is_button_state(Input::Button::UP, Input::Button_State::PRESSED) && is_played == true && in_combat == false) {
				std::cout << "Test" << std::endl;
				start = clock();

			}
			if (input->is_button_state(Input::Button::UP, Input::Button_State::RELEASED) && is_played == true && in_combat == false) {
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				std::cout << "end" << std::endl;
				std::cout << "Button Held duration: " << duration << '\n';


				if (duration > 0.75) {
					float random_number = (float)generator() / generator.max();
					if (random_number > 0.75) {
					std::cout << "BATTLE!!!!!!!!" << std::endl;
					in_combat = true;
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

			if (input->is_button_state(Input::Button::DOWN, Input::Button_State::PRESSED) && is_played == true && in_combat == false) {
				std::cout << "Test" << std::endl;
				start = clock();

			}
			if (input->is_button_state(Input::Button::DOWN, Input::Button_State::RELEASED) && is_played == true && in_combat == false) {
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				std::cout << "end" << std::endl;
				std::cout << "Button Held duration: " << duration << '\n';


				if (duration > 0.75) {
					float random_number = (float)generator() / generator.max();
					if (random_number > 0.75) {
						std::cout << "BATTLE!!!!!!!!" << std::endl;
						in_combat = true;
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

			if (input->is_button_state(Input::Button::LEFT, Input::Button_State::PRESSED) && is_played == true && in_combat == false) {
				std::cout << "Test" << std::endl;
				start = clock();

			}
			if (input->is_button_state(Input::Button::LEFT, Input::Button_State::RELEASED) && is_played == true && in_combat == false) {
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				std::cout << "end" << std::endl;
				std::cout << "Button Held duration: " << duration << '\n';


				if (duration > 0.75) {
					float random_number = (float)generator() / generator.max();
					if (random_number > 0.75) {
						std::cout << "BATTLE!!!!!!!!" << std::endl;
						in_combat = true;
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

			if (input->is_button_state(Input::Button::RIGHT, Input::Button_State::PRESSED) && is_played == true && in_combat == false) {
				std::cout << "Test" << std::endl;
				start = clock();

			}
			if (input->is_button_state(Input::Button::RIGHT, Input::Button_State::RELEASED) && is_played == true && in_combat == false) {
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				std::cout << "end" << std::endl;
				std::cout << "Button Held duration: " << duration << '\n';


				if (duration > 0.75) {
					float random_number = (float)generator() / generator.max();
					if (random_number > 0.75) {
						std::cout << "BATTLE!!!!!!!!" << std::endl;
						in_combat = true;
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
