#include "pch.h"
#include "writingTools.h"
#include "playFunctions.h"
#include "stringReader.h"

void displayMainMenu();
void operateMainMenu(std::vector<Room> &rmList, std::vector<Door> &drList);
std::vector <std::string> actionWordBank;


int main()
{
	std::vector<Room> roomList;
	std::vector<Door> doorList;
    displayMainMenu();
	operateMainMenu(roomList, doorList);
}

// Function that displays the options for the main menu
void displayMainMenu() {
	std::cout << "____________________________________________________" << std::endl;
	std::cout << "Main Menu\n" << std::endl;
	std::cout << "1) Create" << std::endl;
	std::cout << "2) Play" << std::endl;
	std::cout << "3) Demo String reader" << std::endl;

}

// Function that allows user to operate the main menu
void operateMainMenu(std::vector<Room> &rmList, std::vector<Door> &drList) {
	int choice;
	std::string inputString;
	std::cout << "\nWhat would you like to do?: ";
	std::cin >> choice;

	// As long as the user chooses to not play the game,
	// allow them to create an entity and reprompt them
	// afterwards.
	while (choice != 2) {
		if (choice == 1) {
			displayCreateMenu();
			operateCreateMenu(rmList, drList);
		}
		else if (choice == 3) {
			
			std::cout << std::endl << std::endl << "THE LINE THAT THE EVIL PEOPLE WILL TYPE IN GAME " << std::endl << std::endl << std::endl;

			std::getline(std::cin, inputString);
			std::getline(std::cin, inputString);



			stringBreaker(inputString, rmList, drList);
		}
		
		displayMainMenu();
		std::cout << "\nWhat would you like to do?: ";
		std::cin >> choice;
	}


	if (choice == 2) {
		startGame(rmList, drList);
	}
}