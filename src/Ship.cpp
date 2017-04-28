/*
 * ===================================================================================== 
 * 
 *   * * Filename:  Ship.cpp * *    
 *   Description:  Implémentation classe Ship * *        
 *   Version:  1.0 *        
 *   Created:  05/04/2017 18:26:40
 *   Revision:  none
 *   Compiler:  gcc
 *   Author:  Rodrigue Siry, rodsiry@gmail.com
 *   Organization:  Ecole supérieure d'électricité
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "../include/Ship.h"
#include <SDL2/SDL.h>
using namespace std; 
using namespace glm;
int rd()
{
	return rand()%100-50;
}
Ship::Ship(): dir(mat4(1.))
{
	pos.push_front(vec3(rd(),rd(),rd()));
}		/* -----  end of method Ship::Ship  ----- */
Ship::Ship( vec3 POS) 
{
	Ship();
	pos.push_front(POS);
}
void Ship::MoveRd()
{
	pos.push_front(vec3(0.,0.,10.));
}
void Ship::MovePly()
{
	float turn=90.f;
	float speed=1.f;
	const Uint8* keys=SDL_GetKeyboardState(NULL);
	if(keys[SDL_SCANCODE_J])
		dir=rotate(dir, radians(-turn), glm::vec3(1.f, 0.f, 0.f));
	if(keys[SDL_SCANCODE_K])
		dir=rotate(dir, radians(turn), glm::vec3(1.f, 0.f, 0.f));
	if(keys[SDL_SCANCODE_H])
		dir=rotate(dir, radians(-turn), glm::vec3(0.f, 0.f, 1.f));
	if(keys[SDL_SCANCODE_L])
		dir=rotate(dir, radians(turn), glm::vec3(0.f, 0.f, 1.f));
	vec3 p=*pos.begin();
	p+=speed*vec3(dir*vec4(0.,0.,1.,0.));
	pos.push_front(p);
	if(pos.size()>nMaxPos)
	{
		pos.pop_back();
	}

}
void Ship::MoveDiscr(Ship *tg)
{
	float turn=90.f;
	float speed=1.f;
	vec3 tP=*tg->GetQueue()->begin();
	mat4 tDir=tg->GetDir();
	vec3 d=vec3(dir*vec4(0.,0.,1.,0.));
	vec3 p=*pos.begin();
	vec3 rA=normalize(cross(tP-p, d));
//	if(angle(vec3(dir*vec4(0.f,0.f,1.f,0.f)),tP-p)<=radians(10.f)&& angle(vec3(dir*vec4(0.f,0.f,1.f,0.f)) ,vec3(tDir*vec4(0.f,0.f,1.f,0.f)))<=radians(10.f))
//		turn=0.f;
	int ind=0;
	float max=0;
	mat3 M(1.0);
	vec3 vP=M*rA;
	for(int i(0);i<3;i++)
	{
		if (abs(vP[i])>max)
		{
			max=abs(vP[i]);
			ind=i;
		}
	}
	rA=normalize(vP[ind])*M[ind];
	dir=rotate(radians(-turn), rA)*dir;
	p+=speed*vec3(dir*vec4(0.,0.,1.,0.));
	pos.push_front(p);
	if(pos.size()>nMaxPos)
	{
		pos.pop_back();
	}
}
void Ship::MoveToTrg(Ship* tg)
{
	float turn=5.f;
	float speed=0.1f;
	vec3 tP=*tg->GetQueue()->begin();
	mat4 tDir=tg->GetDir();
	vec3 d=vec3(dir*vec4(0.,0.,1.,0.));
	vec3 p=*pos.begin();
	vec3 rA=normalize(cross(tP-p, d));
	dir=rotate(radians(-turn), rA)*dir;
	p+=speed*vec3(dir*vec4(0.,0.,1.,0.));
	pos.push_front(p);
	if(pos.size()>nMaxPos)
	{
		pos.pop_back();
	}

}

Ship::~Ship ()
{
}		/* -----  end of method Ship::~Ship  ----- */

