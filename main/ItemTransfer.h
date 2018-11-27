#ifndef ITEMTRANSFER_H
#define ITEMTRANSFER_H
#include <vector>
#include <iostream>
#include <string>
#include "Item.h"
#include "Container.h"
#include "Individual.h"
#include "Room.h"
using namespace std;

/********************************************
 * In any case of the item transfer class   *
 * the object that you are trasferring from *
 * is ALWAYS the first one you put in the   *
 * parameters. It goes item name, the       *
 * thing you are trasferring from, and the  *
 * thing you are trasferring to             *
 ********************************************/
class ItemTransfer {
public:

	ItemTransfer();

	int i = 0, invSize=0;
	bool found = false;
	string itemName;
	Item* itemTT;
	Room room1Temp;
	Room room2Temp;
	Individual person1;
	Individual person2;
	Container container1Temp;
	Container container2Temp;

	Room worldRoom;
	Container worldContainer;
	Individual worldIndividual;
	Room worldRoom2;
	Container worldContainer2;
	Individual worldIndividual2;

	Room getRoom();
	Individual getIndividual();
	Container getContainer();

	void setRoom(Room temp);
	void setIndividual(Individual temp);
	void setContainer(Container temp);

	Room getRoom2();
	Individual getIndividual2();
	Container getContainer2();

	void setRoom2(Room temp);
	void setIndividual2(Individual temp);
	void setContainer2(Container temp);

	ItemTransfer transferItem(string name, Individual individual1, Individual individual2, ItemTransfer temp);
	ItemTransfer transferItem(string name, Individual individual1, Room room2, ItemTransfer temp);
	ItemTransfer transferItem(string name, Individual individual1, Container container2, ItemTransfer temp);

	ItemTransfer transferItem(string name, Room room1, Individual individual2, ItemTransfer temp);
	ItemTransfer transferItem(string name, Room room1, Room room2, ItemTransfer temp);
	ItemTransfer transferItem(string name, Room room1, Container container2, ItemTransfer temp);

	ItemTransfer transferItem(string name, Container container1, Individual individual2, ItemTransfer temp);
	ItemTransfer transferItem(string name, Container container1, Room room2, ItemTransfer temp);
	ItemTransfer transferItem(string name, Container container1, Container container2, ItemTransfer temp);

};

#endif
