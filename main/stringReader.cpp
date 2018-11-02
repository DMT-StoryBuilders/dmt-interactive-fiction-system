#include <string>
#include <iostream>
#include <vector>
#include "pch.h"
#include "stringReader.h"
#include "Player.h"
#include "Room.h"
#include "Door.h"

void stringBreaker(Player &player, std::string inputString, std::vector<Room> &rmList, std::vector<Door> &drList) //Breaks up the Input into a arrays of string words
{

	std::vector <std::string> stringWords;

	std::string tempNewWords;
	std::string userInput = inputString;	

	userInput += toupper(' ');

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
			transform(tempNewWords.begin(), tempNewWords.end(), tempNewWords.begin(), ::toupper);
			stringWords.push_back(tempNewWords);
			vectorWordsCounter++;
			tempNewWords = "";
		}

	}//End of the for loop

	stringFindAction(player, userInput, stringWords,rmList,drList);
}

/*
	Using bool we will find out what the user input is trying to say.
	Based on what bools and words are used the action taken will be determined
	bool wordAttackingFound Checks for any words that might mean the player is attacking something
	bool wordSearchingFound Checks for any words that might mean the player is seaching for something
	bool wordInteractingFound Checks for any words that might mean the player is Interactioning with something
*/

void stringFindAction(Player &player, std::string userInput, std::vector <std::string> &stringWords, std::vector<Room> &rmList, std::vector<Door> &drList) // FIND the action word in the string 
{
	int currentRoom = -1;
	int currentDoor = -1;
	int foundRoom = -1;
	int foundDoor = -1;
	int roomNumber = -1;
	int doorNumber = -1;
	int doorNameLength;
	int roomNameLength;

	bool wordAttackingFound = false; //True if found an attack word
	bool wordLookingFound = false; 
	bool wordSearchingFound = false; // True if found an searching word
	bool wordInteractingFound = false;
	bool wordUseFound = false;
	bool wordItemFound = false;
	bool inputHasDoor = false;
	bool inputHasRoom = false;

	std::string doorName;
	std::string roomName;
	std::string doorNameChecker;
	std::string roomNameChecker;

	transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);


	int stopper = 0;

	for (int i = 0; i < drList.size(); i++) // Checking the name of door was used
	{
		
		doorName = ( drList.at(i).getName() ); 
		transform(doorName.begin(), doorName.end(), doorName.begin(), ::toupper);
		doorNumber = i;
		doorNameLength = drList.at(i).getName().size();
		foundDoor = userInput.find(doorName);
		
		if (foundDoor > -1) 
		{
			doorNameChecker = userInput.substr(foundDoor, foundDoor + doorNameLength);
			transform(doorNameChecker.begin(), doorNameChecker.end(), doorNameChecker.begin(), ::toupper);
		}

		if (foundDoor > -1 && doorName.compare(doorNameChecker))
		{
			currentDoor = i;
			inputHasDoor = true;
		}
		foundDoor = -1;
		doorName = "No door found";
	}

	for (int j = 0; j < rmList.size(); j++)
	{
		roomName = rmList.at(j).getName();
		transform(roomName.begin(), roomName.end(), roomName.begin(), ::toupper);
		foundRoom = userInput.find(roomName);
		roomNumber = j;
		roomNameLength = rmList.at(j).getName().size();


		if (foundRoom > -1)
		{
			roomNameChecker = userInput.substr(foundRoom, foundRoom + roomNameLength);
			transform(roomNameChecker.begin(), roomNameChecker.end(), roomNameChecker.begin(), ::toupper);

		}

		if (foundRoom > -1 && roomName.compare(roomNameChecker))
		{
			currentRoom = j;
			inputHasRoom = true;
		}
		foundRoom = -1;
		roomName = "No room found";
	}

	std::cout << std::endl;

	for (int x = 0; x < stringWords.size(); x++)// The loop that looks for action words
	{
		if (stringWords.at(x) == "ATTACK" || stringWords.at(x) == "ATTACKED" || stringWords.at(x) == "ATTACKING")
		{
			wordAttackingFound = true;
		}
		if (stringWords.at(x) == "USE" || stringWords.at(x) == "USING" || stringWords.at(x) == "OPEN" )
		{
			wordUseFound = true;
		}
		if (stringWords.at(x) == "ITEM")
		{
			wordItemFound = true;
		}
		if (stringWords.at(x) == "SEARCH" || stringWords.at(x) == "EXAMINE" || stringWords.at(x) == "STUDY" || stringWords.at(x) == "ANALYSIS")
		{
			wordSearchingFound = true;
		}
		if (stringWords.at(x) == "LOOK" || stringWords.at(x) == "VIEW" || stringWords.at(x) == "OBSERVE")
		{
			wordLookingFound = true;
		}
		if (stringWords.at(x) == "LEVER")
		{
			wordInteractingFound = true;
		}
	}
		
	if (wordSearchingFound == true && inputHasDoor == true) //looking at doors
	{
		player.examine(&drList.at(currentDoor));
	}

	if (wordLookingFound == true && inputHasDoor == true) //looking at doors short
	{
		player.observe(&drList.at(currentDoor));
	}

	if (wordUseFound == true && inputHasDoor == true) // using a door
	{
		player.use(&drList[currentDoor]);
		std::cout << std::endl;
		std::cout << player.getCurrentRoom()->getName() << std::endl;
		std::cout << player.getCurrentRoom()->getShortDescription();
		std::cout << std::endl << "______________________________________________" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "> ";

	
	}

	if (wordSearchingFound == true && inputHasRoom == true)
	{
		player.examine(&rmList.at(currentRoom));
	}

	if (wordLookingFound == true && inputHasRoom == true)
	{
		player.observe(&rmList.at(currentRoom));
	}

	if (wordLookingFound == false && wordInteractingFound == false && wordSearchingFound == false && wordItemFound == false && wordUseFound == false && wordAttackingFound == false)
	{
		std::cout << std::endl << " umm what? lets get the debug and find out what happened";
		std::cout << std::endl;
		std::cout << "Debug: ";
		std::cout << std::endl << " has founded looking key word: " << wordLookingFound;
		std::cout << std::endl << " has founded searching key word: " << wordSearchingFound;
		std::cout << std::endl << " has founded has door? " << inputHasDoor;
		std::cout << std::endl << " has founded has room? = " << inputHasRoom;
		std::cout << std::endl << " what is door vector vaule  " << doorNumber;
		std::cout << std::endl << "roomName = " << roomName << std::endl;
		std::cout << std::endl << "Room name checker " << roomNameChecker << std::endl;
		std::cout << std::endl << "Door name checker " << doorNameChecker << std::endl;
		std::cout << std::endl << "roomname " << roomName;
		std::cout << std::endl << "doorname " << doorName;
		std::cout << std::endl << "current Room number " << currentRoom;
		std::cout << std::endl << "current Room number " << currentDoor;

	}

	/*
	std::cout << std::endl << std::endl;
	std::cout << "Debug: a word was found    ___ user input was " << userInput;
	std::cout << std::endl;

	
	for (int k = 0; k < rmList.size(); k++)
	{
		std::cout << std::endl << rmList.at(k).getName();
	}

	
	std::cout << std::endl << " has founded looking key word: " << wordLookingFound;
	std::cout << std::endl << " has founded look key word: " << wordSearchingFound;
	std::cout << std::endl << " has founded has door? " << inputHasDoor;
	std::cout << std::endl << " has founded has room? = " << inputHasRoom;
	std::cout << std::endl << " what is door vector vaule  " << doorNumber;
	std::cout << std::endl << "roomName = " << roomName << std::endl;
	std::cout << std::endl << "Room name checker " << roomNameChecker << std::endl;
	std::cout << std::endl << "Door name checker " << doorNameChecker << std::endl;
	std::cout << std::endl << "roomname " << roomName;
	std::cout << std::endl << "doorname " << doorName;
	std::cout << std::endl << "current Room number " << currentRoom;
	std::cout << std::endl << "current Room number " << currentDoor;
	std::cout << std::endl << "current Room number " << wordUseFound;
	*/

	currentRoom = -1;
	currentDoor = -1;
	foundRoom = -1;
	foundDoor = -1;
	roomNumber = -1;
	doorNumber = -1;

	wordAttackingFound = false; 
	wordSearchingFound = false; 
	wordInteractingFound = false;
	wordUseFound = false;
	wordItemFound = false;
	inputHasDoor = false;
	inputHasRoom = false;

	doorName = "";
	roomName = "";
	doorNameChecker = "";
	roomNameChecker = "";

}


