#include "pch.h"
#include "Room.h"


Room::Room() {
	name = "";
	longDescription = "";
	shortDesecription = "";
}

Room::Room(std::string nm, std::string longDesc, std::string shortDesc) {
	name = nm;
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

std::string Room::getName() {
	return name;
}

std::string Room::getLongDescription() {
	return longDescription;
}

std::string Room::getShortDescription() {
	return shortDesecription;
}

Room::~Room() {
}
