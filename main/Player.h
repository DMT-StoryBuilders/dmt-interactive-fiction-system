#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Individual.h"
#include "Door.h"
#include "Item.h"

/* Class that represents the controllable player
 * Derived from base class "Individual"
 *
 * Functions
 * __________________________________
 * use(door): checks if the door is accessible before transferring the player to room on the other side.
 * observe: displays the short description of the object
 * examine: displays the long description of the object
 */
class Player : public Individual {
public:
	Player();
	Player(std::string nm, Room *roomPtr);
	Player(std::string nm, std::string desc, Room *roomPtr);
	Player(std::string nm, std::string desc, int hp, Room *roomPtr);

	void use(Door *door);

	void observe(Door door);
	void observe(Room room);
	void observe(Item item);

	void examine(Room room);
	void examine(Item item);

	~Player();
};
#endif