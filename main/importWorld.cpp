#include "importWorld.h"

void loadDocument(std::vector<Room>& rmList, std::vector<Door>& drList, std::vector<Container> &crList, std::vector<Individual> &ilList, std::vector<Item> &imList) {
	std::string savePath;

	std::cout << "____________________________________________________" << std::endl;
	std::cout << "World Import" << std::endl;
	std::cout << "\nEnter a path for the save location.\n"
		<< "\nWindows Ex) C:\\Users\\Username\\Documents\\mySavedWorld.xml"
		<< "\n\nPath: ";

	std::cin >> savePath;

	/* Because tinyxml2's file saving function only take in a character array
	 * for the file path,
	 * the contents of the string must be stored in a char array.
	 */
	char savePathChars[80];
	strcpy(savePathChars, savePath.c_str());

	tinyxml2::XMLDocument worldDocument;
	worldDocument.LoadFile(savePathChars);

	tinyxml2::XMLNode* worldNodePtr = worldDocument.FirstChild();

	// Create item objects before rooms, containers, and individuals since they
	// may require those items to exist before being added to their inventories.
	// Also, create door objects before room objects since they require rooms to
	// exist before connecting to them.
	createItemObjects(worldDocument, worldNodePtr, imList);
	createRoomObjects(worldDocument, worldNodePtr, rmList, imList);
	createDoorObjects(worldDocument, worldNodePtr, drList, rmList);
	createContainerObjects(worldDocument, worldNodePtr, crList, rmList, imList);
	createIndividualObjects(worldDocument, worldNodePtr, ilList, rmList, imList);
}// end load document

void createItemObjects(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Item> &imList) {
	tinyxml2::XMLElement* itemElementPtr;
	tinyxml2::XMLElement* dataElementPtr;
	const char* dataChars;

	// Have the item element pointer find the first item element
	itemElementPtr = wNodePtr->FirstChildElement("item");

	// Loop that runs as long as there are still unprocessed item elements in the document
	while (itemElementPtr != nullptr) {

		// Have the data element pointer find the name element.
		// Once found, store the contents of the name element in a string variable.
		dataElementPtr = itemElementPtr->FirstChildElement("name");
		dataChars = dataElementPtr->GetText();
		std::string nm(dataChars);

		// Have the data element pointer find the short description element.
		// Once found, store the contents of the short description element in a string variable.
		dataElementPtr = itemElementPtr->FirstChildElement("shortDescription");
		dataChars = dataElementPtr->GetText();
		std::string shortDesc(dataChars);

		// Have the data element pointer find the long description element.
		// Once found, store the contents of the long description element in a string variable.
		dataElementPtr = itemElementPtr->FirstChildElement("longDescription");
		dataChars = dataElementPtr->GetText();
		std::string longDesc(dataChars);

		// Create a new item object from the acquired information,
		// and add it to the item list.
		Item newItem(nm, shortDesc, longDesc);
		imList.push_back(newItem);

		// Set the item element pointer to the next item element.
		itemElementPtr = itemElementPtr->NextSiblingElement("item");
	}// end while loop
}// end create item

void createRoomObjects(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Room> &rmList, std::vector<Item> &imList) {
	tinyxml2::XMLElement* roomElementPtr;
	tinyxml2::XMLElement* dataElementPtr;
	const char* dataChars;

	// Have the room element pointer find the first room element
	roomElementPtr = wNodePtr->FirstChildElement("room");

	// Loop that runs as long as there are still unprocessed room elements in the document.
	while (roomElementPtr != nullptr) {

		// Have the data element pointer find the name element.
		// Once found, store the contents of the name element in a string variable.
		dataElementPtr = roomElementPtr->FirstChildElement("name");
		dataChars = dataElementPtr->GetText();
		std::string nm(dataChars);

		// Have the data element pointer find the short description element.
		// Once found, store the contents of the short description element in a string variable.
		dataElementPtr = roomElementPtr->FirstChildElement("shortDescription");
		dataChars = dataElementPtr->GetText();
		std::string shortDesc(dataChars);

		// Have the data element pointer find the long description element.
		// Once found, store the contents of the long description element in a string variable.
		dataElementPtr = roomElementPtr->FirstChildElement("longDescription");
		dataChars = dataElementPtr->GetText();
		std::string longDesc(dataChars);

		// Create a new room object from the acquired information,
		// and add it to the room list.
		Room newRoom(nm, shortDesc, longDesc);

		// Have the data element pointer find inventory element
		dataElementPtr = roomElementPtr->FirstChildElement("inventory");

		// If the room element has an inventory element, search for item elements.
		if (dataElementPtr != nullptr) {
			tinyxml2::XMLElement* itemElementPtr;
			itemElementPtr = dataElementPtr->FirstChildElement("item");

			// If there is an item element hasn't been added to the room's
			// inventory yet, search through the item list for the item that has
			// the same name as the item element. Once that item is found, add
			// its address to the room's inventory.
			while (itemElementPtr != nullptr){
				dataChars = itemElementPtr->GetText();
				std::string itemName(dataChars);

				for (int i = 0; i < imList.size(); i++) {
					if (imList[i].getName() == itemName) {
						newRoom.addItem(&imList[i]);
					}// end if
				}// end for

				itemElementPtr = itemElementPtr->NextSiblingElement("item");
			}// end while
		}// end if

		// Once the room's inventory has been filled (if it had item elements),
		// add the room to the room list.
		rmList.push_back(newRoom);

		// Set the room element pointer to the next room element.
		roomElementPtr = roomElementPtr->NextSiblingElement("room");
	}// end while room ptr
}// end create room

