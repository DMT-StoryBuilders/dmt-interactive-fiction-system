#include "ItemTransfer.h"

//Each function is virtually identical so I will only comment the first
//There are so many overloads of the item transfer to maintain functionality
//regardless of the giver and receiver.

ItemTransfer::ItemTransfer() {
	i = 0; //index value
	invSize = 0; //size of first party's inventory
	found = false; //did it find the item

	//We create two of each type of inventory just to account for all transfer cases
	Room worldRoom;
	Container worldContainer;
	Individual worldIndividual;
	Room worldRoom2;
	Container worldContainer2;
	Individual worldIndividual2;
}

Container ItemTransfer::getContainer()
{
	return(worldContainer);
}

void ItemTransfer::setContainer(Container temp)
{
	worldContainer = temp;
}

Individual ItemTransfer::getIndividual()
{
	return(worldIndividual);
}

void ItemTransfer::setIndividual(Individual temp)
{
	worldIndividual = temp;
}

Room ItemTransfer::getRoom()
{
	return(worldRoom);
}

void ItemTransfer::setRoom(Room temp)
{
	worldRoom = temp;
}

/////////////////////////////////////////////////////////////////
Container ItemTransfer::getContainer2()
{
	return(worldContainer2);
}

void ItemTransfer::setContainer2(Container temp)
{
	worldContainer2 = temp;
}

Individual ItemTransfer::getIndividual2()
{
	return(worldIndividual2);
}

void ItemTransfer::setIndividual2(Individual temp)
{
	worldIndividual2 = temp;
}

Room ItemTransfer::getRoom2()
{
	return(worldRoom2);
}


void ItemTransfer::setRoom2(Room temp)
{
	worldRoom2 = temp;
}

ItemTransfer ItemTransfer::transferItem(string name, Individual individual1, Individual individual2, ItemTransfer temp)
{
	i = 0; //declare an index variable
	found = false; //self-explanatory
	invSize = individual1.getInventorySize();//get the size of the vector in the transferer class

	while (i < invSize && found == false) //this loop looks through to see if it can find the item name in question
	{                                     //it will exit on two conditions; either it checked everything in the vector
										  //or it found the item name

		itemTT = individual1.getItem(i);
		itemName = itemTT->getName();
		if (itemName == name) //found the named item
		{
			found = true;
		}
		else
		{
			i++;//check next index if item not found
		}
	}
	if (found == true)
	{
		individual2.addItem(individual1.getItem(i));//add item to the second party
		individual1.removeItem(i);//remove item from the first party
		temp.setIndividual(individual1);//update the giver in the return object
		temp.setIndividual2(individual2);//update the receiver in the return object
		std::cout << "Item transferred \n";//denote success in the console
	}
	else
	{
		std::cout << "Item not found \n";//denote failure due to not finding the item
	}
	return(temp);
}

