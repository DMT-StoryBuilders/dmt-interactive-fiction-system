#include "importWorld.h"

void loadDocument(std::vector<Room>& rmList, std::vector<Door>& drList) {
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
	createRoomObjects(worldDocument, worldNodePtr, rmList);
	createDoorObjects(worldDocument, worldNodePtr, drList, rmList);
}

void createRoomObjects(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Room> &rmList) {
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
		rmList.push_back(newRoom);

		// Set the room element pointer to the next room element.
		roomElementPtr = roomElementPtr->NextSiblingElement("room");
	}
}

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
}//end create door object functions
