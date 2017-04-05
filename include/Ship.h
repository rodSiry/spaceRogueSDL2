/*
 * =====================================================================================
 *
 *       Filename:  Ship.h
 *
 *    Description:  Class Ship
 *
 *
 *        Version:  1.0
 *        Created:  05/04/2017 18:12:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry, rodsiry@gmail.com
 *   Organization:  Ecole supérieure d'électricité
 *
 * =====================================================================================
 */

#ifndef  SHIP_H
#define SHIP_H
#include <queue>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
/*
 * =====================================================================================
 *        Class:  Ship
 *  Description:  Vaisseau - Variables d'état  
 * =====================================================================================
 */
class Ship
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		Ship ();                             /* constructor */
		~Ship();
		void Move();
		std::deque<glm::vec3>* GetQueue(){return &pos;}
		/* ====================  ACCESSORS     ======================================= */

		/* ====================  MUTATORS      ======================================= */

		/* ====================  OPERATORS     ======================================= */

	protected:
		/* ====================  DATA MEMBERS  ======================================= */
		std::deque<glm::vec3>pos;
	 	glm::mat4 dir; 	
		int nMaxPos=20;
	private:
		/* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class Ship  ----- */

#endif     /* -----  not SHIP_H  ----- */
