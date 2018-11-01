#pragma once
#ifndef STRINGREADER_H
#define STRINGREADER_H
#include <iostream>
#include "Individual.h"
#include "Door.h"
#include "Item.h"

void stringBreaker(std::string inputString, std::vector<Room> &rmList, std::vector<Door> &drList);

void stringFindAction( std::string userInput, std::vector <std::string> &stringWords,  std::vector<Room> &rmList, std::vector<Door> &drList);

#endif
