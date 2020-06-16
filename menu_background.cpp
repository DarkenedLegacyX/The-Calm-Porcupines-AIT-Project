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
