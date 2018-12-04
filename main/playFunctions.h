#pragma once
#ifndef PLAYFUNCTIONS_H
#define PLAYFUNCTIONS_H
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Player.h"
#include "Room.h"
#include "Door.h"
#include "Container.h"
#include "Item.h"

void startGame(std::vector<Room> &rmList, std::vector<Door> &drList, std::vector<Container> &crList, std::vector<Individual> &ilList, std::vector<Item> &imList);

/*
void playerUse(Player &player, std::vector<Door> &drList);
void playerObserve(Player &player, std::vector<Room> &rmList, std::vector<Door> &drList);
void playerExamine(Player &player, std::vector<Room> &rmList, std::vector<Door> &drList);
*/
#endif
