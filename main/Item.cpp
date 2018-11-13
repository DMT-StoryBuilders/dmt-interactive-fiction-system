#include "Item.h"


Item::Item() {
	name = "";
	shortDescription = "";
	longDescription = "";
	durability = 5;
}

Item::Item(std::string nm, std::string desc) {
	name = nm;
	shortDescription = desc;
	longDescription = desc;
	durability = 5;
}

Item::Item(std::string nm, std::string shortDesc, std::string longDesc) {
	name = nm;
	shortDescription = shortDesc;
	longDescription = longDesc;
	durability = 5;
}

Item::Item(std::string nm, std::string shortDesc, std::string longDesc, int hp) {
	name = nm;
	shortDescription = shortDesc;
	longDescription = longDesc;
	durability = hp;
}

void Item::setName(std::string nm) {
	name = nm;
}

void Item::setShortDescription(std::string shortDesc) {
	shortDescription = shortDesc;
}

void Item::setLongDescription(std::string longDesc) {
	longDescription = longDesc;
}

void Item::setDurability(int points) {
	durability = points;
}

std::string Item::getName() {
	return name;
}

std::string Item::getShortDescription() {
	return shortDescription;
}

std::string Item::getLongDescription() {
	return longDescription;
}

int Item::getDurability() {
	return durability;
}


Item::~Item()
{
}
