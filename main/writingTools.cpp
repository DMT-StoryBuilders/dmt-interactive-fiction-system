#include "writingTools.h"

void displayCreateMenu() {
	std::cout << "____________________________________________________" << std::endl;
	std::cout << "Creation Menu\n" << std::endl;
	std::cout << "1) Room" << std::endl;
	std::cout << "2) Door" << std::endl;
	std::cout << "3) Container" << std::endl;
	std::cout << "4) Individual" << std::endl;
	std::cout << "5) Item" << std::endl;
	std::cout << "0) Go Back" << std::endl;
}// end create menu display

void operateCreateMenu(std::vector<Room> &rmList, std::vector<Door> &drList, std::vector<Container> &crList, std::vector<Individual> &ilList, std::vector<Item> &imList) {
	int choice;
	std::cout << "\nWhat would you like to create?: ";
	std::cin >> choice;

	// As long as the user doesn't choose to go back to the main menu,
	// allow them to create the corresponding object and
	// then reprompt them afterwards
	while (choice != 0) {
		switch (choice) {
			case 1:
				createRoom(rmList, imList);
				break;
			case 2:
				createDoor(rmList, drList);
				break;
			case 3:
				createContainer(crList, imList);
				break;
			case 4:
				createIndividual(ilList, rmList, imList);
				break;
			case 5:
				createItem(imList);
				break;
		}//end switch choice

		displayCreateMenu();
		std::cout << "\nWhat would you like to create?: ";
		std::cin >> choice;
	}//end while choice
}//end create operation

void createRoom(std::vector<Room> &rmList, std::vector<Item> &imList) {
	std::cout << "____________________________________________________" << std::endl;
	std::cout << "Room Creation" << std::endl;

	std::string name;
	std::string shortDesc;
	std::string longDesc;
	int userInput;

	std::cout << "\nEnter the name of the room: " << std::endl;
	std::getline (std::cin, name);
	std::getline(std::cin, name);

	std::cout << "\nEnter a short description of the room: " << std::endl;
	std::getline(std::cin, shortDesc);

	std::cout << "\nEnter a long description of the room: " << std::endl;
	std::getline(std::cin, longDesc);

	// Create the room and add it to the end of the room list
	Room newRoom(name, shortDesc, longDesc);

	// Prompt the user if they would like to added created Items
	// into the room.
	std::cout << "\nAdd an item to this room? Yes(1) or No(0): ";
	std::cin >> userInput;

	// If the user chooses to add items, display the list of every
	// created item.
	if (userInput == 1) {
		std::cout << "\nItem List:" << std::endl;

		for (int i = 0; i < imList.size(); i++) {
			std::cout << i + 1 << ") " << imList[i].getName() << std::endl;
		}

		std::cout << "0) Cancel" << std::endl;

		// Prompt the user to select an item to add.
		std::cout << "\nAdd Item: ";
		std::cin >> userInput;

		// While the user doesn't enter 0 to cancel,
		// store the address of the selected item into the room's
		// inventory and reprompt them to add more.
		while (userInput != 0) {
			newRoom.addItem(&imList[userInput - 1]);

			std::cout << "\n" << imList[userInput - 1].getName()
				<< " has been added to the room." << std::endl;

			std::cout << "\nAdd Item: ";
			std::cin >> userInput;
		}
	}

	// Add the room to the created room list.
	rmList.push_back(newRoom);

	// Confirm that the room was created and display the number of created rooms
	std::cout << "\nRoom \"" << newRoom.getName() << "\" has been created." << std::endl;
	std::cout << "Number of rooms: " << rmList.size() << std::endl;
}

void createDoor(std::vector<Room>& rmList, std::vector<Door> &drList) {
	std::cout << "____________________________________________________" << std::endl;
	std::cout << "Door Creation" << std::endl;

	if (rmList.size() != 0) {
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
		newDoor.setRoomOne(&rmList[roomChoice - 1]);

		std::cout << "Second room: ";
		std::cin >> roomChoice;
		newDoor.setRoomTwo(&rmList[roomChoice - 1]);

		// Add the door to the end of the door list
		drList.push_back(newDoor);

		// Confirm that the door was created and display the number of created doors
		std::cout << "\nDoor \"" << newDoor.getName() << "\" has been created." << std::endl;
		std::cout << "Current number of doors: " << drList.size() << std::endl;
	}

	// If the room list is empty, display a message saying so.
	else {
		std::cout << "\nSorry, no room has been created yet. "
			<< "Please create one before creating a door." << std::endl;
	}
}

