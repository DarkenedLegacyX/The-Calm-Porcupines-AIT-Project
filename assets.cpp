#include "assets.h"
#include "texture.h"
#include "animated_texture.h"
#include "sound.h"

#include <iostream>

Assets::Assets(SDL_Renderer* renderer)
{

	// Create player walking texture.
	{
		const int frame_count = 9;

		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Walking", "Assets/ShatteredLegendResources/player.walking.right.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player walking Up texture.
	{
		const int frame_count = 9;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Walking.Up", "Assets/ShatteredLegendResources/player.walking.up.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player walking Down texture.
	{
		const int frame_count = 9;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Walking.Down", "Assets/ShatteredLegendResources/player.walking.down.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}
	// Create player dead texture.
	{
		const int frame_count = 6;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Dead", "Assets/player.dead.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}
	// Create player running texture.
	//{
	//	const int frame_count = 10;
	//	const Uint32 frame_duration_milliseconds = 100;
	//	Asset* player_animated_texture = new Animated_Texture("Texture.Player.Running", "Assets/player.running.png", renderer, frame_count, frame_duration_milliseconds);
	//	_assets[player_animated_texture->id()] = player_animated_texture;
	//}

	// Create player idle texture.
	{
		const int frame_count = 2;
		const Uint32 frame_duration_milliseconds = 500;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Idle", "Assets/ShatteredLegendResources/player.idle.down.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player idle Fight texture.
	{
		const int frame_count = 5;
		const Uint32 frame_duration_milliseconds = 300;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Fight", "Assets/ShatteredLegendResources/player.idle.right.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player Attack texture.
	{
		const int frame_count = 7;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Attack", "Assets/ShatteredLegendResources/player.attack.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player dead texture.
	{
		const int frame_count = 6;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.", "Assets/ShatteredLegendResources/player.dead.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create Enemy texture
	{
		const int frame_count = 4;
		const Uint32 frame_duration_milliseconds = 300;
		Asset* player_animated_texture = new Animated_Texture("Texture.Enemy.Idle", "Assets/enemy.idle.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}
	// Create Enemy  Attack texture
	{
		const int frame_count = 11;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Enemy.Attack", "Assets/enemy.attack.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create animated dragon
	{
		const int frame_count = 3;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Dragon", "Assets/dragon.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}
	// Create menu texture
	{
		Texture* texture = new Texture("Texture.Menu", "Assets/menu.png", renderer);
		_assets[texture->id()] = texture;
	}

	// Create Lose texture
	{
		Texture* texture = new Texture("Texture.Lose", "Assets/gameover.png", renderer);
		_assets[texture->id()] = texture;
	} 
	// Create Win texture
	{
		Texture* texture = new Texture("Texture.Win", "Assets/win_screen.png", renderer);
		_assets[texture->id()] = texture;
	}
	// Tree textures
	for (int i = 1; i <= 4; ++i)
	{
		Texture* texture = new Texture("Texture.Tree" + std::to_string(i), "Assets/tree" + std::to_string(i) + ".png", renderer);
		_assets[texture->id()] = texture;
	}

	// Create combat texture
	{
		Texture* texture = new Texture("Texture.Combat", "Assets/beach.png", renderer);
		_assets[texture->id()] = texture;
	}
	//Diamond texture
	{
		Texture* texture = new Texture("Texture.Diamond", "Assets/Crystal.png", renderer);
		_assets[texture->id()] = texture;
	}

	// Create tile texture
	for(int i = 0; i <14; ++i)
	{
		std::string id = "Texture.Tile" + std::to_string(i);
		std::string path = "Assets/tile" + std::to_string(i) + ".png";
		Texture* texture = new Texture(id, path, renderer);
		_assets[texture->id()] = texture;
	}
	

	// Create music sound
	{
		Sound* sound = new Sound("Sound.Music", "Assets/ShatteredLegendResources/MusicOriginal/Take Over (Battle Theme) - Persona 5 Royal.mp3");
		_assets[sound->id()] = sound;

		Mix_PlayChannel(0, sound->data(), -1);
	}

	// Create walking sound
	{
		//Sound* sound = new Sound("Sound.Walking", "Assets/walking.wav");
		//_assets[sound->id()] = sound;
	}

	// Create running sound
	{
		//Sound* sound = new Sound("Sound.Running", "Assets/running.wav");
		//_assets[sound->id()] = sound;
	}


}

Assets::~Assets()
{

}

Asset* Assets::get_asset(std::string id)
{
	if (_assets.find(id) == _assets.end())
	{
		std::cout << "Attempted to find an asset that was not loaded. ID: " << id << std::endl;
		exit(1);
	}

	return _assets[id];
}