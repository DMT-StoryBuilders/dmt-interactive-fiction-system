#pragma once
#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <vector>
#include <iostream>
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
	Container(std::string nm);
	Container(std::string nm, std::string desc);

	void setName(std::string nm);
	void setDescription(std::string desc);

	std::string getName();
	std::string getDescription();
	Item* getItem(int i);
	int getInventorySize();
	unsigned int i;

	void addItem(Item* item);
	void removeItem(int i);
	void printItems();
	void clearItems();

	~Container();

private:
	std::string name;
	std::string description;
	std::vector<Item*> inventory;
};

#endif
