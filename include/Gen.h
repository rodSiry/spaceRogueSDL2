/*
 * =====================================================================================
 *
 *       Filename:  Gen.h
 *
 *    Description:  Procedural Generation 
 *
 *
 *        Version:  1.0
 *        Created:  20/04/2017 18:12:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry (), rodsiry@gmail.com
 *   Organization:  Ecole Supérieure d'électricité
 *
 * =====================================================================================
 */

#ifndef  GEN_INC
#define  GEN_INC
#include <queue>
#include <glm/glm.hpp>

std::deque<glm::vec3> genDiscr(glm::vec3 pos);
std::deque<glm::vec3> genNaive();
#endif   /* ----- #ifndef GEN_INC  ----- */
