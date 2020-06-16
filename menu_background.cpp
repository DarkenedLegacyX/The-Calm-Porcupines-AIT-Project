#include "menu_background.h"
#include "text.h"

Menu_background::Menu_background(std::string id) : Game_Object(id, "Texture.Menu")
{
	_translation = Vector_2D(0, 0);
	_width = 800;
	_height = 800;


}

Menu_background::~Menu_background()
{
}

void Menu_background::simulate_AI(Uint32, Assets* , Input*, Scene* ) 
{
}

void Menu_background::render(Uint32, Assets* assets, SDL_Renderer* renderer, Configuration* config)
{


		SDL_Color text_color;
		text_color.r = 255;
		text_color.g = 0;
		text_color.b = 0;
		text_color.a = 0;

		Text id(renderer, _id.c_str(), text_color, "ID.Text");


		id.render(renderer, _translation);
	
}