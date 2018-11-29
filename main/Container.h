#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"
#include "Room.h"

/* Class that represents a container.
 * Ex) Chest, bookcase, closet, shoebox, etc.
 *
 * Data members
 * __________________________________________________
 * string name: stores the name of the container
 * string description: stores the description of the container
 * vector containerContent: Vector that stores Item pointers
 */
class Container {
public:
	Container();
	Container(std::string nm);
	Container(std::string nm, std::string desc);
	Container(std::string nm, std::string desc, bool accessible);
	Container(std::string nm, std::string desc, bool accessible, Room* roomPtr);
	Container(std::string nm, std::string desc, bool accessible, Room &room);

	void setName(std::string nm);
	void setDescription(std::string desc);
	void setIsAccessible(bool accessible);
	void setCurrentRoom(Room *roomPtr);
	void setCurrentRoom(Room &room);

	std::string getName();
	std::string getDescription();
	bool getIsAccessible();
	Room* getCurrentRoom();

	int getInventorySize();
	Item* getItem(int i);
	std::string getItemName(int index);

	void addItem(Item* item);
	void removeItem(int i);
	void printItems();
	void clearItems();

	~Container();

private:
	std::string name;
	std::string description;
	bool isAccesible;
	Room* currentRoomPtr;
	std::vector<Item*> inventory;
};

#endif
