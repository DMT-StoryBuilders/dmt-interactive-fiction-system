#include "playFunctions.h"
#include "stringReader.h"

void startGame(std::vector<Room> &rmList, std::vector<Door> &drList, std::vector<Container> &crList, std::vector<Individual> &ilList, std::vector<Item> &imList) {
	std::string action;

	Player player; //creates the player

	player.setCurrentRoom(&rmList[0]);

	std::cout << "____________________________________________________" << std::endl;
	std::cout << player.getCurrentRoom()->getName() << std::endl;
	std::cout << player.getCurrentRoom()->getShortDescription() << std::endl;

	std::cout << std::endl;
	std::cout << "> ";

	getline(std::cin, action);
	getline(std::cin, action); //user input

	transform(action.begin(), action.end(), action.begin(), ::toupper);
	while (action != "action") {
		stringBreaker(player, action, rmList, drList); //Breaks up the Input into a arrays of string words
		getline(std::cin, action);
	}
}
