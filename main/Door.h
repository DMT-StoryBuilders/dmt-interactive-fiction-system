#pragma once
#ifndef DOOR_H
#define DOOR_H	
#include "Room.h"

class Door {
public:
	Door();
	Door(std::string nm, std::string desc, bool accessible);
	Door(std::string nm, std::string desc, bool accessible, Room roomOne, Room roomTwo);
	Door(std::string nm, std::string desc, bool accessible, Room* roomOnePointer, Room* roomTwoPointer);
	Door(std::string nm, std::string desc, bool accessible, Room &roomOneAddress, Room &roomTwoAddress);

	void setName(std::string nm);
	void setDescription(std::string desc);
	void setIsAccessible(bool accessible);

	void setRoomOnePointer(Room roomOne);
	void setRoomOnePointer(Room* roomOnePointer);
	void setRoomOnePointer(Room &roomOneAddress);
	void setRoomTwoPointer(Room roomTwo);
	void setRoomTwoPointer(Room* roomTwoPointer);
	void setRoomTwoPointer(Room &roomTwoAddress);

	std::string getName();
	std::string getDescription();
	bool getIsAccessible();

	~Door();

private:
	std::string name;
	std::string description;
	bool isAccessible;
	Room* roomOnePtr;
	Room* roomTwoPtr;
};
#endif