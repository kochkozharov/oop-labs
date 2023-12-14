#pragma once
#include "npc.h"

struct Bear : public NPC {
    Bear(int x, int y);
    Bear(std::istream &is);


    void print(std::ostream &os) override;

    void save(std::ostream &os) override;
    bool is_bear() const override;

    bool fight(std::shared_ptr<Bear> other) override;
    bool fight(std::shared_ptr<Elf> other) override;
    bool fight(std::shared_ptr<Rogue> other) override;

    bool accept(std::shared_ptr<NPC> attacker) override;

    friend std::ostream &operator<<(std::ostream &os, Bear &knight);
};