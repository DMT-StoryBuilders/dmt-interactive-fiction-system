#include "exportWorld.h"

void createDocument(std::vector<Room>& rmList, std::vector<Door>& drList, std::vector<Container> &crList, std::vector<Individual> &ilList, std::vector<Item> &imList) {
	std::string savePath;

	std::cout << "____________________________________________________" << std::endl;
	std::cout << "World Export" << std::endl;
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
	tinyxml2::XMLNode* worldNodePtr = worldDocument.NewElement("world");
	worldDocument.InsertFirstChild(worldNodePtr);

	createItemElements(worldDocument, worldNodePtr, imList);
	createRoomElements(worldDocument, worldNodePtr, rmList);
	createDoorElements(worldDocument, worldNodePtr, drList);
	createContainerElements(worldDocument, worldNodePtr, crList);
	createIndividualElements(worldDocument, worldNodePtr, ilList);

	worldDocument.SaveFile(savePathChars);
}// end create documents

void createItemElements(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Item> &imList){
	tinyxml2::XMLElement* itemElementPtr;
	tinyxml2::XMLElement* dataElementPtr;
	std::string dataString;
	char dataChars[600];

	for (int i = 0; i < imList.size(); i++){

		// Create a new item element
		itemElementPtr = worldDoc.NewElement("item");

		// Create a name element for the item element
		dataElementPtr = worldDoc.NewElement("name");

		// Store the characters of the current item's name into a char array
		// Store the contents of the char array into the name element.
		dataString = imList[i].getName();
		strcpy(dataChars, dataString.c_str());
		dataElementPtr->SetText(dataChars);

		// Insert the name element into the item element
		itemElementPtr->InsertEndChild(dataElementPtr);

		// Create a short description element for the item element
		dataElementPtr = worldDoc.NewElement("shortDescripton");

		// Store the characters of the current item's short desc into a char array
		// Store the contents of the char array into the name element.
		dataString = imList[i].getShortDescription();
		strcpy(dataChars, dataString.c_str());
		dataElementPtr->SetText(dataChars);

		// Insert the short desc element into the item element
		itemElementPtr->InsertEndChild(dataElementPtr);

		// Create a long description element for the item element
		dataElementPtr = worldDoc.NewElement("longDescription");

		// Store the characters of the current item's long desc into a char array
		// Store the contents of the char array into the name element.
		dataString = imList[i].getLongDescription();
		strcpy(dataChars, dataString.c_str());
		dataElementPtr->SetText(dataChars);

		// Insert the long desc element into the item element
		itemElementPtr->InsertEndChild(dataElementPtr);

		// Once the data elements for the item has been inserted,
		// insert the item element into the world document.
		wNodePtr->InsertEndChild(itemElementPtr);
	}// end for
}// end create item elements

void createContainerElements(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Container> &crList){
	tinyxml2::XMLElement* containerElementPtr;
	tinyxml2::XMLElement* dataElementPtr;
	std::string dataString;
	char dataChars[600];

	for (int i = 0; i < crList.size(); i++) {

		// Create a new container element
		containerElementPtr = worldDoc.NewElement("container");

		// Create the name element for the container element.
		dataElementPtr = worldDoc.NewElement("name");

		// Store the characters of the container's name in a char array.
		// Store the contents of the char array in the name element.
		dataString = crList[i].getName();
		strcpy(dataChars, dataString.c_str());
		dataElementPtr->SetText(dataChars);

		// Insert the name element into the room element
		containerElementPtr->InsertEndChild(dataElementPtr);

		// Create the description element for the container element.
		dataElementPtr = worldDoc.NewElement("description");

		// Store the characters of the container's description in a char array.
		// Store the contents of the char array in the description element.
		dataString = crList[i].getDescription();
		strcpy(dataChars, dataString.c_str());
		dataElementPtr->SetText(dataChars);

		// Insert the description element into the container element
		containerElementPtr->InsertEndChild(dataElementPtr);

		// Create the accessible element for the container element.
		dataElementPtr = worldDoc.NewElement("accessible");

		// Store the container's accessibility into the corresponding element.
		dataElementPtr->SetText(crList[i].getIsAccessible());

		// Insert the accessibility element into the container element.
		containerElementPtr->InsertEndChild(dataElementPtr);

		// Create the room element for the container
		dataElementPtr = worldDoc.NewElement("room");

		// Store the name of the room in which the container is located in
		// into the element.
		dataString = crList[i].getCurrentRoom()->getName();
		strcpy(dataChars, dataString.c_str());
		dataElementPtr->SetText(dataChars);

		// Insert the room element into the container element
		containerElementPtr->InsertEndChild(dataElementPtr);

		// If the container's inventory is not empty, create an inventory element
		// and fill it with item elements.
		if (crList[i].getInventorySize() != 0) {

			// Create an inventory element for the room element
			dataElementPtr = worldDoc.NewElement("inventory");
			tinyxml2::XMLElement* itemElementPtr;

			// Store every item's name in the room's inventory into the inventory
			// element as item elements.
			for (int j = 0; j < crList[i].getInventorySize(); j++) {

				// Create an item element for the room's inventory element
				itemElementPtr = worldDoc.NewElement("item");

				dataString = crList[i].getItemName(j);
				strcpy(dataChars, dataString.c_str());
				itemElementPtr->SetText(dataChars);

				// insert the item element into the inventory element.
				dataElementPtr->InsertEndChild(itemElementPtr);
			}// end for j

			// Insert the inventory element into the room element.
			containerElementPtr->InsertEndChild(dataElementPtr);
		}// end if rmList

		// Once the data elements for the container has been created,
		// insert the container element into the world document.
		wNodePtr->InsertEndChild(containerElementPtr);
	}// end for i
}// end create container elements

