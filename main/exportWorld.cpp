#include "exportWorld.h"

void createDocument(std::vector<Room>& rmList, std::vector<Door>& drList) {
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

	createRoomElements(worldDocument, worldNodePtr, rmList);
	createDoorElements(worldDocument, worldNodePtr, drList);
	//createContainerElements(worldDocument, worldNodePtr, crList);

	worldDocument.SaveFile(savePathChars);
}

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
