#include "fight.h"

Fight::Fight()
{
  is_over = false;
}

Fight::Fight(Being& a, Being& d)
{
  setAttacker(&a);
  setDefender(&d);
  is_over = false;
}

void Fight::stop()
{
  is_over = true;
}

void Fight::setAttacker(Being* a)
{
  if (!a->isAlive())
    is_over = true;
  attacker = a;
}

void Fight::setDefender(Being* d)
{
  if (!d->isAlive())
    is_over = true;
  defender = d;
}
    
Being* Fight::getAttacker()
{
  return attacker;
}

Being* Fight::getDefender()
{
  return defender;
}
    
bool Fight::isOver()
{
  return is_over;
}