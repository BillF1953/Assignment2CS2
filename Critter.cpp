/*********************************************************************
** Program Filename: Critter Header
** Author: Tyler Forrester
** Date: 7/7/2016
** Description: Critter class base class for Ant and Doodlebug
** Input: Main() calls functions to create, kill and move creatures
** Output: Returns values to determine how creatures live
** Citations:
********************************************************************/

#include "Critter.hpp"
/* This sets the name of critter acts as a typeId and a printout representation of class*/
void Critter::setName(string x)
{
	name = x;
}
/* This seeds the random number generator*/
void Critter::seed()
{
	srand((unsigned)time(NULL));

}
/*********************************************************************
** Function: virtual function breed
** Description: returns true when time to breed, resets counter
** Parameters: 
** Pre-Conditions:  Ant::breed() Doodlebug::breed()
** Post-Conditions:  bool breed jchange() ichange() 
** Citation:
*********************************************************************/

bool Critter::breed()
{
	
		bCount = 0; 
		return true;

	
}

/*********************************************************************
** Function:  eat
** Description: keeps time to till death resets for bugs who eat ants
** Parameters: bool ateAnt
** Pre-Conditions:   jchange() ichange() 
** Post-Conditions:  Ant::death(), Doodlebug::death(), ichange(), jchange()
** Citation:
*********************************************************************/
 void Critter::eat(bool ateAnt)
{
	if (ateAnt == true) {
		eCount= 0;
		}
	else {
		eCount++; 
	}
}
 /*********************************************************************
 ** Function: vrtual death
 ** Description: Returns true when time to die causes critter to be removed from board
 ** Parameters: bool ateAnt
 ** Pre-Conditions:  jchange() ichange() Ant::death(), Doodlebug::death(),
 ** Post-Conditions:  ichange(), jchange()
 ** Citation:
 *********************************************************************/

bool Critter::death()
{
  return true;

}

/*********************************************************************
** Function: getBCount
** Description: Moves counter forward then returns value. Used to determine when to breed. 
** Parameters: 
** Pre-Conditions:  jchange() ichange() Ant::breed(), Doodlebug::breed(),
** Post-Conditions:  ichange(), jchange()
** Citation:
*********************************************************************/

int Critter::getBCount()
{
	bCount++; 
	return bCount;
}

/*********************************************************************
** Function: getECount
** Description: Returns time sense last eaten.  Will signal death
** Parameters:
** Pre-Conditions:  jchange() ichange() Ant::death(), Doodlebug::death(),
** Post-Conditions:  ichange(), jchange()
** Citation:
*********************************************************************/

int Critter::getECount()
{
	return eCount;
}
/*********************************************************************
** Function: Constructor
** Description: Sets default values, seeds random number generator
** Parameters:
** Pre-Conditions: First board build, main(), jchange() ichange()
** Post-Conditions: ichange(), jchange()
** Citation:
*********************************************************************/

Critter::Critter()
{
	bCount = 0; 
	eCount = 0; 
	seed();
	setName(".");
}
/*********************************************************************
** Function: name
** Description: Used as Type ID and print value
** Parameters:
** Pre-Conditions: First board build, main(), jchange() ichange()
** Post-Conditions: ichange(), jchange()
** Citation:
*********************************************************************/

string Critter::getName()
{
	return name;
}
/*********************************************************************
** Function: setMoveThisTurn
** Description: Sets value Used to keep creatures from moving twice in a turn. 
** Parameters: bool x
** Pre-Conditions: main(), jchange() ichange()
** Post-Conditions: ichange(), jchange()
** Citation:
*********************************************************************/

void Critter::setMoveThisTurn(bool x)
{
	moveThisTurn = x; 
}
/*********************************************************************
** Function: getMoveThisTurn
** Description: Gets value Used to keep creatures from moving twice in a turn. 
**  Reset each turn
** Parameters: bool x
** Pre-Conditions: main(), jchange() ichange()
** Post-Conditions: ichange(), jchange()
** Citation:
*********************************************************************/
bool Critter::getMoveThisTurn()
{
	return moveThisTurn;
}
/*********************************************************************
** Function: move
** Description: Returns directions of movement
** Parameters: 
** Pre-Conditions: main()
** Post-Conditions: ichange(), jchange()
** Citation:
*********************************************************************/

int Critter::move()
{
	return (1 + (rand() % 4));
}

