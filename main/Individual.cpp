#include "Individual.h"

Individual::Individual() {
    name = "";
	description = "";
	health = 100;
	currentRoomPtr = NULL;
}

Individual::Individual(std::string nm) {
	name = nm;
	description = "";
	health = 100;
	currentRoomPtr = NULL;
}

Individual::Individual(std::string nm, Room *roomPtr) {
	name = nm;
	description = "";
	health = 100;
	currentRoomPtr = roomPtr;
}

Individual::Individual(std::string nm, std::string desc, Room *roomPtr) {
	name = nm;
	description = desc;
	currentRoomPtr = roomPtr;
}

Individual::Individual(std::string nm, std::string desc, int hp, Room *roomPtr) {
	name = nm;
	description = desc;
	health = hp;
	currentRoomPtr = roomPtr;
}

void Individual::setName(std::string nm) {
	name = nm;
}

void Individual::setDescription(std::string desc) {
	description = desc;
}

void Individual::setHealth(int hp) {
	health = hp;
}

void Individual::setCurrentRoom(Room &room) {
	currentRoomPtr = &room;
}

void Individual::setCurrentRoom(Room *roomPtr) {
	currentRoomPtr = roomPtr;
}

std::string Individual::getName() {
	return name;
}

std::string Individual::getDescription() {
	return description;
}

int Individual::getHealth() {
	return health;
}

Room* Individual::getCurrentRoom() {
	return currentRoomPtr;
}

int Individual::getInventorySize()
{
	return(inventory.size());
}

Item* Individual::getItem(int i) {
	return(inventory[i]);
}

void Individual::removeItem(int i) {
	inventory.erase(inventory.begin() + i);
}

void Individual::clearItems() {
	for (i = 0; i < inventory.size(); i++) {
		inventory.erase(inventory.begin() + i);
	}
}

void Individual::addItem(Item* item) {
	inventory.push_back(item);
}

void Individual::printItems() {
	std::cout << "\n";

	if (inventory.size() == 0) {
		std::cout << "There is nothing on the " << name << "\n";
	}

	else {
		std::cout << "On the " << name << " is:\n";
		for (i = 0; i < inventory.size(); i++) {
			std::cout << inventory[i]->getName() << "\n";
		}
	}
}

Individual::~Individual() {
}