void createContainer(std::vector<Container> &crList, std::vector<Item> &imList) {
	std::cout << "____________________________________________________" << std::endl;
	std::cout << "Container Creation" << std::endl;

	std::string name;
	std::string desc;
	bool isAccessible;
	int userInput;

	std::cout << "\nEnter the name of the container: " << std::endl;
	std::getline(std::cin, name);
	std::getline(std::cin, name);

	std::cout << "\nEnter a description of the container: " << std::endl;
	std::getline(std::cin, desc);

	std::cout << "\nIs this container accessible? Yes(1) or No(0): ";
	std::cin >> isAccessible;

	Container newContainer(name, desc, isAccessible);

	//Prompt the user if they would like to added created Items
	//into the container.
	std::cout << "\nAdd an item to this container? Yes(1) or No(0): ";
	std::cin >> userInput;

	//If the user chooses to add items, display the list of every
	//created item.
	if (userInput == 1) {
		std::cout << "\nItem List:" << std::endl;

		for (int i = 0; i < imList.size(); i++) {
			std::cout << i + 1 << ") " << imList[i].getName() << std::endl;
		}

		std::cout << "0) Cancel" << std::endl;

		//Prompt the user to select an item to add.
		std::cout << "\nAdd Item: ";
		std::cin >> userInput;

		//While the user doesn't enter 0 to cancel,
		//store the address of the selected item into the container's
		//inventory and reprompt them to add more.
		while (userInput != 0) {
			newContainer.addItem(&imList[userInput - 1]);

			std::cout << "\n" << imList[userInput - 1].getName()
				<< " has been added to the container." << std::endl;

			std::cout << "\nAdd Item: ";
			std::cin >> userInput;
		}
	}

	//Once the user finished the container creation, add it to the end
	//of the created containers list.
	crList.push_back(newContainer);

	// Confirm that the container was created and display the number of created containers
	std::cout << "\nContainer \"" << newContainer.getName() << "\" has been created." << std::endl;
	std::cout << "Number of Containers: " << crList.size() << std::endl;
}

void createIndividual(std::vector<Individual> &ilList, std::vector<Room> &rmList, std::vector<Item> &imList){
	std::cout << "____________________________________________________" << std::endl;
	std::cout << "Individual Creation" << std::endl;

	if (rmList.size() != 0) {
			std::string name;
			std::string desc;
			int health;
			int userInput;

			std::cout << "\nEnter the name of the individual: " << std::endl;
			std::getline(std::cin, name);
			std::getline(std::cin, name);

			std::cout << "\nEnter a description of the individual: " << std::endl;
			std::getline(std::cin, desc);

			std::cout << "\nEnter the starting health of the individual: " << std::endl;
			std::cin >> health;

			Individual newIndividual(name, desc, health);

			// Display the list of every created room
			std::cout << "\nRoom List:" << std::endl;
			for (int i = 0; i < rmList.size(); i++) {
				std::cout << i + 1 << ") " << rmList[i].getName() << std::endl;
			}

			// Prompt the user to enter the starting point for the individual
			// and set their current room to that room.
			std::cout << "\nSelect the individual's starting room." << std::endl;
			std::cout << "Room: ";
			std::cin >> userInput;
			newIndividual.setCurrentRoom(&rmList[userInput - 1]);

			//Prompt the user if they would like to added created Items
			//into the individual's inventory.
			std::cout << "\nAdd an item to this individual's inventory? Yes(1) or No(0): ";
			std::cin >> userInput;

			//If the user chooses to add items, display the list of every
			//created item.
			if (userInput == 1) {
				std::cout << "\nItem List:" << std::endl;

				for (int i = 0; i < imList.size(); i++) {
					std::cout << i + 1 << ") " << imList[i].getName() << std::endl;
				}

				std::cout << "0) Cancel" << std::endl;

				//Prompt the user to select an item to add.
				std::cout << "\nAdd Item: ";
				std::cin >> userInput;

				//While the user doesn't enter 0 to cancel,
				//store the address of the selected item into the container's
				//inventory and reprompt them to add more.
				while (userInput != 0) {
					newIndividual.addItem(&imList[userInput - 1]);

					std::cout << "\n" << imList[userInput - 1].getName()
						<< " has been added to the individual's inventory." << std::endl;

					std::cout << "\nAdd Item: ";
					std::cin >> userInput;
				}
			}

			//Once the user finished the container creation, add it to the end
			//of the created containers list.
			ilList.push_back(newIndividual);

			// Confirm that the container was created and display the number of created containers
			std::cout << "\nIndividual \"" << newIndividual.getName() << "\" has been created." << std::endl;
			std::cout << "Number of Individuals: " << ilList.size() << std::endl;
	}

	// If the room list is empty, display a message saying so.
	else {
		std::cout << "\nSorry, no room has been created yet. "
			<< "Please create one before creating an individual." << std::endl;
	}
}

void createItem(std::vector<Item> &imList) {
	std::cout << "____________________________________________________" << std::endl;
	std::cout << "Item Creation" << std::endl;

	std::string name;
	std::string shortDesc;
	std::string longDesc;

	std::cout << "\nEnter the name of the item: " << std::endl;
	std::getline(std::cin, name);
	std::getline(std::cin, name);

	std::cout << "\nEnter a short description of the item: " << std::endl;
	std::getline(std::cin, shortDesc);

	std::cout << "\nEnter a long description of the item: " << std::endl;
	std::getline(std::cin, longDesc);

	Item newItem(name, shortDesc, longDesc);
	imList.push_back(newItem);

	// Confirm that the item was created and display the number of created items
	std::cout << "\nItem \"" << newItem.getName() << "\" has been created." << std::endl;
	std::cout << "Number of Items: " << imList.size() << std::endl;
}
