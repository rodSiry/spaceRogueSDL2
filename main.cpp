#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
using namespace std;
int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *win=SDL_CreateWindow("Hello, world!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,512, 512, SDL_WINDOW_RESIZABLE);
	SDL_Surface* wSf=SDL_GetWindowSurface(win);
	SDL_Rect source={0,0,512,512};
	SDL_Rect dest={0,0,0,0};
	SDL_Surface* sprite=IMG_Load("13081.png");
	if(sprite==NULL)
		cerr<<IMG_GetError()<<endl; 
	SDL_BlitSurface(sprite, NULL, wSf, &dest);
	SDL_UpdateWindowSurface(win);
	SDL_Delay(2000);
	SDL_FreeSurface(sprite);
	SDL_Quit();
	return 0;
}


