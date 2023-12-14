#include "bear.h"

#include "elf.h"
#include "rogue.h"

Bear::Bear(int x, int y) : NPC(NpcType::BearType, x, y) {}
Bear::Bear(std::istream &is) : NPC(NpcType::BearType, is) {}

void Bear::print() { std::cout << *this; }

void Bear::save(std::ostream &os) {
    os << static_cast<int>(NpcType::BearType) << std::endl;
    NPC::save(os);
}

bool Bear::is_bear() const { return true; }

bool Bear::fight(std::shared_ptr<Bear> other) {
    fight_notify(other, false);
    return false;
}

bool Bear::fight(std::shared_ptr<Elf> other) {
    fight_notify(other, true);
    return true;
}

bool Bear::fight(std::shared_ptr<Rogue> other) {
    fight_notify(other, false);
    return false;
}

bool Bear::accept(std::shared_ptr<NPC> attacker) {
    return attacker->fight(std::static_pointer_cast<Bear>(shared_from_this()));
}

std::ostream &operator<<(std::ostream &os, Bear &bear) {
    os << "bear: " << *static_cast<NPC *>(&bear) << std::endl;
    return os;
}