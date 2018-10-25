#include "pch.h"
#include "Container.h"


Container::Container() {
	name = "";
	description = "";
}

Container::Container(std::string nm, std::string desc) {
	name = nm;
	description = desc;
}

void Container::setName(std::string nm) {
	name = nm;
}

void Container::setDescription(std::string desc) {
	description = desc;
}

void Container::addItem(Item* item) {
	containerContent.push_back(item);
}

std::string Container::getName() {
	return name;
}

std::string Container::getDescription() {
	return description;
}

Container::~Container() {
}