void createRoomElements(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Room>& rmList) {
	tinyxml2::XMLElement* roomElementPtr;
	tinyxml2::XMLElement* dataElementPtr;
	std::string dataString;
	char dataChars[600];

	for (int i = 0; i < rmList.size(); i++) {

		// Create a new room element
		roomElementPtr = worldDoc.NewElement("room");

		// Create a name element for room element
		dataElementPtr = worldDoc.NewElement("name");

		// Store the characters of the room's name in a char array.
		// Store the contents of the char array in the name element.
		dataString = rmList[i].getName();
		strcpy(dataChars, dataString.c_str());
		dataElementPtr->SetText(dataChars);

		// Insert the name element into the room element
		roomElementPtr->InsertEndChild(dataElementPtr);

		// Create a short description element for the room element
		dataElementPtr = worldDoc.NewElement("shortDescription");

		// Store the characters of the room's short description in a char array.
		// Store the contents of the char array in the shortDescription element.
		dataString = rmList[i].getShortDescription();
		strcpy(dataChars, dataString.c_str());
		dataElementPtr->SetText(dataChars);

		// Insert the short description element into the room element
		roomElementPtr->InsertEndChild(dataElementPtr);

		// Create a long description element for the room element
		dataElementPtr = worldDoc.NewElement("longDescription");

		// Store the characters of the room's short description in a char array.
		// Store the contents of the char array in the shortDescription element.
		dataString = rmList[i].getLongDescription();
		strcpy(dataChars, dataString.c_str());
		dataElementPtr->SetText(dataChars);

		// Insert the long description element into the room element
		roomElementPtr->InsertEndChild(dataElementPtr);

		// If the room's inventory is not empty, create an inventory element
		// and fill it with item elements.
		if (rmList[i].getInventorySize() != 0) {

			// Create an inventory element for the room element
			dataElementPtr = worldDoc.NewElement("inventory");
			tinyxml2::XMLElement* itemElementPtr;

			// Store every item's name in the room's inventory into the inventory
			// element as item elements.
			for (int j = 0; j < rmList[i].getInventorySize(); j++) {

				// Create an item element for the room's inventory element
				itemElementPtr = worldDoc.NewElement("item");

				dataString = rmList[i].getItemName(j);
				strcpy(dataChars, dataString.c_str());
				itemElementPtr->SetText(dataChars);

				// insert the item element into the inventory element.
				dataElementPtr->InsertEndChild(itemElementPtr);
			}

			// Insert the inventory element into the room element.
			roomElementPtr->InsertEndChild(dataElementPtr);
		}// end if rmList

		// Once the data elements for the room has been created,
		// insert the room element into the world document.
		wNodePtr->InsertEndChild(roomElementPtr);
	}// end for
}// end create room elements

