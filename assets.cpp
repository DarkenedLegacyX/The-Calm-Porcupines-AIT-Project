#include "assets.h"
#include "texture.h"
#include "animated_texture.h"
#include "sound.h"

#include <iostream>

Assets::Assets(SDL_Renderer* renderer)
{

	// Create player walking texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Walking", "Assets/player.walking.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player running texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Running", "Assets/player.running.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player idle texture.
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 50;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Idle", "Assets/player.idle.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create collider texture
	{
		Texture* texture = new Texture("Texture.Collider", "Assets/collider.png", renderer);
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
		Sound* sound = new Sound("Sound.Music", "Assets/ShatteredLegendResources/Music8-Bit/Persona5Price8Bit.mp3");
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