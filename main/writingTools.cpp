#include "pch.h"
#include "writingTools.h"

void displayCreateMenu() {
	std::cout << "____________________________________________________" << std::endl;
	std::cout << "Creation Menu\n" << std::endl;
	std::cout << "1) Room" << std::endl;
	std::cout << "2) Door" << std::endl;
	std::cout << "0) Go Back" << std::endl;
}//end create menu display

void operateCreateMenu(std::vector<Room> &rmList, std::vector<Door> &drList) {
	int choice;
	std::cout << "\nWhat would you like to create?: ";
	std::cin >> choice;

	// As long as the user doesn't choose to go back to the main menu,
	// allow them to create the corresponding object and 
	// then reprompt them afterwards
	while (choice != 0) {
		switch (choice) {
			// create room
			case 1:
				createRoom(rmList);
				break;
			// create door
			case 2:
				createDoor(rmList, drList);
				break;
		}//end switch choice

		displayCreateMenu();
		std::cout << "\nWhat would you like to create?: ";
		std::cin >> choice;
	}//end while choice
}//end create operation

void createRoom(std::vector<Room> &rmList) {
	std::cout << "____________________________________________________" << std::endl;
	std::cout << "Room Creation" << std::endl;
	std::string name;
	std::string longDesc;
	std::string shortDesc;

	std::cout << "\nEnter the name of the room: " << std::endl;
	std::getline (std::cin, name);
	std::getline(std::cin, name);

	std::cout << "\nEnter a long description of the room: " << std::endl;
	std::getline(std::cin, longDesc);

	std::cout << "\nEnter a short description of the room: " << std::endl;
	std::getline(std::cin, shortDesc);

	// Create the room and add it to the end of the room list
	Room newRoom(name, longDesc, shortDesc);
	rmList.push_back(newRoom);

	// Confirm that the room was created and display the number of created rooms
	std::cout << "\nRoom \"" << newRoom.getName() << "\" has been created." << std::endl;
	std::cout << "Number of rooms: " << rmList.size() << std::endl;
}

void createDoor(std::vector<Room>& rmList, std::vector<Door>& drList) {
	std::cout << "____________________________________________________" << std::endl;
	std::cout << "Door Creation" << std::endl;
	std::string name;
	std::string desc;
	bool isAccessible;

	int roomChoice;

	std::cout << "\nEnter the name of the door: " << std::endl;
	std::getline(std::cin, name);
	std::getline(std::cin, name);

	std::cout << "\nEnter a description of the door: " << std::endl;
	std::getline(std::cin, desc);

	std::cout << "\nIs this door accessible? Yes(1) or No(0): ";
	std::cin >> isAccessible;

	// Create the Door object
	Door newDoor(name, desc, isAccessible);

	// Display the list of every created room
	std::cout << "\nRoom List:" << std::endl;
	for (int i = 0; i < rmList.size(); i++) {
		std::cout << i + 1 << ") " << rmList[i].getName() << std::endl;
	}

	// Prompt the user to choose the two rooms that will be connected to the door
	std::cout << "\nEnter the numbers of the two rooms will connect to the door." << std::endl;
	std::cout << "First room: ";
	std::cin >> roomChoice;
	newDoor.setRoomOne(rmList[roomChoice - 1]);

	std::cout << "Second room: ";
	std::cin >> roomChoice;
	newDoor.setRoomTwo(rmList[roomChoice - 1]); 

	// Add the door to the end of the door list
	drList.push_back(newDoor);

	// Confirm that the door was created and display the number of created doors
	std::cout << "\nDoor \"" << newDoor.getName() << "\" has been created." << std::endl;
	std::cout << "Current number of doors: " << drList.size() << std::endl;
}