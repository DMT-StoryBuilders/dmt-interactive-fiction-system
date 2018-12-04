#pragma once
#ifndef IMPORTWORLD_H
#define IMPORTWORLD_H
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include "tinyxml2.h"
#include "Room.h"
#include "Door.h"
#include "Item.h"
#include "Container.h"
#include "Individual.h"

void loadDocument(std::vector<Room> &rmList, std::vector<Door> &drList, std::vector<Container> &crList,
    std::vector<Individual> &ilList, std::vector<Item> &imList);

void createItemObjects(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Item> &imList);
void createRoomObjects(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Room> &rmList, std::vector<Item> &imList);
void createDoorObjects(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr, std::vector<Door> &drList, std::vector<Room> &rmList);

void createContainerObjects(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr,
    std::vector<Container> &crList, std::vector<Room> &rmList, std::vector<Item> &imList);

void createIndividualObjects(tinyxml2::XMLDocument &worldDoc, tinyxml2::XMLNode* wNodePtr,
    std::vector<Individual> &ilList, std::vector<Room> &rmList, std::vector<Item> &imList);

#endif
