#include "being.h"

Being::Being(std::string n)
{
	setName(n);
	setLevel(1);
	setHealth(getMaxHealth());
}

Being::Being(std::string n, short l)
{
	setName(n);
	setLevel(l);
	setHealth(getMaxHealth());
}

AttackMessage Being::attack(Being& victim)
{
	AttackMessage attackMessage;
	int damage = getPower();
	attackMessage.attacker = getName();
	attackMessage.defender = victim.getName();
	attackMessage.damage = victim.receiveDamage(damage);
	attackMessage.hp_left = victim.getHealth();
	return attackMessage;
}

int Being::receiveDamage(int dmg)
{
	dmg -= getResistance();
	if (dmg < 1)
		dmg = 1;
	setHealth(getHealth()-dmg);
	return dmg;
}

std::string Being::getName()
{
	return _name;
}

void Being::setName(std::string n)
{
	_name = n;
}

short Being::getHealth()
{
	return _health;
}

void Being::setHealth(short hp)
{
	_health = hp;
}

short Being::getMaxHealth()
{
	return 10+(getLevel()*4);
}

void Being::setMaxHealth(short mh)
{
	// TODO
	// Not sure if function is neccesary
	_maxHealth = mh;
}

short Being::getPower()
{
	return 3+(getLevel());
}

void Being::setPower(short p)
{
	// TODO
	// Not sure if function is neccesary
	_power = p;
}

short Being::getResistance()
{
	return 1+(getLevel());
}

void Being::setResistance(short r)
{
	// TODO
	// Not sure if function is neccesary
	_resistance = r;
}

short Being::getLevel()
{
	return _level;
}

void Being::setLevel(short l)
{
	_level = l;
}

int Being::getExperience()
{
	return _experience;
}

void Being::setExperience(int exp)
{
	_experience = exp;
}
