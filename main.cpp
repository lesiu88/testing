#include "being.h"
#include "game_strings.h"
#include "gui.h"

#include <iostream>
#include <unistd.h>

void fight(Being&, Being&);

int main()
{
	gui::clearScreen();
	std::cout << welcome_message << std::endl;

	// Create Player
	std::cout << get_player_name_message << std::endl;
	std::string name;
	std::getline(std::cin, name);
	Being player(name, 4);

	// Create Enemies
	std::vector<Being> mobs;

	for (int i=0; i!=10; ++i)
	{
		if ( i % 2 != 0 )
		{
			Being rat("Rat", 11);
			mobs.push_back(rat);
		}
		else
		{
			Being scorpion("Scorpion", 15);
			mobs.push_back(scorpion);
		}
	}

	std::vector<Being>::size_type current_enemy = 1;

	gui::clearScreen();
	gui::printStats(player);


	bool gameIsRunning = true;

	// Game loop
	while (gameIsRunning)
	{
		std::cout << main_choice_message;
		switch (gui::getUserChoice(3))
		{
			case 3:
				gui::clearScreen();
				std::cout << "Hunting..." << std::endl;
				gui::printStats(player);
				sleep(2);
				fight(player, mobs[current_enemy]);
				++current_enemy;
				break;
			case 2:
				gui::clearScreen();
				gui::printStats(player);
				break;
			case 1:
				gui::clearScreen();
				gameIsRunning = false;
				break;
		}
		if (player.getHealth() < 1)
			gameIsRunning = false;
	}

	std::cout << goodbye_message << std::endl;
	return 0;
}

void fight(Being& attacker, Being& defender)
{
	bool fightIsRunning = true;
	gui::clearScreen();
	std::cout << attacker.getName() << " encountered " << defender.getName() << std::endl;

	while (fightIsRunning)
	{
		std::cout << fight_choice_message;

		switch (gui::getUserChoice(2))
		{
			// Attack
			case 2:
				gui::clearScreen();
				gui::printAttackMessage(attacker.attack(defender));
				sleep(3);
				if (defender.getHealth() < 1)
					fightIsRunning = false;
			break;
			case 1:
				fightIsRunning = false;
			break;
		}
		if (defender.getHealth() > 0)
		{
			gui::printAttackMessage(defender.attack(attacker));
			sleep(3);
			if (attacker.getHealth() < 1)
				fightIsRunning = false;
		}
	}
	gui::clearScreen();
}
