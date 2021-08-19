#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
	if(SDL_Init(0))
	{
		puts("SDL_Init failed");
		return 1;
	}
	
	SDL_Window *window = NULL;
	window = SDL_CreateWindow("minimal SDL2",
		                  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		                  640, 480,
		                  0);
	if(window == NULL)
	{
		puts("SDL_CreateWindow failed");
		return 1;
	}
	
	SDL_Renderer *renderer = NULL;
	renderer = SDL_CreateRenderer(window,
		                    -1,
		                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	if(renderer == NULL)
	{
		puts("SDL_CreateRenderer failed");
		return 1;
	}
	SDL_SetRenderDrawColor(renderer,
	                       0x10,
	                       0xb0,
	                       0x10,
	                       SDL_ALPHA_OPAQUE);
	
	SDL_RenderFillRect(renderer, NULL);
	SDL_RenderPresent(renderer);
	SDL_Event event;
	while (SDL_WaitEvent(&event) >= 0)
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return(0);
				break;
			default: break;
		}
	}
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return 0;
}

