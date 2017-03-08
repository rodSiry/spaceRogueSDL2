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
#include <glm/ext.hpp>
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
		Drawer (std::string path, SDL_Window* W, SDL_Renderer* RD);                             /* constructor */
		glm::vec3 Proj(glm::vec3 v);
		void Draw(int tN, glm::vec3 pos);
		void DrawS(int tN, glm::vec3 pos);
		void DrawShp(int tN, glm::vec3 pos);
		void DrawD();
		~Drawer();
		/* ====================  ACCESSORS     ======================================= */

		/* ====================  MUTATORS      ======================================= */

		/* ====================  OPERATORS     ======================================= */

	protected:
		/* ====================  DATA MEMBERS  ======================================= */
		SDL_Renderer* rD;
		SDL_Window* w;
		SDL_Texture* tile;
		SDL_Texture* dam;
		int tW;
		int nW;
		int nH;	
		glm::mat4 mV;
	private:
		/* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class Drawer  ----- */

#endif   /* ----- #ifndef DRAW_INC  ----- */
