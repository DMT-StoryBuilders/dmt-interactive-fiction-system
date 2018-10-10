#pragma once
#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include <string>
#include "Room.h"

/* Class that represents an individual/character.
 * Ex) Friendly merchant, goblin fighter, dragon, etc.
 *
 * Data members
 * ______________________________________________
 * string name: stores the name of the individual
 * string description: stores the description of the individual
 * int health: stores the health of the individual
 * pointer currentRoomPtr: stores the address of the room that the individual is currently in
 */
class Individual {
public:
	Individual();
	Individual(std::string nm, Room *roomPtr);
	Individual(std::string nm, std::string desc, Room *roomPtr);
	Individual(std::string nm, std::string desc, int hp, Room *roomPtr);

	void setName(std::string nm);
	void setDescription(std::string desc);
	void setHealth(int hp);
	void setCurrentRoom(Room &room);
	void setCurrentRoom(Room *roomPtr);

	std::string getName();
	std::string getDescription();
	int getHealth();
	Room* getCurrentRoom();

	~Individual();

protected:
	std::string name;
	std::string description;
	int health;
	Room* currentRoomPtr;
};
#endif