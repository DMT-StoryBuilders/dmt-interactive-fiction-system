#include "pch.h"
#include "Player.h"


Player::Player() : Individual() {
}

Player::Player(std::string nm, Room *roomPtr) : Individual(nm, roomPtr) {
}

Player::Player(std::string nm, std::string desc, Room * roomPtr) : Individual(nm, desc, roomPtr) {
}

Player::Player(std::string nm, std::string desc, int hp, Room * roomPtr) : Individual(nm, desc, hp, roomPtr) {
}

/* 
 * First, the function checks if the door is accessible.
 * If the door is accessible, compare the player's current room address with
 * the two addresses of rooms connected to the door.

 * If the player's address is the same as room one's address, change the player's
 * address to room two's address, nnd vice versa.
 */
void Player::use(Door *door) {
	if (door->getIsAccessible() == true) {
		if (getCurrentRoom() == door->getRoomOne()) {
			setCurrentRoom(door->getRoomTwo());
		}
		else if (getCurrentRoom() == door->getRoomTwo()) {
			setCurrentRoom(door->getRoomOne());
		}
	}//end if accessible
}

void Player::observe(Door door) {
	std::cout << door.getDescription() << std::endl;
}

void Player::observe(Room room) {
	std::cout << room.getShortDescription() << std::endl;
}

void Player::observe(Item item) {
	std::cout << item.getShortDescription() << std::endl;
}

void Player::examine(Room room) {
	std::cout << room.getLongDescription() << std::endl;
}

void Player::examine(Item item) {
	std::cout << item.getLongDescription() << std::endl;
}

Player::~Player() {
}
