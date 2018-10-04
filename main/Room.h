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
	Room(std::string nm, std::string longDesc, std::string shortDesc);

	void setName(std::string nm);
	void setLongDescription(std::string longDesc);
	void setShortDescription(std::string shortDesc);
	 
	std::string getName();
	std::string getLongDescription();
	std::string getShortDescription();

	~Room();

private:
	std::string name;
	std::string longDescription;
	std::string shortDesecription;
};
#endif