#include "Container.h"

Container::Container() {
	name = "";
	description = "";
	isAccesible = true;
}

Container::Container(std::string nm) {
	name = nm;
	description = "";
	isAccesible = true;
}

Container::Container(std::string nm, std::string desc) {
	name = nm;
	description = desc;
	isAccesible = true;
}

Container::Container(std::string nm, std::string desc, bool accessible) {
	name = nm;
	description = desc;
	isAccesible = accessible;
}

Container::Container(std::string nm, std::string desc, bool accessible, Room* roomPtr){
	name = nm;
	description = desc;
	isAccesible = accessible;
	currentRoomPtr = roomPtr;
}

Container::Container(std::string nm, std::string desc, bool accessible, Room &room){
	name = nm;
	description = desc;
	isAccesible = accessible;
	currentRoomPtr = &room;
}

void Container::setName(std::string nm) {
	name = nm;
}

void Container::setDescription(std::string desc) {
	description = desc;
}

void Container::setIsAccessible(bool accessible) {
	isAccesible = accessible;
}

void Container::setCurrentRoom(Room* roomPtr) {
	currentRoomPtr = roomPtr;
}

void Container::setCurrentRoom(Room &room) {
	currentRoomPtr = &room;
}

std::string Container::getName() {
	return name;
}

std::string Container::getDescription() {
	return description;
}

bool Container::getIsAccessible() {
	return isAccesible;
}

Room* Container::getCurrentRoom() {
	return currentRoomPtr;
}

std::string Container::getItemName(int index) {
	return inventory[index]->getName();
}

int Container::getInventorySize() {
	return inventory.size();
}

Item* Container::getItem(int i) {
	return(inventory[i]);
}

void Container::addItem(Item* item) {
	inventory.push_back(item);
}

void Container::removeItem(int i) {
	inventory.erase(inventory.begin() + i);
}

void Container::clearItems() {
	for (int i = 0; i < inventory.size(); i++) {
		inventory.erase(inventory.begin() + i);
	}
}

void Container::printItems() {
	std::cout << "\n";

	if (inventory.size() == 0) {
		std::cout << "There is nothing in the " << name <<"\n";
	}

	else {
		std::cout << "Inside the " << name << " is:\n";

		for (int i = 0; i < inventory.size(); i++) {
			std::cout << inventory[i]->getName() << "\n";
		}
	}
}

Container::~Container() {
}
