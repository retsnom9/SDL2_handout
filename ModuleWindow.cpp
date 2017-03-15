#include "Globals.h"
#include "Application.h"
#include "ModuleWindow.h"
// TODO 2: Init the library and check for possible error
// using SDL_GetError()

// TODO 3: pick the width and height and experiment with flags: borderless / fullscreen / resizable,
// then create the window and check for errors

// TODO 4: Finally create a screen surface and keep it as a public variable

// TODO 5: Fill with code CleanUp() method :)

bool ModuleWindow::Init()
{
	bool ret = true;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		LOG("Unable to initialize SDL: %s\n", SDL_GetError());
		ret = false;
	}
	else
	{
		window = SDL_CreateWindow("win", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 620, 480, SDL_WINDOW_RESIZABLE);

		if (window == 0)
		{
			LOG("Unsuccessful window creation. %s", SDL_GetError());
		}

		ret = true;
	}

	return ret;
}

bool ModuleWindow::CleanUp()
{
	SDL_Quit();
	return true;
}