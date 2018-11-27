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

void Container::setName(std::string nm) {
	name = nm;
}

void Container::setDescription(std::string desc) {
	description = desc;
}

std::string Container::getName() {
	return name;
}

std::string Container::getDescription() {
	return description;
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
	for (i = 0; i < inventory.size(); i++) {
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

		for (i = 0; i < inventory.size(); i++) {
			std::cout << inventory[i]->getName() << "\n";
		}
	}
}

Container::~Container() {
}
