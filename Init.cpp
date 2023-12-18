#include "Renderer.h"
#include "MapEditor.h"

void Init::startSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL could not init correctly" << SDL_GetError() << std::endl;
	}
	
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		std::cerr << "SDL_IMAGE FAILED: " << SDL_GetError() << std::endl;
	}

	window = SDL_CreateWindow("Shine Ville World Editor v2.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		std::cerr << "Window could not be created: " << SDL_GetError() << std::endl;

	}

	gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (gRenderer == nullptr)
	{
		std::cerr << "gRenderer could not be created!" << SDL_GetError() << std::endl;
	}

	
}