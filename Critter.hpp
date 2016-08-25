/*********************************************************************
** Program Filename: Critter Header
** Author: Tyler Forrester
** Date: 7/7/2016
** Description: Critter class base class for Ant and Doodlebug
** Input: Main() calls functions to create, kill and move creatures
** Output: Returns values to determine how creatures live
** Citations:
********************************************************************/



#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <cstdlib>
#include<ctime>
#include <iostream>
#include <string>



using std::string;
using std::endl;
using std::cout;
using std::cin;



class Critter {
	
private:
	string name;  // name of critter
	bool moveThisTurn; // did critter move this turn
	int bCount;  // breed counter
	int eCount; // time to death counter
public:
	Critter();
	string getName();
	void setMoveThisTurn(bool);
	bool getMoveThisTurn();
	int move(); 
	void setName(string); 
	void seed(); 
	virtual bool breed(); 
	void eat(bool); 
	virtual bool death();
	int getBCount(); 
	int getECount(); 

};

#endif // !1


