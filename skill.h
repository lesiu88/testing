#ifndef _GUARD_SKILL_H
#define _GUARD_SKILL_H

class Being;

#include <string>

class Skill
{
  private:
    std::string   _name;
    std::string   _spell;
    int           _power;
  public:
    // Constructor (name, spell, power)
    // name - Name of the spell to appear in battle log
    // spell - Code name, type to invoke
    // power - Power of the spell, negative values for defensive spells
    Skill(std::string, std::string, int);
    int use();
    int useOn(Being*);
    std::string spell();
};

#endif
