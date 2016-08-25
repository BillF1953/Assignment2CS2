/*********************************************************************
** Program Filename: Doodlebug.cpp
** Author: Tyler Forrester
** Date: 7/7/2016
** Description: Derived class from Critter Keeps track of "Doodlebug" Behavior
** Input: Main() calls functions to create, kill and move Doodlebug
** Output: Returns values to determine how  Doodlebugs live
** Citations:
********************************************************************/



#include "Doodlebug.hpp"
/*********************************************************************
** Function: Constructor
** Description: Sets default value of critters who are Doodlebugs to "D"
** Parameters:
** Pre-Conditions: First Doodlebugs constructed in main
** Post-Conditions: all program functions dealing with Doodlebug
** Citation:
*********************************************************************/

Doodlebug::Doodlebug()
{

		setName("D");
	
}

/*********************************************************************
** Function: breed()
** Description: Overrdes Critter::Breed, checks time till Breeding then calls the Base Class method
** Returns False if not time to breed
** Parameters:
** Pre-Conditions: Doodlebug Exists Movement function called
** Post-Conditions: Causes new Doodlebug Object to be left when  Doodlebug moves spaces
** Citation:
*********************************************************************/

bool Doodlebug::breed()
{

	if (getBCount() == 8) {

		return Critter::breed();
	}
	return false;
}


/*********************************************************************
** Function: death()
** Description: Overrdes Critter::Death, checks time since last ate then calls the Base Class method
** Returns False if not time to die
** Parameters:
** Pre-Conditions: Doodlebug Exists.  Movement function called
** Post-Conditions: Removes Doodlebug from Board
** Citation:
*********************************************************************/

bool Doodlebug::death()
{
	if (getECount() == 3) {

		return Critter::death(); 
	}
	return false;
}

