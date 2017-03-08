#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include "include/Draw.h"
#include <iostream>
#include <glm/glm.hpp>
using namespace std;
int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *win=SDL_CreateWindow("Hello, world!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,512, 512, SDL_WINDOW_RESIZABLE);
	SDL_Renderer *pRenderer = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);	
	SDL_Surface* wSf=SDL_GetWindowSurface(win);
	Drawer d("13081.png", win, pRenderer);	
	SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
	for(int i(0);i<1000;i++)
	{	
		d.DrawShp(10, glm::vec3(20.f*sin(SDL_GetTicks()/1000.f),20.f*cos(SDL_GetTicks()/1000.f),20.f*cos(SDL_GetTicks()/1000.f)));
		d.DrawD();
		SDL_RenderPresent(pRenderer);
		SDL_Delay(10);
		SDL_SetRenderDrawColor(pRenderer, 0, 10, 255, 255);
		SDL_RenderClear(pRenderer);
	}
	SDL_DestroyRenderer(pRenderer);
	SDL_Quit();
	return 0;
}


