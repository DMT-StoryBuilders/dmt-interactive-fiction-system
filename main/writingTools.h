#pragma once
#ifndef WRITINGTOOLS_H
#define WRITINGTOOLS_H
#include <iostream>
#include <sstream>
#include <vector>
#include "Door.h"
#include "Room.h"

// Function that displays the options for the creation menu
void displayCreateMenu();

// Function that allows user to operate the creation menu
void operateCreateMenu(std::vector<Room> &rmList, std::vector<Door> &drList);

/* Function that creates a room based on the information
 * provided by the user. The created room is then added
 * to the end of the room list.
*/
void createRoom(std::vector<Room> &rmList);

/* Function that creates a door based on the information
 * provided by the user. The created door is then added
 * to the end of the door list.
*/
void createDoor(std::vector<Room> &rmList, std::vector<Door> &drList);
#endif