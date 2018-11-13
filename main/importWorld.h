#pragma once
#ifndef IMPORTWORLD_H
#define IMPORTWORLD_H
#include <iostream>
#include <string>
#include <cstring>
#include "tinyxml2.h"
#include "Room.h"
#include "Door.h"

void loadDocument(std::vector<Room> &rmList, std::vector<Door> &drList);
void createRoomObjects(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Room> &rmList);
void createDoorObjects(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Door> &drList, std::vector<Room> &rmList);

#endif
