#ifndef GUARD_BEING_H
#define GUARD_BEING_H

#include "skill.h"

#include <string>
#include <vector>

struct AttackMessage
{
	std::string attacker;
	std::string defender;
	int damage;
	int hp_left;
};

class Being
{
	private:
		std::string		_name;
		int						_health;
		int						_maxHealth;

		int						_power;
		int						_resistance;

		int						_level;
		int						_experience;
		int						_expYield;
		
		std::vector<Skill> _skills;
		std::vector<Skill>::iterator skill;

	public:
		/*	+++ CONSTUCTORS +++ */

		// With name only, rest default
		Being(std::string);
		// With name and level
		Being(std::string, short);


		/* +++ SETTERS AND GETTERS +++ */

		std::string name();

		int currentHealth();
		int maxHealth();
		bool isAlive();
		int level();
		int experience();
		bool knows(std::string);
		void use(std::string);
		
		void learnSkill(Skill&);

		AttackMessage	attack(Being&, Skill&);
		int receiveDamage(int);
};

#endif

