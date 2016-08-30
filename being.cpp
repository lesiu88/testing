#include "being.h"

Being::Being(std::string n)
{
	_name = n;
	_level = 1;
	_health = maxHealth();
	_power = 6;
	_resistance = 2;
}

Being::Being(std::string n, short l)
{
	_name = n;
	_level = l;
	_health = maxHealth();
	_power = 5*l;
	_resistance = 2*l;
}

AttackMessage Being::attack(Being& victim, Skill& s)
{
	AttackMessage attackMessage;
	int damage = _power*s.use();
	attackMessage.attacker = name();
	attackMessage.defender = victim.name();
	attackMessage.damage = victim.receiveDamage(damage);
	attackMessage.hp_left = victim.currentHealth();
	return attackMessage;
}

void Being::learnSkill(Skill& s)
{
	_skills.push_back(s);
	skill = _skills.begin();
}

bool Being::knows(std::string spell_name)
{
	for (skill = _skills.begin(); skill != _skills.end(); skill++)
	{
		if (spell_name.compare(skill->spell()))
		{
			return true;
		}
	}
	return false;
}

void Being::use(std::string spell_name)
{
	// TODO
}

int Being::receiveDamage(int dmg)
{
	dmg -= _resistance;
	if (dmg < 1)
		dmg = 1;
	_health -= dmg;
	return dmg;
}

std::string Being::name()
{
	return _name;
}

int Being::currentHealth()
{
	return _health;
}

int Being::maxHealth()
{
	return 20+level()*6;
}

bool Being::isAlive()
{
	if (_health > 0)
		return true;
	return false;
}

int Being::level()
{
	return _level;
}

int Being::experience()
{
	return _experience;
}
