// TestSDL.cpp : Defines the entry point for the console application.
// uses SDL Library https://www.libsdl.org/download-2.0.php#source
//
// setup project for SDL http://www.programmersranch.com/2014/02/sdl2-setting-up-sdl2-in-visual-studio.html

#include "stdafx.h"
#include <iostream>
#include "SDL.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window * window = SDL_CreateWindow("SDL2 Image",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	if (window == NULL)
		SDL_ShowSimpleMessageBox(0, "Window init error", SDL_GetError(),
		window);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL)
		SDL_ShowSimpleMessageBox(0, "Renderer init error",
		SDL_GetError(), window);
	SDL_Surface * image = SDL_LoadBMP("image.bmp");
	if (image == NULL)
		SDL_ShowSimpleMessageBox(0, "Image init error", SDL_GetError(),
		window);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
		image);
	if (texture == NULL)
		SDL_ShowSimpleMessageBox(0, "Texture init error",
		SDL_GetError(), window);

	
	while (!quit)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}

		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	SDL_Quit();
	
	return 0;
}

