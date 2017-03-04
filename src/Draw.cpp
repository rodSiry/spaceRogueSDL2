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
using namespace std;
Drawer::Drawer(string path): tile(IMG_Load(path.c_str())), tW(32)
{
		
}
void Drawer::Draw(int tN, glm::vec3 pos)
{
 	
}
