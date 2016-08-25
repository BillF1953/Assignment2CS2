/*********************************************************************
** Program Filename: Ant.cpp
** Author: Tyler Forrester
** Date: 7/7/2016
** Description: Derived class from Critter Keeps track of "Ant" Behavior
** Input: Main() calls functions to create, kill and move Ants
** Output: Returns values to determine how Ants live
** Citations:
********************************************************************/



#include "Ant.hpp"
/*********************************************************************
** Function: Constructor
** Description: Sets default value of critters who are Ants to "A"
** Parameters:
** Pre-Conditions: First Ant constructed in main
** Post-Conditions: all program functions dealing with ants
** Citation:
*********************************************************************/
Ant::Ant() 
{
	setName("A");  
}

/*********************************************************************
** Function: breed()
** Description: Overrdes Critter::Breed, checks time till Breeding then calls the Base Class method
** Returns False if not time to breed 
** Parameters:
** Pre-Conditions: Ant Exists Movement function called
** Post-Conditions: Causes new Ant Object to be left when Ant moves spaces
** Citation:
*********************************************************************/

bool Ant::breed()
{
  
  if (getBCount() == 3) {

	  return Critter::breed();
  }
	return false;
}

/*********************************************************************
** Function: death()
** Description: Overrdes Critter::Death, checks time since last ate  then calls the Base Class method
** Returns False if not time to die
** Parameters:
** Pre-Conditions: Ant Exists.  Movement function called
** Post-Conditions: Removes Ant from Board
** Citation:
*********************************************************************/

bool Ant::death()
{
	if (getECount() == 10) {

		return Critter::death(); 
	}
	return false;
}