void createDoorObjects(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Door> &drList, std::vector<Room>&rmList) {
	tinyxml2::XMLElement* doorElementPtr;
	tinyxml2::XMLElement* dataElementPtr;
	const char* dataChars;
	bool dataBool;

	doorElementPtr = wNodePtr->FirstChildElement("door");

	while (doorElementPtr != nullptr) {

		// Have the data element pointer find the name element.
		// Once found, store the contents of the name element in a string variable.
		dataElementPtr = doorElementPtr->FirstChildElement("name");
		dataChars = dataElementPtr->GetText();
		std::string nm(dataChars);

		// Have the data element pointer find the short description element.
		// Once found, store the contents of the short description element in a string variable.
		dataElementPtr = doorElementPtr->FirstChildElement("description");
		dataChars = dataElementPtr->GetText();
		std::string desc(dataChars);

		// Have the data element pointer find the accessbility element.
		// Once found, store the contents of the accessbility element in a bool variable.
		dataElementPtr = doorElementPtr->FirstChildElement("accessible");
		dataBool = dataElementPtr->GetText();

		// Create the Door object
		Door newDoor(nm, desc, dataBool);

		// Have the data element pointer find the room one element.
		// Once found, store the contents of the room one element in a string variable.
		dataElementPtr = doorElementPtr->FirstChildElement("roomOne");
		dataChars = dataElementPtr->GetText();
		std::string roomOneName(dataChars);

		// Have the data element pointer find the room two element.
		// Once found, store the contents of the room two element in a string variable.
		dataElementPtr = doorElementPtr->FirstChildElement("roomTwo");
		dataChars = dataElementPtr->GetText();
		std::string roomTwoName(dataChars);

		// Loop that searches through the list of created rooms
		// and find the rooms are to be connected to the door.
		//
		// If the current room's name matches with one of the door's room names,
		// store the address of that room to the corresponding room pointer in the door.
		for (int i = 0; i < rmList.size(); i++) {
			if (rmList[i].getName() == roomOneName) {
				newDoor.setRoomOne(&rmList[i]);
			}//end if
			else if (rmList[i].getName() == roomTwoName) {
				newDoor.setRoomTwo(&rmList[i]);
			}//end else if
		}//end for

		// Add the door to the door list.
		drList.push_back(newDoor);

		// Set the room element pointer to the next door element.
		doorElementPtr = doorElementPtr->NextSiblingElement("door");
	} //end while
}//end create door object function

void createContainerObjects(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Container> &crList, std::vector<Room> &rmList, std::vector<Item> &imList) {

	tinyxml2::XMLElement* containerElementPtr;
	tinyxml2::XMLElement* dataElementPtr;
	const char* dataChars;
	bool dataBool;

	containerElementPtr = wNodePtr->FirstChildElement("container");

	while (containerElementPtr != nullptr) {

		// Have the data element pointer find the name element.
		// Once found, store the contents of the name element in a string variable.
		dataElementPtr = containerElementPtr->FirstChildElement("name");
		dataChars = dataElementPtr->GetText();
		std::string nm(dataChars);

		// Have the data element pointer find the short description element.
		// Once found, store the contents of the short description element in a string variable.
		dataElementPtr = containerElementPtr->FirstChildElement("description");
		dataChars = dataElementPtr->GetText();
		std::string desc(dataChars);

		// Have the data element pointer find the accessbility element.
		// Once found, store the contents of the accessbility element in a bool variable.
		dataElementPtr = containerElementPtr->FirstChildElement("accessible");
		dataBool = dataElementPtr->GetText();

		// Create the container object
		Container newContainer(nm, desc, dataBool);

		// Have the data element pointer find the room element.
		// Once found, store the contents of the room element in a string variable.
		dataElementPtr = containerElementPtr->FirstChildElement("room");
		dataChars = dataElementPtr->GetText();
		std::string roomName(dataChars);

		// Loop that searches through the list of created rooms
		// and find the room that the container will be placed in.
		//
		// If the current room's name matches the container's room element name,
		// store the address of that room in the container's room pointer.
		for (int i = 0; i < rmList.size(); i++) {
			if (rmList[i].getName() == roomName) {
				newContainer.setCurrentRoom(&rmList[i]);
				break;
			}// end if
		}// end for

		// Have the data element pointer find inventory element
		dataElementPtr = containerElementPtr->FirstChildElement("inventory");

		// If the room element has an inventory element, search for item elements.
		if (dataElementPtr != nullptr) {
			tinyxml2::XMLElement* itemElementPtr;
			itemElementPtr = dataElementPtr->FirstChildElement("item");

			// If there is an item element hasn't been added to the container's
			// inventory yet, search through the item list for the item that has
			// the same name as the item element. Once that item is found, add
			// its address to the container's inventory.
			while (itemElementPtr != nullptr){
				dataChars = itemElementPtr->GetText();
				std::string itemName(dataChars);

				for (int i = 0; i < imList.size(); i++) {
					if (imList[i].getName() == itemName) {
						newContainer.addItem(&imList[i]);
					}// end if
				}// end for

				itemElementPtr = itemElementPtr->NextSiblingElement("item");
			}// end while
		}// end if

		// Add the door to the door list.
		crList.push_back(newContainer);

		// Set the room element pointer to the next door element.
		containerElementPtr = containerElementPtr->NextSiblingElement("container");
	}// end while container ptr
}//end create containers function

