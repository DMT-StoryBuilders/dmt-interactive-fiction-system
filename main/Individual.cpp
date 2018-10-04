#include "pch.h"
#include "Individual.h"


Individual::Individual() {
	name = "";
	description = "";
	health = 0;
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

void Individual::setCurrentRoom(Room room) {
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

Room * Individual::getCurrentRoom() {
	return currentRoomPtr;
}


Individual::~Individual() {
}
