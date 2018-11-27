#ifndef ITEM_H
#define ITEM_H
#include <string>

/* Class that represents an item.
 * Ex) Key, lockpicks, sword, note, etc.
 *
 * Data members
 * ________________________________________
 * string name: stores the name of the item
 * string short description: stores the short description of the item after initial encounter
 * string long description: stores the long description of the item upon intial encounter
 * int durability: stores the durability of the item
 */
class Item {
public:
	Item();
	Item(std::string nm, std::string desc);
	Item(std::string nm, std::string shortDesc, std::string longDesc);

	void setName(std::string nm);
	void setShortDescription(std::string shortDesc);
	void setLongDescription(std::string longDesc);

	std::string getName();
	std::string getShortDescription();
	std::string getLongDescription();

	~Item();

private:
	std::string name;
	std::string shortDescription;
	std::string longDescription;
};
#endif
