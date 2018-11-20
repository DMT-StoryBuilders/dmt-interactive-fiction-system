#ifndef EXPORTWORLD_H
#define EXPORTWORLD_H
#include <iostream>
#include <string>
#include <cstring>
#include "tinyxml2.h"
#include "Room.h"
#include "Door.h"
#include "Container.h"

void createDocument(std::vector<Room> &rmList, std::vector<Door> &drList);
void createRoomElements(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Room> &rmList);
void createDoorElements(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Door> &drList);
//void createContainerElements(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Container> &crlist);

#endif
