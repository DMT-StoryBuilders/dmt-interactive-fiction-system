#include "pch.h"
#include "Door.h"

Door::Door() {
	name = "";
	description = "";
	isAccessible = true;
}

Door::Door(std::string nm, std::string desc, bool accessible) {
	name = nm;
	description = desc;
	isAccessible = accessible;
}

Door::Door(std::string nm, std::string desc, bool accessible, Room roomOne, Room roomTwo) {
	name = nm;
	description = desc;
	isAccessible = accessible;
	roomOnePtr = &roomOne;
	roomTwoPtr = &roomTwo;
}

Door::Door(std::string nm, std::string desc, bool accessible, Room* roomOnePointer, Room* roomTwoPointer) {
	name = nm;
	description = desc;
	isAccessible = accessible;
	roomOnePtr = roomOnePointer;
	roomTwoPtr = roomTwoPointer;
}

Door::Door(std::string nm, std::string desc, bool accessible, Room &roomOneAddress, Room &roomTwoAddress) {
	name = nm;
	description = desc;
	isAccessible = accessible;
	roomOnePtr = &roomOneAddress;
	roomTwoPtr = &roomTwoAddress;
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

void Door::setRoomOnePointer(Room roomOne) {
	roomOnePtr = &roomOne;
}

void Door::setRoomOnePointer(Room* roomOnePointer) {
	roomOnePtr = roomOnePointer;
}

void Door::setRoomOnePointer(Room & roomOneAddress) {
	roomOnePtr = &roomOneAddress;
}

void Door::setRoomTwoPointer(Room roomTwo) {
	roomTwoPtr = &roomTwo;
}

void Door::setRoomTwoPointer(Room * roomTwoPointer) {
	roomTwoPtr = roomTwoPointer;
}

void Door::setRoomTwoPointer(Room & roomTwoAddress) {
	roomTwoPtr = &roomTwoAddress;
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

Door::~Door()
{
}
