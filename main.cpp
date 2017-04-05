#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include "include/Draw.h"
#include <iostream>
#include <glm/glm.hpp>
#include "include/Ship.h"
using namespace std;
int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *win=SDL_CreateWindow("Hello, world!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,512, 512, SDL_WINDOW_RESIZABLE);
	SDL_Renderer *pRenderer = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);	
	SDL_Surface* wSf=SDL_GetWindowSurface(win);
	Drawer d("tile.png", win, pRenderer);	
	SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
	vector<Ship> shp;
	for(int i(0); i<5;i++)
	{		
		shp.push_back(Ship());
		shp[i].Move();
	}
	while(true)
	{	
		for(int i(0); i<shp.size();i++)
		{		
			shp[i].Move();
		d.DrawShp(60, &shp[i]);
		}
		SDL_RenderPresent(pRenderer);
		SDL_Delay(10);
		SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
		SDL_RenderClear(pRenderer);
		const Uint8 *keys = SDL_GetKeyboardState(NULL);
		SDL_Event e;
		do 	
			SDL_WaitEvent(&e);
		while(e.type!=SDL_KEYDOWN);
		if (e.type == SDL_QUIT){
	 		break; 
		}
		if (keys[SDL_SCANCODE_ESCAPE]){
			SDL_DestroyRenderer(pRenderer);
			SDL_Quit();
			return 0;
		}
		SDL_Delay(10);
	}
	SDL_Quit();
	return 0;
}


