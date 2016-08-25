/*********************************************************************
** Program Filename: Ant Header
** Author: Tyler Forrester
** Date: 7/7/2016
** Description: Derived class from Critter Keeps track of "Ant" Behavior
** Input: Main() calls functions to create, kill and move Ants
** Output: Returns values to determine how Ants live
** Citations:
********************************************************************/



#ifndef ANT_HPP
#define ANT_HPP
#include "Critter.hpp"


class Ant : public Critter {

private:
	

public:
  Ant();   // intializes ants
  bool breed(); // override virtual function breed
  bool death(); // overrides virtual function death

}; 

#endif