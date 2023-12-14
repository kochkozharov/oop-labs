#pragma once
#include "npc.h"

struct Elf : public NPC {
    Elf(int x, int y);
    Elf(std::istream &is);
    void print(std::ostream &os) override;
    void save(std::ostream &os) override;
    bool is_elf() const override;
    bool fight(std::shared_ptr<Bear> other) override;
    bool fight(std::shared_ptr<Elf> other) override;
    bool fight(std::shared_ptr<Rogue> other) override;
    bool accept(std::shared_ptr<NPC> attacker) override;
    friend std::ostream &operator<<(std::ostream &os, Elf &knight);
};