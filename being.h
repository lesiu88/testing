#ifndef GUARD_BEING_H
#define GUARD_BEING_H

#include <string>


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
		short			_health;
		short			_maxHealth;

		short			_power;
		short			_resistance;

		short			_level;
		int				_experience;
		short			_expYield;

	public:
		/*	+++ CONSTUCTORS +++ */

		// With name only, rest default
		Being(std::string);
		// With name and level
		Being(std::string, short);


		/* +++ SETTERS AND GETTERS +++ */

		std::string		getName();
		void			setName(std::string);

		short			getHealth();
		void			setHealth(short);

		short			getMaxHealth();
		void			setMaxHealth(short);

		short			getPower();
		void			setPower(short);

		short			getResistance();
		void			setResistance(short);

		short			getLevel();
		void			setLevel(short);

		int				getExperience();
		void			setExperience(int);

		AttackMessage	attack(Being&);
		int				receiveDamage(int);
};

#endif

