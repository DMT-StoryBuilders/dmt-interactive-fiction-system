#ifndef WRITINGTOOLS_H
#define WRITINGTOOLS_H
#include <iostream>
#include <sstream>
#include <vector>
#include "Door.h"
#include "Room.h"
#include "Container.h"
#include "Individual.h"
#include "Item.h"

// Function that displays the options for the creation menu
void displayCreateMenu();

// Function that allows user to operate the creation menu
void operateCreateMenu(std::vector<Room> &rmList, std::vector<Door> &drList, std::vector<Container> &crList, std::vector<Individual> &ilList, std::vector<Item> &imList);

/* Interactive function that creates a room based on the information
 * provided by the user.
 *
 * A vector of items is passed by reference in case the writer would like
 * to add items into the room.
 *
 * The created room is then added to the end of the room list.
 */
void createRoom(std::vector<Room> &rmList, std::vector<Item> &imList);

/* Interactive function that creates a door based on the information
 * provided by the user.
 *
 * A vector of rooms is passed by reference so the door can store the
 * addresses of the two rooms that will connect to it.
 *
 * The created door is then added to the end of the door list.
 */
void createDoor(std::vector<Room> &rmList, std::vector<Door> &drList);

/* Interactive function that creates a container based on the information
 * provided by the user.
 *
 * A vector of items is passed by reference in case the writer would like
 * to add items into the container.
 *
 * The created container is then added to the end of the container list.
 */
void createContainer(std::vector<Container> &crList, std::vector<Item> &imList);

/* Interactive function that creates an individual based on the information
 * provided by the user.
 *
 * A vector of rooms is passed by reference so the Individual can store the
 * address of room that it will be located in.
 *
 * A vector of items is passed by reference in case the writer would like
 * to add items into the container.
 *
 * The created container is then added to the end of the container list.
 */
void createIndividual(std::vector<Individual> &ilList, std::vector<Room> &rmList, std::vector<Item> &imList);

/* Interactive function that creates an item based on the information
 * provided by the user.
 *
 * The created item is then added to the end of the item list.
 */
void createItem(std::vector<Item> &imList);

#endif
