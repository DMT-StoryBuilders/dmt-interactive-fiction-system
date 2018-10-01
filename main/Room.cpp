#include "pch.h"
#include "Room.h"


Room::Room() {
	name = "";
	longDescription = "";
	shortDesecription = "";
}

Room::Room(std::string nm, std::string longDesc, std::string shortDesc) {
	name = name;
	longDescription = longDesc;
	shortDesecription = shortDesc;
}

void Room::setName(std::string nm) {
	name = nm;
}

void Room::setLongDescription(std::string longDesc) {
	longDescription = longDesc;
}

void Room::setShortDescription(std::string shortDesc) {
	shortDesecription = shortDesc;
}

/*
void Room::addToDoorList(Door door) {
	doorList.push_back(door);
}
*/

/*
void Room::addToDoorList(Door &doorAddress) {
	doorList.push_back(&doorAddress);
}
*/

std::string Room::getName() {
	return name;
}

std::string Room::getLongDescription() {
	return longDescription;
}

std::string Room::getShortDescription() {
	return shortDesecription;
}

Room::~Room()
{
}
