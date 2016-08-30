#ifndef GUARD_GAME_STRINGS_H
#define GUARD_GAME_STRINGS_H

#include <string>

struct gameMessage
{
	std::string type;
	std::string title;
};

std::string welcome_message = "Simple Console Role-Playing Game Project, v0.00.1";
std::string get_player_name_message = "What is your name?";
std::string goodbye_message = "Bye.";

// Monster names
std::string rat_name = "Rat";
std::string scorpion_name = "Scorpion";

// Activities names
std::string hunting_string = "Hunting...";
std::string encounter_string = " encountered ";

std::string main_choice_message = "What do you want to do now?\n2 - Print Stats\n3 - Go Hunting\n\n1 - Exit Game\n";
std::string fight_choice_message = "What do you want to do now?\n3 - Power Attack\n2 - Attack\n\n1 - Run Away\n";
#endif
