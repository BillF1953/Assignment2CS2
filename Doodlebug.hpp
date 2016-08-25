/*********************************************************************
** Program Filename: Doodlebug Header
** Author: Tyler Forrester
** Date: 7/7/2016
** Description: Derived class from Critter Keeps track of "Doodlebug" Behavior
** Input: Main() calls functions to create, kill and move Doodlebug
** Output: Returns values to determine how Doodlebug live
** Citations:
********************************************************************/



#ifndef Doodlebug_HPP
#define Doodlebug_HPP
#include "Critter.hpp"


class Doodlebug : public Critter {

private:


public:
	Doodlebug(); // sets name in baseclass to "D"
	bool breed(); // overrides virtual function in base class 
	bool death(); // overrides virtual function in base class

};

#endif