ItemTransfer ItemTransfer::transferItem(string name, Individual individual1, Room room2, ItemTransfer temp)
{
	i = 0;
	found = false;
	invSize = individual1.getInventorySize();
	while (i < invSize && found == false)
	{
		itemTT = individual1.getItem(i);
		itemName = itemTT->getName();
		if (itemName == name)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	if (found == true)
	{
		room2.addItem(individual1.getItem(i));
		individual1.removeItem(i);
		std::cout << "Item transferred\n";
		temp.setRoom(room2);
		temp.setIndividual(individual1);


	}
	else
	{
		std::cout << "Item not found\n";
	}
	return(temp);
}

ItemTransfer ItemTransfer::transferItem(string name, Individual individual1, Container container2, ItemTransfer temp)
{
	i = 0;
	found = false;
	invSize = individual1.getInventorySize();
	while (i < invSize && found == false)
	{
		itemTT = individual1.getItem(i);
		itemName = itemTT->getName();
		if (itemName == name)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	if (found == true)
	{
		container2.addItem(individual1.getItem(i));
		individual1.removeItem(i);
		std::cout << "Item transferred\n";
		temp.setIndividual(individual1);
		temp.setContainer(container2);
	}
	else
	{
		std::cout << "Item not found\n";
	}
	return(temp);
}

ItemTransfer ItemTransfer::transferItem(string name, Room room1, Individual individual2, ItemTransfer temp)
{
	i = 0;
	found = false;
	invSize = room1.getInventorySize();
	while (i < invSize && found == false)
	{
		itemTT = room1.getItem(i);
		itemName = itemTT->getName();
		if (itemName == name)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	if (found == true)
	{
		individual2.addItem(room1.getItem(i));
		room1.removeItem(i);
		std::cout << "Item transferred\n";
		temp.setIndividual(individual2);
		temp.setRoom(room1);
	}
	else
	{
		std::cout << "Item not found\n";
	}
	return(temp);
}

ItemTransfer ItemTransfer::transferItem(string name, Room room1, Room room2, ItemTransfer temp)
{
	i = 0;
	found = false;
	invSize = room1.getInventorySize();
	while (i < invSize && found == false)
	{
		itemTT = room1.getItem(i);
		itemName = itemTT->getName();
		if (itemName == name)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	if (found == true)
	{
		room2.addItem(room1.getItem(i));
		room1.removeItem(i);
		std::cout << "Item transferred\n";
		temp.setRoom(room1);
		temp.setRoom2(room2);
	}
	else
	{
		std::cout << "Item not found\n";
	}
	return(temp);
}

ItemTransfer ItemTransfer::transferItem(string name, Room room1, Container container2, ItemTransfer temp)
{
	i = 0;
	found = false;
	invSize = room1.getInventorySize();
	while (i < invSize && found == false)
	{
		itemTT = room1.getItem(i);
		itemName = itemTT->getName();
		if (itemName == name)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	if (found == true)
	{
		container2.addItem(room1.getItem(i));
		room1.removeItem(i);
		std::cout << "Item transferred\n";
		temp.setContainer(container2);
		temp.setRoom(room1);
	}
	else
	{
		cout << "Item not found\n";
	}
	return(temp);
}

ItemTransfer ItemTransfer::transferItem(string name, Container container1, Individual individual2, ItemTransfer temp)
{
	i = 0;
	found = false;
	invSize = container1.getInventorySize();
	while (i < invSize && found == false)
	{
		itemTT = container1.getItem(i);
		itemName = itemTT->getName();
		//cout << "\n" << itemName << "\n";
		if (itemName == name)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	if (found == true)
	{
		individual2.addItem(container1.getItem(i));
		container1.removeItem(i);
		std::cout << "Item transferred\n";
		temp.setIndividual(individual2);
		temp.setContainer(container1);
	}
	else
	{
		std::cout << "Item not found\n";
	}
	return(temp);
}

ItemTransfer ItemTransfer::transferItem(string name, Container container1, Room room2, ItemTransfer temp)
{
	i = 0;
	found = false;
	invSize = container1.getInventorySize();
	while (i < invSize && found == false)
	{
		itemTT = container1.getItem(i);
		itemName = itemTT->getName();
		if (itemName == name)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	if (found == true)
	{
		room2.addItem(container1.getItem(i));
		container1.removeItem(i);
		std::cout << "Item transferred\n";
		temp.setRoom(room2);
		temp.setContainer(container1);
	}
	else
	{
		std::cout << "Item not found\n";
	}
	return(temp);
}

ItemTransfer ItemTransfer::transferItem(string name, Container container1, Container container2, ItemTransfer temp)
{
	i = 0;
	found = false;
	invSize = container1.getInventorySize();
	while (i < invSize && found == false)
	{
		itemTT = container1.getItem(i);
		itemName = itemTT->getName();
		if (itemName == name)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}
	if (found == true)
	{
		container2.addItem(container1.getItem(i));
		container1.removeItem(i);
		std::cout << "Item transferred\n";
		temp.setContainer(container2);
		temp.setContainer2(container1);
	}
	else
	{
		std::cout << "Item not found\n";
	}
	return(temp);
}
