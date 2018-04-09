/********************
** Program name: Langton's Ant
** Author: Kelvin Lu
** Date: 09/27/2017
** Description: This is the main file for the execution of the Langton's Ant simulation. It includes the menu functions required for user input.
** EC: Program will randomize the starting location of the ant based on the user's request.
********************/

#include "Ant.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>

//Function prototypes
int twoOptionMenu(std::string a, std::string b);
int oneOptionMenu(std::string a);
int oneOptionRangeMenu(std::string a, int lower, int upper);
int validatePositiveRange(int lower, int upper);
int validatePositive();

int main()
{
	int choice;
	int startRow;
	int startCol;
	int counter = 0;

	//Repeat simulation until user wants to quit
	do
	{
		//Display start menu and get user's choice (only first time)
		if (counter == 0)
		{
			choice = twoOptionMenu("Start Langton's Ant simulation", "Quit");

			if (choice == 2)
			{
				return 0;
			}
			counter++;
		}

		//Get starting parameters from user including number of rows/columns, the starting row/column of the ant, and the number of moves
		int rows = oneOptionMenu("Enter the number of rows");
		int cols = oneOptionMenu("Enter the number of columns");
		int moves = oneOptionMenu("Enter the number of moves");

		//*EC: Give user the option to select whether to give the ant a random starting location or manually choose one.
		int startChoice = twoOptionMenu("Manually enter ant's start position", "Randomize ant's start position");		
		if (startChoice == 1)
		{
			startRow = oneOptionRangeMenu("Enter the starting row of the ant", 1, rows);
			startCol = oneOptionRangeMenu("Enter the starting column of the ant", 1, cols);
		} else
		{
			startRow = rand() % rows + 1;
			startCol = rand() % cols + 1;
		}

		//Insantiate an ant object with user's parameters.
		Ant ant(rows, cols, startRow, startCol);

		//Display the starting board
		ant.display();

		//Conduct moves equal to the user's input
		for (int i = 0; i < moves; i++)
		{
			ant.move();
		}

		//Deallocate memory used for board
		ant.deallocate();

		//Display and validate menu asking user if they want to try again or quit
		std::cout << std::endl;
		choice = twoOptionMenu("Play Again", "Quit");

	} while (choice == 1);
}


//Two option menu with input validation
int twoOptionMenu(std::string a, std::string b)
{
	std::cout << "1. " << a << std::endl;
	std::cout << "2. " << b << std::endl;
	std::cout << "Please enter your choice: ";
	return validatePositiveRange(1, 2);
}

//One option menu with positive integer input validation
int oneOptionMenu(std::string a)
{
	std::cout << a << ": ";
	return validatePositive();
}

/*One option menu with positive integer and range input validation
 *Precondition: Lower < Upper
 */
int oneOptionRangeMenu(std::string a, int lower, int upper)
{
	std::cout << a << " (" << lower << "-" << upper << ") : ";
	return validatePositiveRange(lower, upper);
}

/*Function to get a user's input and check that it is a valid integer within the lower to upper range inclusive. It will return the integer if valid.
 *Precondition: Lower < Upper
 */
int validatePositiveRange(int lower, int upper)
{
	int input;
	bool rangeAgain = true;
	
	//Loop endlessly until user provides a valid input
	do
	{
		//validate input is a positive integer
		input = validatePositive();

		//Return input if input is within range
		if (input >= lower && input <= upper)
		{
			return input;
		}

		//If not, display this error message and prompt the user to try again
		std::cout << "Not in range- Please enter an integer between " << lower << " and " << upper << ": ";
	} while (rangeAgain);
	
	//function should never reach here, but if it does restart
	return validatePositiveRange(lower, upper);
}

//Function to get a user's input and check if it is a positive integer. It will return the integer if valid.
int validatePositive()
{
	std::string input;
	bool again;

	//Loop endlessly until user provides a valid input
	do
	{

		getline(std::cin, input);
		again = false;
		//If first character is 0 or the string is null, print error and have user re-enter input
		if (input.length() == 0 || input[0] == '0')
		{
			again = true;
		}

		//If any character is non-numerical, print error and have user re-enter input
		if (!again)
		{
			for (int i = 0; i < static_cast<int>(input.length()); i++)
			{
				if (!isdigit(input[i]))
				{
					again = true;
				}
			}
		}

		//If input passes all of the tests, return the input as an integer
		if (!again)
		{
			return stoi(input);
		}

		//If input did not pass all the tests, have user try again
		std::cout << "Invalid format- Please enter a positive integer: ";
	} while (again);

	//function should never reach here, but if it does restart
	return validatePositive();
}