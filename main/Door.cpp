#include "Door.h"

Door::Door() {
	name = "";
	description = "";
	isAccessible = true;
	roomOnePtr = NULL;
	roomTwoPtr = NULL;
}

Door::Door(std::string nm, std::string desc, bool accessible) {
	name = nm;
	description = desc;
	isAccessible = accessible;
	roomOnePtr = NULL;
	roomTwoPtr = NULL;
}

Door::Door(std::string nm, std::string desc, bool accessible, Room &roomOne, Room &roomTwo) {
	name = nm;
	description = desc;
	isAccessible = accessible;
	roomOnePtr = &roomOne;
	roomTwoPtr = &roomTwo;
}

Door::Door(std::string nm, std::string desc, bool accessible, Room *roomOnePointer, Room *roomTwoPointer) {
	name = nm;
	description = desc;
	isAccessible = accessible;
	roomOnePtr = roomOnePointer;
	roomTwoPtr = roomTwoPointer;
}

void Door::setName(std::string nm) {
	name = nm;
}

void Door::setDescription(std::string desc) {
	description = desc;
}

void Door::setIsAccessible(bool accessible) {
	isAccessible = accessible;
}

void Door::setRoomOne(Room &roomOne) {
	roomOnePtr = &roomOne;
}

void Door::setRoomOne(Room *roomOnePointer) {
	roomOnePtr = roomOnePointer;
}

void Door::setRoomTwo(Room &roomTwo) {
	roomTwoPtr = &roomTwo;
}

void Door::setRoomTwo(Room *roomTwoPointer) {
	roomTwoPtr = roomTwoPointer;
}

std::string Door::getName() {
	return name;
}

std::string Door::getDescription() {
	return description;
}

bool Door::getIsAccessible() {
	return isAccessible;
}

Room * Door::getRoomOne() {
	return roomOnePtr;
}

Room * Door::getRoomTwo() {
	return roomTwoPtr;
}

Door::~Door()
{
}
