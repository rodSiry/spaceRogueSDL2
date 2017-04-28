/* * ===================================================================================== *
 *    Description:  class Drawer implementation 
 *
 *        Version:  1.0
 *        Created:  04/03/2017 16:55:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry, rodsiry@gmail.com
 *   Organization:  Ecole supérieure d'électricité
 * * ===================================================================================== */ 
#include <stdlib.h>
#include "../include/Draw.h"
#define RECT(a, b, c, d) (SDL_Rect){a,b,c,d} 
#include <iostream>
using namespace std;
using namespace glm;
vec3 Drawer::Proj(vec4 v)
{
	
	return vec3(v);
}
SDL_Rect Rect(glm::vec3 v)
{
	SDL_Rect r;
	r.x=v.x;
	r.y=v.y;
	return r;	
}
void Drawer::SetMM(Ship* shp)
{

 	vec3 pos= *shp->GetQueue()->begin();
	mM=inverse(translate(mat4(1.f), pos)*shp->GetDir());
}
SDL_Rect RectTexture(SDL_Texture* t)
{
	SDL_Rect r;
	SDL_QueryTexture(t, NULL, NULL, &r.w, &r.h);
	return r;
}
Drawer::Drawer(string path, SDL_Window* W, SDL_Renderer* RD): rD(RD), mM(mat4(1.0)),tW(8), w(W), mV(lookAt(vec3(0.f,40.f,-40.f), vec3(0.f,0.f,0.f),vec3(0.f,1.f,0.f)))
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
void Drawer::DrawS(int tN, vec3 pos, vec3 Color)
{	
	int a, b;
	SDL_GetRendererOutputSize(rD, &a, &b);
	pos.x+=a/tW/2;
	pos.y=b/tW/2-pos.y;
	pos.y-=pos.z;
    SDL_SetTextureColorMod(tile, 0, 0, 0);
    Draw(219, pos);
    SDL_SetTextureColorMod(tile, Color.x, Color.y, Color.z);
	Draw(tN, pos);	
}
void Drawer::DrawShpDiscr(int tN, Ship* shp)
{
	deque<vec3>* q=shp->GetQueue();
	for(deque<vec3>::iterator i(++q->begin()); i!=q->end();++i)
	{
		vec3 p1=*i; 
		vec3 p1S=vec3(mM*vec4(p1,1.f));
		DrawS(tN, p1S, vec3(50, 0, 0));
	}	
	vec3 posP=*q->begin();
	vec3 pos=posP;
	SDL_SetRenderDrawColor(rD, 0, 0, 255, 0);
	vec3 posS=vec3(mM*vec4(pos,1.));
	vec4 posPS4=mM*vec4(posP,1.);
	posPS4.y=0.f;
	vec3 posPS=vec3(posPS4);
	int c(normalize((posPS-posS).y));
	int i(rint(posS.y)+c);
    if(posPS!=posS)
        while(abs(i)>1.f)
        {
            vec3 posL=posS;
            posL.y=i;
            DrawS(179, posL, vec3(50,0,0));
            i+=c;
        }
	DrawS(tN, posS, vec3(255, 0, 0));
		
}

	Drawer::~Drawer()
{
	SDL_DestroyTexture(tile);
}
void Drawer::DrawPartDiscr(int tN, vec3 pos)
{
	SDL_SetRenderDrawColor(rD, 0, 0, 255, 0);
	vec3 posS=vec3(mM*vec4(pos,1.));
	vec4 posPS4=mM*vec4(pos,1.);
	posPS4.y=0;
	vec3 posPS=vec3(posPS4);
    int c;
    if(posS.y==0)
        c=0;
    else
        c=normalize(-posS.y);
	int i(rint(posS.y));
    if(abs(posS.x)+abs(posS.y)+abs(posS.z)<3*16)
    {
        while(abs(i)>=1)
        {
            vec3 posL=posS;
            posL.y=i;
            DrawS(179, posL, vec3(0,0, 50));
            i+=c;
        }
        DrawS(42, posPS, vec3(0,0, 50));
    }
	DrawS(tN, posS, vec3(0, 0, 255*(32-int(abs(posS.y)))));
}

void Drawer::Draw(int tN, glm::vec3 pos)
{
	int bW=tN%nW;
	int bH=(tN-bW)/nW;
 	SDL_Rect src=RECT(tW*bW,tW*bH,tW, tW);
	pos=vec3(rint(pos.x), rint(pos.y), rint(pos.z));
	vec3 p=tW*pos;
	SDL_Rect rK=Rect(p);
	rK.w=tW;
	rK.h=tW;
    SDL_RenderCopy(rD,tile,&src,&rK);
}
void Drawer::DrawD()
{
	vec3 a(-20.f, 0.f,20.f);
	vec3 b(20.f, 0.f,-20.f);
	a=Proj(vec4(a, 1.f));
	b=Proj(vec4(b, 1.f));
	SDL_Rect dest=Rect(a);
	dest.w=b.x-a.x;
	dest.h=b.y-a.y;
	SDL_Rect src=RECT(0,0,512,512);
	SDL_RenderCopy(rD, dam, &src, &dest);
}
