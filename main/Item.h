#pragma once
#include <string>

/* Class that represents an item. Item could be anything creative.
 * Example: Key, Lockpicks, sword, note, etc.
 * 
 * Data members
 * ______________________________
 * string name: stores the name of the item
 * string short description: stores the short description of the item
 * string long description: stores the long description of the item
 * int durability: stores the durability of the item
 */

class Item {
public:
	Item();
	Item(std::string nm, std::string shortDesc);
	Item(std::string nm, std::string longDesc);
	Item(std::string nm, std::string shortDesc, std::string longDesc);
	Item(std::string nm, std::string shortDesc, std::string longDesc, int hp);
	
	void setName(std::string nm);
	void setShortDescription(std::string shortDesc);
	void setLongDescription(std::string longDesc);
	void setDurability(int hp);

	std::string getName();
	std::string getShortDescription();
	std::string getLongDescription();
	int getDurability();

	~Item();

private:
	std::string name;
	std::string shortDescription;
	std::string longDescription;
	int durability;
};

