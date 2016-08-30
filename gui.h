#ifndef GUARD_GUI_H
#define GUARD_GUI_H

#include "being.h"

#include <string>
#include <vector>
#include <sstream>

namespace gui
{
	void clearScreen();
	void printStats(Being& being);
	void printAttackMessage(AttackMessage);
	void printWindow(std::string, std::vector<std::string>);
	int getUserChoice(int);
	std::string getUserVerbalChoice();
	std::string combine(std::string, std::string, std::string::size_type);
	std::string printLine(std::string line, std::string border, unsigned short size, unsigned short padding);
	std::string to_string(double value);

} // namespace gui
#endif

