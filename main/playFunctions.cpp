#include "pch.h"
#include "playFunctions.h"

void startGame(std::vector<Room> &rmList, std::vector<Door> &drList) {
	Player player;
	player.setCurrentRoom(&rmList[0]);

	std::cout << "____________________________________________________" << std::endl;
	std::cout << player.getCurrentRoom()->getName() << std::endl;
	std::cout << player.getCurrentRoom()->getShortDescription() << std::endl;
	
	std::string action;
	std::cout << "\n> ";
	std::cin >> action;
	transform(action.begin(), action.end(), action.begin(), ::tolower);

	while (action != "quit") {
		if (action == "use") {
			playerUse(player, drList);
		}

		else if (action == "observe") {
			playerObserve(player, rmList, drList);
		}

		else if (action == "examine") {
			playerExamine(player, rmList, drList);
		}

		std::cout << "\n> ";
		std::cin >> action;
		transform(action.begin(), action.end(), action.begin(), ::tolower);
	}//end while not quit action
}

void playerUse(Player &player, std::vector<Door>& drList) {
	std::string nameInput;
	std::string currentObjectName;

	// Prompt the player to enter the name of the object
	// that they wish to use and convert all characters to lowercase.
	std::cout << "\n> Use ";
	getline(std::cin, nameInput);
	getline(std::cin, nameInput);
	transform(nameInput.begin(), nameInput.end(), nameInput.begin(), ::tolower);

	for (int i = 0; i < drList.size(); i++) {

		// Assign the name of the currrent door and convert all characters to lowercase
		currentObjectName = drList[i].getName();
		transform(currentObjectName.begin(), currentObjectName.end(), currentObjectName.begin(), ::tolower);

		// Compare the name of the current door and the user's input.
		// If they are the same, the player will use with that door.
		if (currentObjectName == nameInput) {
			player.use(&drList[i]);
			std::cout << "____________________________________________________" << std::endl;
			std::cout << player.getCurrentRoom()->getName() << std::endl;
			std::cout << player.getCurrentRoom()->getShortDescription() << std::endl;
		}//end if names are equivalent
	}//end for door list
}

void playerObserve(Player &player, std::vector<Room>& rmList, std::vector<Door>& drList) {
	std::string nameInput;
	std::string currentObjectName;

	// Prompt the player to enter the name of the object
	// that they wish to use and convert all characters to lowercase.
	std::cout << "\n> Observe ";
	getline(std::cin, nameInput);
	getline(std::cin, nameInput);
	transform(nameInput.begin(), nameInput.end(), nameInput.begin(), ::tolower);

	for (int i = 0; i < rmList.size(); i++) {

		// Assign the name of the currrent room and convert all characters to lowercase
		currentObjectName = rmList[i].getName();
		transform(currentObjectName.begin(), currentObjectName.end(), currentObjectName.begin(), ::tolower);

		// Compare the name of the room and the player's input.
		// If they are the same, the player will observe that room.
		if (currentObjectName == nameInput) {
			player.observe(&rmList[i]);
		}//end if names are equivalent
	}//end for room list

	// Functions similarly to the previous loop, but this one is for doors
	for (int i = 0; i < drList.size(); i++) {

		currentObjectName = drList[i].getName();
		transform(currentObjectName.begin(), currentObjectName.end(), currentObjectName.begin(), ::tolower);

		if (currentObjectName == nameInput) {
			player.observe(&drList[i]);
		}//end if names are equivalent
	}//end for door list
}

void playerExamine(Player &player, std::vector<Room>& rmList, std::vector<Door>& drList) {
	std::string nameInput;
	std::string currentObjectName;

	// Prompt the player to enter the name of the object
	// that they wish to use and convert all characters to lowercase.
	std::cout << "\n> Examine ";
	getline(std::cin, nameInput);
	getline(std::cin, nameInput);
	transform(nameInput.begin(), nameInput.end(), nameInput.begin(), ::tolower);

	for (int i = 0; i < rmList.size(); i++) {

		// Assign the name of the currrent room and convert all characters to lowercase
		currentObjectName = rmList[i].getName();
		transform(currentObjectName.begin(), currentObjectName.end(), currentObjectName.begin(), ::tolower);

		// Compare the name of the room and the player's input.
		// If they are the same, the player will examine that room.
		if (currentObjectName == nameInput) {
			player.examine(&rmList[i]);
		}//end if names are equivalent
	}//end for room list

	// Functions similarly to the previous loop, but this one is for doors
	for (int i = 0; i < drList.size(); i++) {

		currentObjectName = drList[i].getName();
		transform(currentObjectName.begin(), currentObjectName.end(), currentObjectName.begin(), ::tolower);

		if (currentObjectName == nameInput) {
			player.examine(&drList[i]);
		}//end if names are equivalent
	}//end for door list
}