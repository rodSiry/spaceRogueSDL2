/*
 * =====================================================================================
 *
 *       Filename:  Draw.cpp
 *
 *    Description:  class Drawer implementation 
 *
 *        Version:  1.0
 *        Created:  04/03/2017 16:55:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry, rodsiry@gmail.com
 *   Organization:  Ecole supérieure d'électricité
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "../include/Draw.h"
#define RECT(a, b, c, d) (SDL_Rect){a,b,c,d} 
#include <iostream>
using namespace std;
using namespace glm;
vec3 Drawer::Proj(vec3 v)
{
	
	SDL_Surface* win=SDL_GetWindowSurface(w);
	int a, b;
	SDL_GetRendererOutputSize(rD, &a, &b);
	v.x=(v.x+20.f)/40.f*a;
	v.y=(20.f-v.y)/40.f*b;
	return v;
}
SDL_Rect Rect(glm::vec3 v)
{
	SDL_Rect r;
	r.x=v.x;
	r.y=v.y;
	return r;	
}
SDL_Rect RectTexture(SDL_Texture* t)
{
	SDL_Rect r;
	SDL_QueryTexture(t, NULL, NULL, &r.w, &r.h);
	return r;
}
Drawer::Drawer(string path, SDL_Window* W, SDL_Renderer* RD): rD(RD), tW(16), w(W), mV(lookAt(vec3(0.,0.,0.),vec3(0.,1.,-1),vec3(0.,1.,0.)))
{
	SDL_Surface* tl=IMG_Load(path.c_str());
	SDL_Surface* dm=IMG_Load("grosDamier.png");
	dam=SDL_CreateTextureFromSurface(rD, dm);
	tile=SDL_CreateTextureFromSurface(rD, tl);
	nH=tl->h/tW;
	nW=tl->w/tW;
	SDL_FreeSurface(tl);	
	SDL_FreeSurface(dm);	
}
void Drawer::DrawS(int tN, vec3 pos)
{	
	
	pos=vec3(mV*vec4(pos, 1.));
	pos=Proj(pos);
	Draw(tN, pos);	
}
void Drawer::DrawShp(int tN, Ship* shp)
{
	deque<vec3>* q=shp->GetQueue();
	int j=255;
	for(deque<vec3>::iterator i(q->begin()); i!=q->end() && (i+1)!=q->end();++i)
	{
		j-=255/20;
		vec3 p1=*(i+1);
		vec3 p2=*i;
		SDL_SetRenderDrawColor(rD, j, j, j, 255);
		vec3 p1S=Proj(vec3(mV*vec4(p1,1.)));
		vec3 p2S=Proj(vec3(mV*vec4(p2,1.)));
		SDL_RenderDrawLine(rD,p1S.x,p1S.y,p2S.x,p2S.y);
		cout<<"lol"<<endl;
	}	
	vec3 posP=*q->begin();
	vec3 pos=posP;
	posP.y=0.f;
	DrawS(641, posP);
	SDL_SetRenderDrawColor(rD, 0, 0, 255, 0);
	vec3 posS=Proj(vec3(mV*vec4(pos,1.)));
	vec3 posPS=Proj(vec3(mV*vec4(posP,1.)));
	SDL_RenderDrawLine(rD,posS.x,posS.y,posPS.x,posPS.y);
	DrawS(tN, pos);
		
}
Drawer::~Drawer()
{
	SDL_DestroyTexture(tile);
}
void Drawer::Draw(int tN, glm::vec3 pos)
{
	int bW=tN%nW;
	int bH=(tN-bW)/nW;
 	SDL_Rect src=RECT(tW*bW,tW*bH,tW, tW);
	vec3 p=pos-glm::vec3(tW/2., tW/2., 0.);
	SDL_Rect rK=Rect(p);
	rK.w=tW;
	rK.h=tW;
        SDL_RenderCopy(rD,tile,&src,&rK);
}
void Drawer::DrawD()
{
	vec3 a(-20.f, 0.f,20.f);
	vec3 b(20.f, 0.f,-20.f);
	a=Proj(vec3(mV*vec4(a, 1.f)));
	b=Proj(vec3(mV*vec4(b, 1.f)));
	SDL_Rect dest=Rect(a);
	dest.w=b.x-a.x;
	dest.h=b.y-a.y;
	SDL_Rect src=RECT(0,0,512,512);
	SDL_RenderCopy(rD, dam, &src, &dest);
}
