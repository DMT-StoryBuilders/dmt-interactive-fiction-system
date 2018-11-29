#include "Room.h"

Room::Room() {
	name = "";
	longDescription = "";
	shortDesecription = "";
}

Room::Room(std::string nm) {
	name = nm;
	longDescription = "";
	shortDesecription = "";
}

Room::Room(std::string nm, std::string shortDesc, std::string longDesc) {
	name = nm;
	shortDesecription = shortDesc;
	longDescription = longDesc;
}

void Room::setName(std::string nm) {
	name = nm;
}

void Room::setShortDescription(std::string shortDesc) {
	shortDesecription = shortDesc;
}

void Room::setLongDescription(std::string longDesc) {
	longDescription = longDesc;
}

std::string Room::getName() {
	return name;
}

std::string Room::getShortDescription() {
	return shortDesecription;
}

std::string Room::getLongDescription() {
	return longDescription;
}

int Room::getInventorySize() {
	return inventory.size();
}

std::string Room::getItemName(int index) {
	return inventory[index]->getName();
}

Item* Room::getItem(int i) {
	return(inventory[i]);
}

void Room::addItem(Item* item) {
	inventory.push_back(item);
}

void Room::removeItem(int i) {
	inventory.erase(inventory.begin() + i);
}

void Room::clearItems() {
	for (int i = 0; i < inventory.size(); i++) {
		inventory.erase(inventory.begin() + i);
	}
}

void Room::printItems() {
	std::cout << "\n";
	if (inventory.size() == 0)	{
		std::cout << "There is nothing in the " << name << "\n";
	}

	else {
		std::cout << "Inside the " << name << " is:\n";

		for (int i = 0; i < inventory.size(); i++) {
			std::cout << inventory[i]->getName() << "\n";
		}
	}
}

Room::~Room() {
}
