#include "being.h"
#include "fight.h"
#include "game_strings.h"
#include "gui.h"
#include "skill.h"

#include <iostream>
#include <unistd.h>

int main()
{
	// Clear the screen and print welcome message
	gui::clearScreen();
	std::cout << welcome_message << std::endl;

	// Create Player
	std::cout << get_player_name_message << std::endl;
	std::string name;
	std::getline(std::cin, name);
	Being player(name, 3);

	// Create Enemies
	std::vector<Being> mobs;
	
	// Load Skills
	Skill attack("Normal Attack", "attack", 1);
	Skill power_attack("Power Attack", "power", 3);
	Skill heal("Heal", "heal", 1);

	for (int i=0; i!=10; ++i)
	{
		if ( i % 2 == 0 )
		{
			Being rat(rat_name, 1);
			mobs.push_back(rat);
		}
		else
		{
			Being scorpion(scorpion_name, 2);
			mobs.push_back(scorpion);
		}
	}
	std::vector<Being>::iterator current_enemy = mobs.begin();
	
	gui::clearScreen();
	gui::printStats(player);
	
	player.learnSkill(attack);
	player.learnSkill(power_attack);
	player.learnSkill(heal);
	bool gameIsRunning = true;
	Fight* fight;

	// Game loop
	while (gameIsRunning)
	{
		std::cout << main_choice_message;
		switch (gui::getUserChoice(3))
		{
			// Go Hunting
			case 3:
				gui::clearScreen();
				std::cout << hunting_string << std::endl;
				gui::printStats(player);
				sleep(2);
				fight = new Fight(player, *current_enemy);
				++current_enemy;
				gui::clearScreen();
				std::cout << fight->getAttacker()->name() << encounter_string << fight->getDefender()->name() << std::endl;
				
				while (!fight->isOver())
				{
					gui::clearScreen();
					std::cout << fight_choice_message;
					std::string choice = gui::getUserVerbalChoice();
					
					if (choice.compare("run") == 0)
						fight->stop();
					else if (fight->getAttacker()->knows(choice))
					{
						std::cout << "Spell known" << std::endl;
					}
					else
						std::cout << "Spell unknown" << std::endl;
					
					sleep(3);
					/*
					switch (gui::getUserChoice(3))
							{
								// Power Attack
								case 3:
									gui::printAttackMessage(fight->getAttacker()->attack(*(fight->getDefender()), power_attack));
									sleep(3);
								break;
								// Attack
								case 2:
									gui::printAttackMessage(fight->getAttacker()->attack(*(fight->getDefender()), attack));
									sleep(3);
								break;
								case 1:
									fight->stop();
								break;
							}
							if (!fight->getDefender()->isAlive())
								fight->stop();
								if (fight->getDefender()->isAlive())
								{
									gui::printAttackMessage(fight->getDefender()->attack(*(fight->getAttacker()), attack));
									sleep(3);
									if (!fight->getAttacker()->isAlive())
										fight->stop();
								}
								*/
				}
				break;
			// Print player stats
			case 2:
				gui::clearScreen();
				gui::printStats(player);
				break;
			
				// Exit game
			case 1:
				gui::clearScreen();
				gameIsRunning = false;
				break;
		}
		if (!player.isAlive())
			gameIsRunning = false;
	}

	std::cout << goodbye_message << std::endl;
	return 0;
}
