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

/* Function that creates a room based on the information
 * provided by the user. The created room is then added
 * to the end of the room list.
 */
void createRoom(std::vector<Room> &rmList, std::vector<Item> &imList);

/* Function that creates a door based on the information
 * provided by the user. The created door is then added
 * to the end of the door list.
 */
void createDoor(std::vector<Room> &rmList, std::vector<Door> &drList);

/* Function that creates a container based on the information
 * provided by the user. The created container is then added
 * to the end of the container list.
 */
void createContainer(std::vector<Container> &crList, std::vector<Item> &imList);

void createIndividual(std::vector<Individual> &ilList, std::vector<Room> &rmList, std::vector<Item> &imList);

void createItem(std::vector<Item> &imList);
#endif
