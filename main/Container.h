#pragma once
#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <vector>
#include "Item.h"

/* Class that represents a container.
 * Ex) Chest, bookcase, closet, shoebox, etc.
 * 
 * Data members
 * __________________________________________________
 * string name: stores the name of the container
 * string description: stores the description of the container
 * vector containerContent: Vector that stores Item pointers
 */
class Container {
public:
	Container();
	Container(std::string nm, std::string desc);
	
	void setName(std::string nm);
	void setDescription(std::string desc);
	void addItem(Item* item);

	std::string getName();
	std::string getDescription();
	~Container();

private:
	std::string name;
	std::string description;
	std::vector<Item*> containerContent;
};

#endif