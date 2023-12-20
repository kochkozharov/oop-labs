#include "rogue.h"
#include "bear.h"
#include "elf_.h"

Rogue::Rogue(int x, int y) : NPC(RogueType, x, y) {}
Rogue::Rogue(std::istream &is) : NPC(RogueType, is) {}

void Rogue::print()
{
    std::cout << *this;
}

bool Rogue::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Rogue>(this,[](Rogue*){}));
}

void Rogue::save(std::ostream &os)
{
    os << RogueType << std::endl;
    NPC::save(os);
}


bool Rogue::fight(std::shared_ptr<Elf> other)
{
    fight_notify(other, true);
    return true;
}

bool Rogue::fight(std::shared_ptr<Rogue> other)
{
    fight_notify(other, false);
    return false;
}

bool Rogue::fight(std::shared_ptr<Bear> other)
{
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Rogue &rogue)
{
    os << "rogue: " << *static_cast<NPC *>(&rogue) << std::endl;
    return os;
}