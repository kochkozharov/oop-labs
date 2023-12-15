#pragma once
#include "npc.h"



struct Elf : public NPC {
    Elf(int x, int y,const std::string &name);
    Elf(std::istream &is);
    void print(std::ostream &os) override;
    void save(std::ostream &os) override;
    bool fight(std::shared_ptr<Bear> other) override;
    bool fight(std::shared_ptr<Elf> other) override;
    bool fight(std::shared_ptr<Rogue> other) override;
    bool accept(std::shared_ptr<Visitor> v) override;
    friend std::ostream &operator<<(std::ostream &os, Elf &knight);
};