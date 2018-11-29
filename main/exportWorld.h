#ifndef EXPORTWORLD_H
#define EXPORTWORLD_H
#include <iostream>
#include <string>
#include <cstring>
#include "tinyxml2.h"
#include "Room.h"
#include "Door.h"
#include "Container.h"
#include "Item.h"
#include "Individual.h"

void createDocument(std::vector<Room> &rmList, std::vector<Door> &drList,
    std::vector<Container> &crList, std::vector<Individual> &ilList, std::vector<Item> &imList);

void createRoomElements(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Room> &rmList);
void createDoorElements(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Door> &drList);
void createItemElements(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Item> &imList);
void createContainerElements(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Container> &crlist);
void createIndividualElements(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Individual> &ilList);

#endif
