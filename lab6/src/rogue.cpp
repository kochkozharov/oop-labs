#include "rogue.h"

#include "bear.h"
#include "elf.h"

Rogue::Rogue(int x, int y) : NPC(NpcType::RogueType, x, y) {}
Rogue::Rogue(std::istream &is) : NPC(NpcType::RogueType, is) {}


void Rogue::print(std::ostream &os) { std::cout << *this; }

bool Rogue::is_rogue() const { return true; }

bool Rogue::fight(std::shared_ptr<Bear> other) {
    fight_notify(other, false);
    return false;
}

bool Rogue::fight(std::shared_ptr<Rogue> other) {
    fight_notify(other, true);
    return true;
}

bool Rogue::fight(std::shared_ptr<Elf> other) {
    fight_notify(other, false);
    return false;
}

bool Rogue::accept(std::shared_ptr<NPC> attacker) {
    return attacker->fight(std::static_pointer_cast<Rogue>(shared_from_this()));
}

void Rogue::save(std::ostream &os) {
    os << static_cast<int>(NpcType::RogueType) << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Rogue &elf) {
    os << "rogue: " << *static_cast<NPC *>(&elf) << std::endl;
    return os;
}