void createIndividualObjects(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Individual> &ilList, std::vector<Room> &rmList, std::vector<Item> &imList) {

	tinyxml2::XMLElement* individualElementPtr;
	tinyxml2::XMLElement* dataElementPtr;
	const char* dataChars;
	int dataInt;

	individualElementPtr = wNodePtr->FirstChildElement("individual");

	while (individualElementPtr != nullptr) {

		// Have the data element pointer find the name element.
		// Once found, store the contents of the name element in a string variable.
		dataElementPtr = individualElementPtr->FirstChildElement("name");
		dataChars = dataElementPtr->GetText();
		std::string nm(dataChars);

		// Have the data element pointer find the short description element.
		// Once found, store the contents of the short description element in a string variable.
		dataElementPtr = individualElementPtr->FirstChildElement("description");
		dataChars = dataElementPtr->GetText();
		std::string desc(dataChars);

		// Have the data element pointer find the health element.
		dataElementPtr = individualElementPtr->FirstChildElement("health");

		// Once found, store the contents of the health element in an int variable.
		// The characters in the health element are stored in a string stream.
		// That string stream is then stoed in the int variable.
		if (dataElementPtr != nullptr){
			dataChars = dataElementPtr->GetText();
			std::stringstream strValue;

			strValue << dataChars;
			strValue >> dataInt;
		}
		// If not found in the document, set a default value of 100 to the health.
		else {
			dataInt = 100;
		}

		// Create the container object
	 	Individual newIndividual(nm, desc, dataInt);

		// Have the data element pointer find the room element.
		// Once found, store the contents of the room element in a string variable.
		dataElementPtr = individualElementPtr->FirstChildElement("room");
		dataChars = dataElementPtr->GetText();
		std::string roomName(dataChars);

		// Loop that searches through the list of created rooms
		// and find the room that the individual will be placed in.
		//
		// If the current room's name matches the individual's room element name,
		// store the address of that room in the individual's room pointer.
		for (int i = 0; i < rmList.size(); i++) {
			if (rmList[i].getName() == roomName) {
				newIndividual.setCurrentRoom(&rmList[i]);
				break;
			}// end if
		}// end for

		// Have the data element pointer find inventory element
		dataElementPtr = individualElementPtr->FirstChildElement("inventory");

		// If the room element has an inventory element, search for item elements.
		if (dataElementPtr != nullptr) {
			tinyxml2::XMLElement* itemElementPtr;
			itemElementPtr = dataElementPtr->FirstChildElement("item");

			// If there is an item element hasn't been added to the container's
			// inventory yet, search through the item list for the item that has
			// the same name as the item element. Once that item is found, add
			// its address to the container's inventory.
			while (itemElementPtr != nullptr){
				dataChars = itemElementPtr->GetText();
				std::string itemName(dataChars);

				for (int i = 0; i < imList.size(); i++) {
					if (imList[i].getName() == itemName) {
						newIndividual.addItem(&imList[i]);
					}// end if
				}// end for

				itemElementPtr = itemElementPtr->NextSiblingElement("item");
			}// end while
		}// end if inventory ptr

		// Add the door to the door list.
		ilList.push_back(newIndividual);

		// Set the room element pointer to the next door element.
		individualElementPtr = individualElementPtr->NextSiblingElement("individual");
	}// end individual element ptr
}// end create individual
