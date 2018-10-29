#include <string>
#include <iostream>
#include <vector>
#include "pch.h"
#include "stringReader.h"

void stringBreaker(std::vector <std::string> &stringWords, std::string inputString) //Breaks up the Input into a arrays of string words
{
	std::cout << "Enter the string breaker up fucntion";
	std::string tempNewWords;
	std::string userInput = inputString;

	int vectorWordsCounter = 0;
	int stringCoutnerCharacter = 0;

	char currentcharacter = ' ';
	std::cout << "     Before the for loop ";

	for (int stringCoutnerCharacter = 0; stringCoutnerCharacter != userInput.length(); stringCoutnerCharacter++)
	{
		if (toupper(userInput.at(stringCoutnerCharacter)) == 'A' || toupper(userInput.at(stringCoutnerCharacter)) == 'B' || toupper(userInput.at(stringCoutnerCharacter)) == 'C' || toupper(userInput.at(stringCoutnerCharacter)) == 'D' || toupper(userInput.at(stringCoutnerCharacter)) == 'E' || toupper(userInput.at(stringCoutnerCharacter)) == 'F' || toupper(userInput.at(stringCoutnerCharacter)) == 'G' || toupper(userInput.at(stringCoutnerCharacter)) == 'H' || toupper(userInput.at(stringCoutnerCharacter)) == 'I' || toupper(userInput.at(stringCoutnerCharacter)) == 'J' || toupper(userInput.at(stringCoutnerCharacter)) == 'K' || toupper(userInput.at(stringCoutnerCharacter)) == 'L' || toupper(userInput.at(stringCoutnerCharacter)) == 'M' || toupper(userInput.at(stringCoutnerCharacter)) == 'N' || toupper(userInput.at(stringCoutnerCharacter)) == 'O' || toupper(userInput.at(stringCoutnerCharacter)) == 'P' || toupper(userInput.at(stringCoutnerCharacter)) == 'Q' || toupper(userInput.at(stringCoutnerCharacter)) == 'R' || toupper(userInput.at(stringCoutnerCharacter)) == 'S' || toupper(userInput.at(stringCoutnerCharacter)) == 'T' || toupper(userInput.at(stringCoutnerCharacter)) == 'U' || toupper(userInput.at(stringCoutnerCharacter)) == 'V' || toupper(userInput.at(stringCoutnerCharacter)) == 'W' || toupper(userInput.at(stringCoutnerCharacter)) == 'S' || toupper(userInput.at(stringCoutnerCharacter)) == 'W' || toupper(userInput.at(stringCoutnerCharacter)) == 'X' || toupper(userInput.at(stringCoutnerCharacter)) == 'Y' || toupper(userInput.at(stringCoutnerCharacter) == 'Z'))
		{
			tempNewWords += toupper(userInput.at(stringCoutnerCharacter));
			// std::cout << " " << tempNewWords;
		}
		else
		{
			stringWords.push_back(tempNewWords);
			vectorWordsCounter++;
			std::cout << " \\ " << tempNewWords;
			tempNewWords = "";
		}

	}
}
void stringFindAction(std::vector <std::string> &stringWords) // FIND the action word in the string 
{

	
}

