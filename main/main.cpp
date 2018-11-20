#include "exportWorld.h"
#include "importWorld.h"
#include "writingTools.h"
#include "playFunctions.h"
#include "tinyxml2.h"

void displayMainMenu();
void operateMainMenu(std::vector<Room> &rmList, std::vector<Door> &drList, std::vector<Container> &crList, std::vector<Item> &imList);

int main()
{
	std::vector<Room> roomList;
	std::vector<Door> doorList;
	std::vector<Container> containerList;
	std::vector<Individual> individualList;
	std::vector<Item> itemList;

    displayMainMenu();
	operateMainMenu(roomList, doorList, containerList, itemList);

	return 0;
}

// Function that displays the options for the main menu
void displayMainMenu() {
	std::cout << "____________________________________________________" << std::endl;
	std::cout << "Main Menu\n" << std::endl;
	std::cout << "1) Create" << std::endl;
	std::cout << "2) Import World" << std::endl;
	std::cout << "3) Export World" << std::endl;
	std::cout << "4) Play" << std::endl;
	std::cout << "0) Quit" << std::endl;
}

// Function that allows user to operate the main menu
void operateMainMenu(std::vector<Room> &rmList, std::vector<Door> &drList, std::vector<Container> &crList, std::vector<Item> &imList) {
	int choice;
	std::cout << "\nWhat would you like to do?: ";
	std::cin >> choice;

	// As long as the user chooses to not play the game,
	// execute their command and reprompt them after
	// the function finishes.
	while (choice != 4) {
		switch (choice) {
		case 0:
			exit(0);
			break;
		case 1:
			displayCreateMenu();
			operateCreateMenu(rmList, drList, crList, imList);
			break;
		case 2:
			loadDocument(rmList, drList);
			break;
		case 3:
			createDocument(rmList, drList);
			break;
		}

		displayMainMenu();
		std::cout << "\nWhat would you like to do?: ";
		std::cin >> choice;
	}

	if (choice == 4) {
		startGame(rmList, drList);
	}
}
