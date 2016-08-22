#include "gui.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

// Convert value to string
std::string gui::to_string(double value)
{
	// create output stream
	std::ostringstream os;
	// throw value into stream
	os << value;
	// convert outputstream to string and return
	return os.str();
}

// Clear screen
void gui::clearScreen()
{
	for (int i=0; i!=50; ++i)
		std::cout << std::endl;
}

// Get user input from 1 to max
int gui::getUserChoice(int max)
{
	int choice = -1;
	std::string line;

	while (choice < 1)
	{
		std::getline(std::cin, line);
		choice = atoi(line.c_str());
	}
	return choice;
}

// Print attack message
void gui::printAttackMessage(AttackMessage am)
{
	std::string::size_type messageLength;

	std::string line = am.attacker + "'s attack has dealt " + to_string(am.damage) + " damage to " + am.defender;
	messageLength = line.size() + 5;

	std::cout << printLine(line, "#", messageLength, 1);
	if (am.hp_left > 0)
		line = am.defender + " has " + to_string(am.hp_left) + " hp left.";
	else
		line = am.defender + " is dead.";
	std::cout << printLine(line, "#", messageLength, 1);
}

// Print being's stats
void gui::printStats(Being& being)
{
	// Vector to hold being's stats that will be printed
	std::vector<std::string> lines;
	std::string::size_type length = being.getName().size();

	// Check if name isn't too short
	if (length < 12)
		length = 12;

	// Add lines to print
	lines.push_back(combine("Level:", to_string(being.getLevel()), length));
	lines.push_back(combine("Health:", to_string(being.getHealth()), length));
	lines.push_back(combine("Power:", to_string(being.getPower()), length));
	lines.push_back(combine("Def:", to_string(being.getResistance()), length));

	// Pass name as a title, and stats as lines in a vector
	printWindow(being.getName(), lines);
}

// Combine two strings in one
std::string gui::combine(std::string left_word, std::string right_word, std::string::size_type length)
{
	return left_word + std::string(length-left_word.size()-right_word.size(), ' ') + right_word;
}

// Print string in line with a border
std::string gui::printLine(std::string line, std::string border, unsigned short size, unsigned short padding)
{
	// Check if size is not too short
	if (size < (line.size()+2+(padding*2)))
		size = line.size()+2+(padding*2);
	// Prepare the line
	return border + std::string(padding, ' ') + line + std::string(size-line.size()-2-padding, ' ') + border + "\n";
}

// Print out a window with a title and list of lines in vector
void gui::printWindow(std::string title, std::vector<std::string> lines)
{
	// Find the longest word to set the size of the window
	std::string::size_type maxlen = title.size();

	for (std::vector<std::string>::size_type i=0; i != lines.size(); ++i)
	{
		if (maxlen < lines[i].size())
			maxlen = lines[i].size();
	}
	// Add four for border and padding
	maxlen += 4;

	std::cout << std::string(maxlen, '-') << std::endl;
	std::cout << printLine(title, "|", maxlen, 1);
	std::cout << std::string(maxlen, '-') << std::endl;

	for (std::vector<std::string>::size_type i=0; i != lines.size(); ++i)
	{
		std::cout << "| " << lines[i] << std::string(maxlen-lines[i].size()-3, ' ') << "|" << std::endl;
	}
	std::cout << std::string(maxlen, '-') << std::endl;
}

