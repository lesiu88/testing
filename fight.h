#ifndef GUARD_FIGHT_H
#define GUARD_FIGHT_H

#include "being.h"
#include <vector>

class Fight
{
  private:
    Being* attacker;
    Being* defender;
    bool is_over;
  public:
    Fight();
    Fight(Being&, Being&);
    
    void setAttacker(Being*);
    void setDefender(Being*);
    
    Being* getAttacker();
    Being* getDefender();
    
    bool isOver();
    void stop();
};

#endif
