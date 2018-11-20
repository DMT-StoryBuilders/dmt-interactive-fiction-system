#ifndef DOOR_H
#define DOOR_H
#include "Room.h"

/* Class that represents a door, path, or any connector of two rooms.
 *
 * Data members
 * ______________________________________
 * string name: stores the name of the door
 * string description: stores the description of the door
 * boolean isAccessible: stores the accesibility of the door (0 = not accessible, 1 = accessible)
 * pointer roomOnePtr: stores the address of the first room connected to the door
 * pointer roomTwoPtr: stores the address of the second room connected to the door
*/
class Door {
public:
	Door();
    Door(std::string nm, std::string desc, bool accessible);
	Door(std::string nm, std::string desc, bool accessible, Room &roomOne, Room &roomTwo);
	Door(std::string nm, std::string desc, bool accessible, Room *roomOnePointer, Room *roomTwoPointer);

	void setName(std::string nm);
	void setDescription(std::string desc);
	void setIsAccessible(bool accessible);

	void setRoomOne(Room *roomOnePointer);
	void setRoomTwo(Room *roomTwoPointer);

	std::string getName();
	std::string getDescription();
	bool getIsAccessible();
	Room* getRoomOne();
	Room* getRoomTwo();

	~Door();

private:
	std::string name;
	std::string description;
	bool isAccessible;
	Room *roomOnePtr;
	Room *roomTwoPtr;
};
#endif
