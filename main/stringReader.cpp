#include <string>
#include <iostream>
#include <vector>
#include "pch.h"
#include "stringReader.h"
#include "Player.h"
#include "Room.h"
#include "Door.h"


void stringBreaker(std::string inputString, std::vector<Room> &rmList, std::vector<Door> &drList) //Breaks up the Input into a arrays of string words
{
	std::vector <std::string> stringWords;

	std::string tempNewWords;
	std::string userInput = inputString;	
	userInput += " ";
	std::cout << userInput;

	int vectorWordsCounter = 0;
	int stringCoutnerCharacter = 0;

	char currentcharacter = ' ';

	int wordFindFound = 0;

	
	for (int stringCoutnerCharacter = 0; stringCoutnerCharacter < userInput.length(); stringCoutnerCharacter++)
	{
		if (toupper(userInput.at(stringCoutnerCharacter)) == 'A' || toupper(userInput.at(stringCoutnerCharacter)) == 'B' || toupper(userInput.at(stringCoutnerCharacter)) == 'C' || toupper(userInput.at(stringCoutnerCharacter)) == 'D' || toupper(userInput.at(stringCoutnerCharacter)) == 'E' || toupper(userInput.at(stringCoutnerCharacter)) == 'F' || toupper(userInput.at(stringCoutnerCharacter)) == 'G' || toupper(userInput.at(stringCoutnerCharacter)) == 'H' || toupper(userInput.at(stringCoutnerCharacter)) == 'I' || toupper(userInput.at(stringCoutnerCharacter)) == 'J' || toupper(userInput.at(stringCoutnerCharacter)) == 'K' || toupper(userInput.at(stringCoutnerCharacter)) == 'L' || toupper(userInput.at(stringCoutnerCharacter)) == 'M' || toupper(userInput.at(stringCoutnerCharacter)) == 'N' || toupper(userInput.at(stringCoutnerCharacter)) == 'O' || toupper(userInput.at(stringCoutnerCharacter)) == 'P' || toupper(userInput.at(stringCoutnerCharacter)) == 'Q' || toupper(userInput.at(stringCoutnerCharacter)) == 'R' || toupper(userInput.at(stringCoutnerCharacter)) == 'S' || toupper(userInput.at(stringCoutnerCharacter)) == 'T' || toupper(userInput.at(stringCoutnerCharacter)) == 'U' || toupper(userInput.at(stringCoutnerCharacter)) == 'V' || toupper(userInput.at(stringCoutnerCharacter)) == 'W' || toupper(userInput.at(stringCoutnerCharacter)) == 'S' || toupper(userInput.at(stringCoutnerCharacter)) == 'W' || toupper(userInput.at(stringCoutnerCharacter)) == 'X' || toupper(userInput.at(stringCoutnerCharacter)) == 'Y' || toupper(userInput.at(stringCoutnerCharacter) == 'Z'))	
		{
			tempNewWords += toupper(userInput.at(stringCoutnerCharacter));
		}

		else
		{
			stringWords.push_back(tempNewWords);
			vectorWordsCounter++;
			std::cout << tempNewWords << std::endl;
			tempNewWords = "";
		}

	}//End of the for loop

	stringFindAction(stringWords,rmList,drList);
}







void stringFindAction(std::vector <std::string> &stringWords, std::vector<Room> &rmList, std::vector<Door> &drList) // FIND the action word in the string 
{
	/*Using bool we will find out what the user input is trying to say.
	Based on what bools and words are used the action taken will be determined
	bool wordAttackingFound Checks for any words that might mean the player is attacking something
	bool wordSearchingFound Checks for any words that might mean the player is seaching for something
	bool wordInteractingFound Checks for any words that might mean the player is Interactioning with something
	*/

	bool wordAttackingFound = false; //True if found an attack word
	bool wordSearchingFound = false; // True if found an searching word
	bool wordInteractingFound = false;
	bool wordDoorFound = false;
	int stopper = 0;
	bool wordItemFound = false;

	for (int x = 0; x < stringWords.size(); x++)
	{
		if (stringWords.at(x) == "ATTACK" || stringWords.at(x) == "ATTACKED" || stringWords.at(x) == "ATTACKING")
		{
			std::cout<< " attacking " << std::endl;
			wordAttackingFound = true;
		}
		if (stringWords.at(x) == "DOOR")
		{
			std::cout << std::endl << "the door " << std::endl;
			wordDoorFound = true;
		}
		if (stringWords.at(x) == "ITEM")
		{
			std::cout << std::endl << " using the item " << std::endl;
			wordItemFound = true;
		}
		if (stringWords.at(x) == "LOOK")
		{
			std::cout << std::endl << " looking at " << std::endl;
			wordSearchingFound = true;
		}
		if (stringWords.at(x) == "LEVER")
		{
			std::cout << std::endl << "found interactions word " << std::endl;
			wordInteractingFound = true;
		}
	}
	
//_________________________________________________________________________________

}


