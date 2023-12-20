#include "bear.h"
#include "elf_.h"
#include "rogue.h"

Bear::Bear(int x, int y) : NPC(BearType, x, y) {}
Bear::Bear(std::istream &is) : NPC(BearType, is) {}

bool Bear::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Bear>(this,[](Bear*){}));
}

void Bear::print()
{
    std::cout << *this;
}

void Bear::save(std::ostream &os)
{
    os << BearType << std::endl;
    NPC::save(os);
}


bool Bear::fight(std::shared_ptr<Elf> other)
{
    fight_notify(other, true);
    return true;
}

bool Bear::fight(std::shared_ptr<Rogue> other)
{
    fight_notify(other, false);
    return false;
}

bool Bear::fight(std::shared_ptr<Bear> other)
{
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Bear &rogue)
{
    os << "bear: " << *static_cast<NPC *>(&rogue) << std::endl;
    return os;
}

bool Bear::is_close(const std::shared_ptr<NPC> &other) { return NPC::is_close(other, 5); }
