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
	SDL_Surface* wSf=SDL_GetWindowSurface(win);
	SDL_Rect dest={0,0,0,0};
	SDL_Surface* sprite=IMG_Load("13081.png");
	if(sprite==NULL)
		cerr<<IMG_GetError()<<endl; 
	Drawer d("13081.png", win);	
	for(int i(0);i<1000;i++)
	{	
		d.DrawS(80, glm::vec3(20.f*sin(SDL_GetTicks()/1000.f),0,20.f*cos(SDL_GetTicks()/1000.f)));
		d.DrawS(80, glm::vec3(16,16,0));
		SDL_UpdateWindowSurface(win);
		SDL_Delay(10);
	
	}
		SDL_FreeSurface(sprite);
	SDL_Quit();
	return 0;
}


