#pragma once
#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <vector>

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