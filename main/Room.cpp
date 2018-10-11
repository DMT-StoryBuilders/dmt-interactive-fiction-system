#include "pch.h"
#include "Room.h"


Room::Room() {
	name = "";
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

Room::~Room() {
}