void createDoorElements(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Door> &drList) {
	tinyxml2::XMLElement* doorElementPtr;
	tinyxml2::XMLElement* dataElementPtr;
	std::string dataString;
	bool dataBool;
	char dataChars[600];

	for (int i = 0; i < drList.size(); i++) {

		// Create a new door element
		doorElementPtr = worldDoc.NewElement("door");

		// Create a name element for the door element
		dataElementPtr = worldDoc.NewElement("name");

		// Store the characters of the door's name in a char array.
		// Store the contents of the char array in the name element.
		dataString = drList[i].getName();
		strcpy(dataChars, dataString.c_str());
		dataElementPtr->SetText(dataChars);

		// Insert the name element into the door element
		doorElementPtr->InsertEndChild(dataElementPtr);

		// Create a description element for the door element
		dataElementPtr = worldDoc.NewElement("description");

		// Store the characters of the door's description in a char array.
		// Store the contents of the char array in the descripton element.
		dataString = drList[i].getDescription();
		strcpy(dataChars, dataString.c_str());
		dataElementPtr->SetText(dataChars);

		// Insert the description element into the door element
		doorElementPtr->InsertEndChild(dataElementPtr);

		// Create an accessibility element for the door
		dataElementPtr = worldDoc.NewElement("accessible");

		// Store the door's accessibility into the corresponding element.
		dataElementPtr->SetText(drList[i].getIsAccessible());

		// Insert the accessibility element into the door element.
		doorElementPtr->InsertEndChild(dataElementPtr);

		// Create the room one element for the door
		dataElementPtr = worldDoc.NewElement("roomOne");

		// Store the characters of the room one's name in a char array.
		// Store the contents of the char array in the descripton element.
		dataString = drList[i].getRoomOne()->getName();
		strcpy(dataChars, dataString.c_str());
		dataElementPtr->SetText(dataChars);

		// Insert the room one element into the door element.
		doorElementPtr->InsertEndChild(dataElementPtr);

		// Create the room two element for the door
		dataElementPtr = worldDoc.NewElement("roomTwo");

		// Store the characters of the room one's name in a char array.
		// Store the contents of the char array in the descripton element.
		dataString = drList[i].getRoomTwo()->getName();
		strcpy(dataChars, dataString.c_str());
		dataElementPtr->SetText(dataChars);

		// Insert the room element into the door element.
		doorElementPtr->InsertEndChild(dataElementPtr);

		// After the data elements of the current door has created,
		// insert the door element into the world document.
		wNodePtr->InsertEndChild(doorElementPtr);
	}// end for
}// end create door elements

void createIndividualElements(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Individual> &ilList) {
	tinyxml2::XMLElement* individualElementPtr;
	tinyxml2::XMLElement* dataElementPtr;
	std::string dataString;
	bool dataBool;
	char dataChars[600];

	for (int i = 0; i < ilList.size(); i++) {

		// Create a new individual element
		individualElementPtr = worldDoc.NewElement("individual");

		// Create the name element for the individual
		dataElementPtr = worldDoc.NewElement("name");

		// Store the characters of the individual's name in a char array.
		// Store the contents of the char array in the name element.
		dataString = ilList[i].getName();
		strcpy(dataChars, dataString.c_str());
		dataElementPtr->SetText(dataChars);

		// Insert the name element into the individual element
		individualElementPtr->InsertEndChild(dataElementPtr);

		// Create description element for the individual
		dataElementPtr = worldDoc.NewElement("description");

		// Store the characters of the door's name in a char array.
		// Store the contents of the char array in the name element.
		dataString = ilList[i].getDescription();
		strcpy(dataChars, dataString.c_str());
		dataElementPtr->SetText(dataChars);

		// Insert the description element into the door element
		individualElementPtr->InsertEndChild(dataElementPtr);

		// Create a health element, store the current individual's health value
		// in the element, and add it to the individual element.
		dataElementPtr = worldDoc.NewElement("health");
		dataElementPtr->SetText(ilList[i].getHealth());
		individualElementPtr->InsertEndChild(dataElementPtr);

		// Create the room element for the individual.
		dataElementPtr = worldDoc.NewElement("room");

		// Store the name of the room that the individual is located in
		// into the room element.
		dataString = ilList[i].getCurrentRoom()->getName();
		strcpy(dataChars, dataString.c_str());
		dataElementPtr->SetText(dataChars);

		// Insert the room element into the individual element
		individualElementPtr->InsertEndChild(dataElementPtr);

		// If the room's inventory is not empty, create an inventory element
		// and fill it with item elements.
		if (ilList[i].getInventorySize() != 0) {

			// Create an inventory element for the room element
			dataElementPtr = worldDoc.NewElement("inventory");
			tinyxml2::XMLElement* itemElementPtr;

			// Store every item's name in the room's inventory into the inventory
			// element as item elements.
			for (int j = 0; j < ilList[i].getInventorySize(); j++) {

				// Create an item element for the room's inventory element
				itemElementPtr = worldDoc.NewElement("item");

				dataString = ilList[i].getItemName(j);
				strcpy(dataChars, dataString.c_str());
				itemElementPtr->SetText(dataChars);

				// insert the item element into the inventory element.
				dataElementPtr->InsertEndChild(itemElementPtr);
			}// end for j

			// insert the inventory element into the individual element.
			individualElementPtr->InsertEndChild(dataElementPtr);
		}// end if inventorySize

		// After the data elements of the current individual has created,
		// insert the door element into the world document.
		wNodePtr->InsertEndChild(individualElementPtr);

	}// end for i
}// end create individual
