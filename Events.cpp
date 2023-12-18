#include "Events.h"
#include "Init.h"
#include "Renderer.h"

bool Events::handleEvents()
{

	Init init;
	Renderer rendering;
	bool quit = false;

	SDL_Event e;
	//we will always render inside the while loop but outside of the main quit loop etc.
	init.startSDL();
	while (!quit)
	{
		while (SDL_PollEvent(&e)!=0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		rendering.renderer(init);
	}
	//rendering.cleanup(init);
	return 0;
}