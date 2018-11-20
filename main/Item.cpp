#include "Item.h"


Item::Item() {
	name = "";
	shortDescription = "";
	longDescription = "";
}

Item::Item(std::string nm, std::string desc) {
	name = nm;
	shortDescription = desc;
	longDescription = desc;
}

Item::Item(std::string nm, std::string shortDesc, std::string longDesc) {
	name = nm;
	shortDescription = shortDesc;
	longDescription = longDesc;
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

std::string Item::getName() {
	return name;
}

std::string Item::getShortDescription() {
	return shortDescription;
}

std::string Item::getLongDescription() {
	return longDescription;
}

Item::~Item()
{
}
