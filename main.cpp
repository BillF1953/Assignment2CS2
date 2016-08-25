/*********************************************************************
** Program Filename: main.cpp
** Author: Tyler Forrester
** Date: 7/7/2016
** Description: A program simulates a simple predate prey model
** Input: An array of Critters
** Output: A text representation of critter movement
** Citations: http://ubuntuforums.org/showthread.php?t=1357606
********************************************************************/
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include "InputValid.hpp"



int main() {

	void jChange(int i, int j, int position, Critter *(&bArr)[20][20], bool breed); // prototype
	void iChange(int i, int j, int position, Critter*(&bArr)[20][20], bool breed); // prototype
	InputValid valid = InputValid(); // input validation
	const int size = 20;  // Grid Size
	Critter *bArr[size][size];
	string input = "";
	srand((unsigned)time(NULL));
	int count = 0;
	int count1 = 0;
	void wait(int seconds);
	cout << "\n";

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{

			bArr[i][j] = new Critter();  // initialize array to new critters


		}
	
	}

	

	for (int i = 0; i < 5;)
	{
		int j = rand() % 20;  // sets five dune bugs on the boards
		int k = rand() % 20;

		if (bArr[j][k]->getName() == ".")
		{
			delete bArr[j][k]; // deallocate heap memory 
			bArr[j][k] = new Doodlebug();
			i++;
		}

	}

	for (int h = 0; h < 100;)
	{
		int j = rand() % 20;  //sets 100 ants on the board
		int k = rand() % 20;

		if (bArr[j][k]->getName() == ".")
		{
			delete bArr[j][k]; // deallocate heap memory 
			bArr[j][k] = new Ant(); 
			h++;
		}

	} 

	/*********************************************************************
	** Section: Builds First Board
	** Description: Prints First Board asks user to start program
	** Parameters:
	** Pre-Conditions: main()
	** Post-Conditions: main()
	** Citation:
	*********************************************************************/
	
	
	do {
		cout << "Welcome to the Doodlebug and Ant Differential Equation" << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{

				cout << bArr[i][j]->getName() << " ";  // Builds First Board


			}
			cout << "\n";
		}

		cout << "\n";
		cout << "Enter c to continue." << endl;
		input = valid.validateChar();
	
	} while (input != "c");
	
	/*********************************************************************
	** Section: Preps for next turn
	** Description: Checks if Array is either empty or full; resets the moveCounter boolean
	** Parameters:
	** Pre-Conditions: main()
	** Post-Conditions: setMovethisTurn() Main()
	** Citation:
	*********************************************************************/
	do 
	{
		count = 0;
		count1 = 0; 
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				bArr[i][j]->setMoveThisTurn(false);  // resets if item moved this turn

				if (bArr[i][j]->getName() == "A" || bArr[i][j]->getName() == "D") {

					count++;       // counts number of D and A 
				}

				if (bArr[i][j]->getName() == ".") {


					count1++; // counts number of empty spaces
				}

			}
		}

		/*********************************************************************
		** Section: Movement
		** Description: Performs bound checks calls Movement functions
		** Parameters: 
		** Pre-Conditions: main() 
		** Post-Conditions: breed() jchange() and ichange() main()
		** Citation:
		*********************************************************************/
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{


					if ((bArr[i][j]->getName() != ".") && bArr[i][j]->getMoveThisTurn() == false)
					{	
						bool breed = bArr[i][j]->breed();  // calls breed function of Ant or Doodle
						//bool breed = true; Test Values
						//int move = 2;
						int move = bArr[i][j]->move(); // calls moves

						if (move == 1 && (j - 1) > -1)  // case 1 for move west only moves if on board
						{
							jChange(i, j, -1,  bArr, breed);  
						}
						
						else if (move == 2 && i + 1 < size) // case 2 for move south only moves if on board
						{
							iChange(i, j, 1, bArr, breed);
						}
						
						else if (move == 3 && j + 1 < size) // case 3 for move east only moves if on board
						{
							jChange(i, j, 1, bArr, breed);
						}
						
						else if (move == 4 && i - 1 > -1) // case 4 for move north only moves if on board
						{
				
							iChange(i, j, - 1, bArr, breed);
						}
						else {

							bArr[i][j]->eat(false); // moves counter of creatures who tried to move off the board
							if (bArr[i][j]->death())
							{
								delete bArr[i][j]; // deallocate heap memory 
								bArr[i][j] = new Critter();  // kills creature trying to move off the board
							}

						}

					}

				} 

			}
			
	
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{

				cout << bArr[i][j]->getName() << " "; // Prints out new board

			}



			cout << "\n";
		}


		cout << "\n"; 
	//	cout << count << "\n";
		wait(1); // calls sleep function to pause output
		// cout << "Enter a character to continue. Enter q to quit." << endl;  // test exit
	//input = valid.validateChar();
	}// while (input != "q");

	while ((count != 400 && count1 != 400)); // keeps going until Array is either all Ants and Doodlebugs or all blanks

}   
/*********************************************************************
** Function:  jchange
** Description: Performs movement of Critters east and west,  Represents Bred Creatures and Killed Creatures
** Parameters: int i , int j, inposition, Critter * bArr[20][20] and bool breed
** Pre-Conditions: main() breed()
** Post-Conditions:  eat() death() setMoveThisTurn() 
** Citation: 
*********************************************************************/

