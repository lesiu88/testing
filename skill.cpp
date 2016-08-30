#include "skill.h"

Skill::Skill(std::string n, std::string s, int p)
{
  _name = n;
  _spell = s;
  _power = p;
}

int Skill::use()
{
  return _power;
}

int Skill::useOn(Being* target)
{
  return _power;
}

std::string Skill::spell()
{
  return _spell;
}