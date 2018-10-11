#pragma once
#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <vector>

/* Class that represents a room, outdoor yard, or any small portion of the world.
 *
 * Data members
 * _________________________________
 * string name: stores the name of the room
 * string longDescription: stores the long description of the room upon initial encounter
 * string shortDescription: stores the short description of room after initial encounter
*/
class Room {
public:
	Room();
	Room(std::string nm, std::string shortDesc, std::string longDesc);

	void setName(std::string nm);
	void setShortDescription(std::string shortDesc);
	void setLongDescription(std::string longDesc);
	 
	std::string getName();
	std::string getShortDescription();
	std::string getLongDescription();

	~Room();

private:
	std::string name;
	std::string shortDesecription;
	std::string longDescription;
};
#endif