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

void Player::observe(Door *doorPtr) {
	std::cout << "\n" << doorPtr->getDescription() << std::endl;
}

void Player::observe(Room *roomPtr) {
	std::cout << "\n" << roomPtr->getShortDescription() << std::endl;
}

void Player::observe(Item *itemPtr) {
	std::cout << "\n" << itemPtr->getShortDescription() << std::endl;
}

void Player::examine(Door *doorPtr) {
	std::cout << "\n" << doorPtr->getDescription() << std::endl;
}

void Player::examine(Room *roomPtr) {
	std::cout << "\n" << roomPtr->getLongDescription() << std::endl;
}

void Player::examine(Item *itemPtr) {
	std::cout << "\n" << itemPtr->getLongDescription() << std::endl;
}

void Player::pickup(std::string itemName) {

	// Capitalize every letter in the item argument
	std::transform(itemName.begin(), itemName.end(), itemName.begin(), ::toupper);

	// For loop that goes through the current room's inventory.
	// Capitalize the current item's name and compare it to the name of the item
	// that we're searching for.
	// If both names are the same, add the item to the player's inventory, and
	// remove it from the current's inventory.
	for (int i = 0; i < getCurrentRoom()->getInventorySize(); i++) {

		std::string roomItemName = getCurrentRoom()->getItemName(i);
		std::transform(roomItemName.begin(), roomItemName.end(), roomItemName.begin(), ::toupper);

		if (roomItemName == itemName) {
			addItem(getCurrentRoom()->getItem(i));
			getCurrentRoom()->removeItem(i);
		}// end if
	}// end for
}// end drop

void Player::drop(std::string itemName) {

	// Capitalize every letter in the item argument
	std::transform(itemName.begin(), itemName.end(), itemName.begin(), ::toupper);

	// For loop that goes through the player's inventory.
	// Capitalize the current item's name and compare it to the name of the item
	// that we're searching for.
	// If both names are the same, add the item to the room's inventory, and
	// remove it from the player's inventory.
	for (int i = 0; i < getInventorySize(); i++) {

		std::string playerItemName = inventory[i]->getName();
		std::transform(playerItemName.begin(), playerItemName.end(), playerItemName.begin(), ::toupper);

		if (playerItemName == itemName) {
			getCurrentRoom()->addItem(inventory[i]);
			inventory.erase(inventory.begin() + i);
		}// end if
	}// end for
}// end drop

Player::~Player() {
}
