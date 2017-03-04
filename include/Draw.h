/*
 * =====================================================================================
 *
 *       Filename:  Draw.h
 *
 *    Description:  Classe Drawer
 *
 *        Version:  1.0
 *        Created:  04/03/2017 16:36:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry, rodsiry@gmail.com
 *   Organization:  Ecole supérieure d'électricité
 *
 * =====================================================================================
 */

#ifndef  DRAW_INC
#define  DRAW_INC
#include <SDL2/SDL.h>
#include <string>
#include <glm/glm.hpp>
#include <SDL/SDL_image.h>
/*
 * =====================================================================================
 *        Class:  Drawer
 *  Description: SDL blit wrapper 
 * =====================================================================================
 */
class Drawer
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		Drawer (std::string path);                             /* constructor */
		void Draw(int tN, glm::vec3 pos);
		~Drawer();
		/* ====================  ACCESSORS     ======================================= */

		/* ====================  MUTATORS      ======================================= */

		/* ====================  OPERATORS     ======================================= */

	protected:
		/* ====================  DATA MEMBERS  ======================================= */
		SDL_Surface* tile;
		int tW;	
	private:
		/* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class Drawer  ----- */

#endif   /* ----- #ifndef DRAW_INC  ----- */