void jChange(int i, int j, int position, Critter  *(&bArr)[20][20], bool breed) {

	if (bArr[i][j]->getName() == "A" && bArr[i][j + position]->getName() == ".")
	{
		   bArr[i][j]->eat(false);
		if (bArr[i][j]->death())  // dies first
		{
			delete bArr[i][j]; // deallocate heap memory 
			bArr[i][j] = new Critter();
			
		}
		else
		{
			bArr[i][j + position] = bArr[i][j];  // must be unoccupied for an Ant
			bArr[i][j + position]->setMoveThisTurn(true);  // stores that move already happen to this space

			if (breed) 
			{
		
				bArr[i][j] = new Ant();  // ant is born on space
			}
			else 
			{
			
				bArr[i][j] = new Critter();  // space is returned to a blank
			}
		}
	}
	else if (bArr[i][j]->getName() == "D" && bArr[i][j + position]->getName() == ".")
	{
			bArr[i][j]->eat(false); // calls eat which is moves time counter
		if (bArr[i][j]->death()) {

			delete bArr[i][j]; // deallocate heap memory 
			bArr[i][j] = new Critter(); // kills doodlebug and replaces him with a critter
		}
		else {
			bArr[i][j + position] = bArr[i][j];  // must be unoccupied for to move
			bArr[i][j + position]->setMoveThisTurn(true);  // keep this board member from moving this turn
												 
			if (breed) {
			
				bArr[i][j] = new Doodlebug(); // creates new doodlebug
			}
			else {
			
				bArr[i][j] = new Critter(); // replaces board with Critter
			}
		}
	}
	else if (bArr[i][j]->getName() == "D" && bArr[i][j + position]->getName() == "A")
	{

		bArr[i][j]->eat(true); // ate ant time counter restes
		bArr[i][j + position] = bArr[i][j];
		bArr[i][j + position]->setMoveThisTurn(true);
		if (breed) {
			
			bArr[i][j] = new Doodlebug(); 
		}
		else {
		
			bArr[i][j] = new Critter();
		}
	}
	else
	{

		 bArr[i][j]->eat(false);
		if (bArr[i][j]->death())
		{

			delete bArr[i][j]; // deallocate heap memory 
			bArr[i][j] = new Critter();
		}


	}






}

/*********************************************************************
** Function:  iChange
** Description: Performs movement of Critters north and south,  Represents Bred Creatures and Killed Creatures
** Parameters: int i , int j, inposition, Critter * bArr[20][20] and bool breed
** Pre-Conditions: main() breed()
** Post-Conditions:  eat() death() setMoveThisTurn()
** Citation:
*********************************************************************/

void iChange(int i, int j, int position, Critter  *(&bArr)[20][20], bool breed) {

	if (bArr[i][j]->getName() == "A" && bArr[i + position][j]->getName() == ".")
	{
		 bArr[i][j]->eat(false);
		 if (bArr[i][j]->death())
		{
			delete bArr[i][j]; // deallocates memory to prevent memory links
			bArr[i][j] = new Critter();
		}
		else
		{
			bArr[i + position][j] = bArr[i][j];  // must be unoccupied for an Ant
			bArr[i + position][j]->setMoveThisTurn(true);  // stores that move already happen to this space

			if (breed) {
			
				bArr[i][j] = new Ant();
			}
			else {
			
				bArr[i][j] = new Critter();
				
			}
		}
	}
	else if (bArr[i][j]->getName() == "D" && bArr[i + position][j]->getName() == ".")
	{
		 bArr[i][j]->eat(false);
		if (bArr[i][j]->death()) {

			delete bArr[i][j];
			bArr[i][j] = new Critter();
		}
		else {
			bArr[i + position][j] = bArr[i][j];  // must unoccupied for D. 
			bArr[i + position][j]->setMoveThisTurn(true);  // stores
													
			if (breed) {
		
				bArr[i][j] = new Doodlebug();
			}
			else {

				bArr[i][j] = new Critter();
			}
		}
	}
	else if (bArr[i][j]->getName() == "D" && bArr[i + position][j]->getName() == "A")
	{

		 bArr[i][j]->eat(true);
		bArr[i + position][j] = bArr[i][j];
		bArr[i + position][j]->setMoveThisTurn(true);
		if (breed) {
		
			bArr[i][j] = new Doodlebug();
		}
		else {
		
			bArr[i][j] = new Critter();
		}
	}
	else
	{

		bArr[i][j]->eat(false);
		if (bArr[i][j]->death())
		{
			delete bArr[i][j]; // deallocates memory to prevent memory links
			bArr[i][j] = new Critter();
		}


	}



	} 

/*********************************************************************
** Function:  wait
** Description: Delays Board Movment
** Parameters: int seconds
** Pre-Conditions: main()
** Post-Conditions: main()
** Citation:  http://ubuntuforums.org/showthread.php?t=1357606 User "OVERPOWER8"  December 17th 2009 "3-way ClOCKS_PER_SEC
*********************************************************************/



void wait(int seconds)
{
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC; // slows down screen display 
	while (clock() < endwait) {}
}





