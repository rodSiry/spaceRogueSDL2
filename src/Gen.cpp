/*
 * =====================================================================================
 *
 *       Filename:  Gen.cpp
 *
 *    Description:  Procedural generation methods
 *
 *        Version:  1.0
 *        Created:  20/04/2017 18:18:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry, rodsiry@gmail.com
 *   Organization:  Ecole Supérieure d'électricité
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "../include/Gen.h"
#include <iostream>
#define SEED 1
using namespace std;
using namespace glm;
int genCentered(int s)
{
    return (rand()%s)-s/2;
}
deque<vec3> genDiscr(vec3 pos)
{
   deque<vec3> sol;
   int s=64;
   vec3 d64=pos/float(s);
   vec3 dPos(rint(d64.x), rint(d64.y), rint(d64.z));
   dPos*=s;
   for(int i(dPos.x-s);i<dPos.x+2*s;i+=s)
       for(int j(dPos.y-s);j<dPos.y+2*s;j+=s)
           for(int k(dPos.z-s);k<dPos.z+2*s;k+=s)
           {
               int acc;
               srand(i);
               acc=rand();
               srand(acc+j);
               acc=rand();
               srand(acc+k);
               for(int l(0);l<8;l++)
               {
                   vec3 adm(genCentered(s), genCentered(s), genCentered(s));
                   adm+=vec3(i,j,k);
                   if(abs(adm.x-dPos.x)+abs(adm.y-dPos.y)+abs(adm.z-dPos.z)<3*s)
                       sol.push_front(adm);   
               } 
           }
   return sol;
}
deque<vec3> genNaive()
{
    deque<vec3> sol;
    sol.push_front(vec3(0, 1, 1));
    return sol;
}
