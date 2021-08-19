#include <SDL2/SDL.h>

SDL_Window *g_window = NULL;

int Init(int *Screen)
{
	// print sdl version
	{
		SDL_version Compiled;
		SDL_version Linked;

		SDL_VERSION(&Compiled);
		SDL_GetVersion(&Linked);
		printf("[sdl] SDL version %d.%d.%d (compiled = %d.%d.%d)\n", Linked.major, Linked.minor, Linked.patch,
			Compiled.major, Compiled.minor, Compiled.patch);
	}
	if(!SDL_WasInit(SDL_INIT_VIDEO))
	{
		if(SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
		{
			printf("[gfx] unable to init SDL video: %s\n", SDL_GetError());
			return 1;
		}
	}
	// store desktop resolution for settings reset button
	SDL_DisplayMode DisplayMode;
	if(SDL_GetDesktopDisplayMode(*Screen, &DisplayMode))
	{
		printf("[gfx] unable to get desktop resolution: %s\n", SDL_GetError());
		return 1;
	}
	int SdlFlags = SDL_WINDOW_OPENGL | \
		       SDL_WINDOW_INPUT_GRABBED | \
		       SDL_WINDOW_INPUT_FOCUS | \
		       SDL_WINDOW_MOUSE_FOCUS | \
		       SDL_WINDOW_FULLSCREEN;
	g_window = SDL_CreateWindow(
		"SDL2",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		DisplayMode.w,
		DisplayMode.h,
		SdlFlags);
	return 0;
}

int main(int argc, char* argv[]) {
	if(SDL_Init(0))
	{
		puts("SDL_Init failed");
		return 1;
	}
	int Screen = 0;
	Init(&Screen);
	
	if(g_window == NULL)
	{
		puts("SDL_CreateWindow failed");
		return 1;
	}
	
	SDL_Renderer *renderer = NULL;
	renderer = SDL_CreateRenderer(g_window,
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
	SDL_DestroyWindow(g_window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return 0;
}

