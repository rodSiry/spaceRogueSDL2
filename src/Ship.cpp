/*
 * =====================================================================================
 *
 *       Filename:  Ship.cpp
 *
 *    Description:  Implémentation classe Ship
 *
 *        Version:  1.0
 *        Created:  05/04/2017 18:26:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry, rodsiry@gmail.com
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
	return rand()%50-25;
}
Ship::Ship(): dir(mat4(1.))
{
	pos.push_front(vec3(rd(),rd(),rd()));
}		/* -----  end of method Ship::Ship  ----- */
void Ship::Move()
{
	vec3 tD=vec3(vec4(0.,0.,1.,0.));
	vec3 d=vec3(dir*vec4(0.,0.,1.,0.));
	vec3 p=*pos.begin();
	vec3 rA=normalize(cross(-p, d));
	dir=rotate(radians(-5.f), rA)*dir;
	p+=0.5f*vec3(dir*vec4(0.,0.,1.,0.));
	pos.push_front(p);
	if(pos.size()>nMaxPos)
	{
		pos.pop_back();
	}
}

Ship::~Ship ()
{
}		/* -----  end of method Ship::~Ship  ----- */

