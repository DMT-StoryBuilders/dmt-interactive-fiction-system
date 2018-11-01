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
	
	//std::cout << userInput;
	



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
			// std::cout << tempNewWords << std::endl;
			tempNewWords = "";
		}

	}//End of the for loop

	stringFindAction(userInput, stringWords,rmList,drList);
}







void stringFindAction(std::string userInput, std::vector <std::string> &stringWords, std::vector<Room> &rmList, std::vector<Door> &drList) // FIND the action word in the string 
{
	/*Using bool we will find out what the user input is trying to say.
	Based on what bools and words are used the action taken will be determined
	bool wordAttackingFound Checks for any words that might mean the player is attacking something
	bool wordSearchingFound Checks for any words that might mean the player is seaching for something
	bool wordInteractingFound Checks for any words that might mean the player is Interactioning with something
	*/

	int currentRoom = 0;
	int currentDoor;
	int foundRoom = -1;
	int foundDoor = -1;
	int roomNumber = -1;

	bool wordAttackingFound = false; //True if found an attack word
	bool wordSearchingFound = false; // True if found an searching word
	bool wordInteractingFound = false;
	bool wordDoorFound = false;
	bool wordItemFound = false;
	int stopper = 0;


	for (int i = 0; i < drList.size(); i++)
	{
		std::string Doorname;
		Doorname = drList.at(i).getName(); 
		foundDoor = userInput.find(Doorname);
		if (foundDoor > 0) 
		{
			currentDoor = i;
			std::cout << "Found the door called:" << Doorname;
		}
	}

	for (int j = 0; j < rmList.size(); j++)
	{

		std::string roomName;

		roomName = rmList.at(j).getName();

		int foundRoom = userInput.find(roomName);
		roomNumber = j;
		if (foundRoom > 0)

		{
			currentRoom = foundRoom;
			std::cout << "Found the room called: " << roomName;
			std::cout << std::endl;
			std::cout << " number " << roomNumber;
			
		}
	}
	std::cout << std::endl;

	for (int x = 0; x < stringWords.size(); x++)
	{

		if (stringWords.at(x) == "ATTACK" || stringWords.at(x) == "ATTACKED" || stringWords.at(x) == "ATTACKING")
		{
			std::cout<< " attacking ";
			wordAttackingFound = true;
		}
		
		if (stringWords.at(x) == "USE")
		{
			std::cout << "the door ";
			wordDoorFound = true;
		}
		if (stringWords.at(x) == "ITEM")
		{
			std::cout << " using/with the item ";
			wordItemFound = true;
		}
		if (stringWords.at(x) == "LOOK")
		{
			std::cout << " looking at ";
			wordSearchingFound = true;

		}
		if (stringWords.at(x) == "LEVER")
		{
			std::cout << "found interactions word ";
			wordInteractingFound = true;
		}
		std::cout << std::endl;
	}
	
	std::cout << "  " << roomNumber << std::endl;
	if (wordSearchingFound == true && roomNumber >= 0)
	{
		std::cout << "As you look around you find : ";
		rmList.at(roomNumber).getLongDescription();
		std::cout << rmList.at(roomNumber).getLongDescription() << std::endl ;
	}

	if (wordInteractingFound == false && wordSearchingFound == false && wordItemFound == false && wordDoorFound == false && wordAttackingFound == false)
	{
		std::cout << std::endl << "I HAVE NO IDEA WHAT YOU ARE SAYING BRAIN " << std::endl << " ";
	}
	
}


