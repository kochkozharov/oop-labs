#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>

// type for npcs
struct NPC;
struct Bear;
struct Elf;
struct Rogue;
using set_t = std::set<std::shared_ptr<NPC>>;

enum class NpcType
{
    Unknown = 0,
    BearType = 1,
    ElfType = 2,
    RogueType = 3
};

struct IFightObserver{
    virtual void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender,bool win) = 0;
};

struct NPC : public std::enable_shared_from_this<NPC>
{
    NpcType type;
    int x{0};
    int y{0};
    std::vector<std::shared_ptr<IFightObserver>> observers;

    NPC(NpcType t, int _x, int _y);
    NPC(NpcType t, std::istream &is);

    void subscribe(std::shared_ptr<IFightObserver>observer );
    void fight_notify(const std::shared_ptr<NPC> defender,bool win);
    virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;

    virtual bool is_bear() const;
    virtual bool is_elf() const;
    virtual bool is_rogue() const;
    virtual bool accept(const std::shared_ptr<NPC> attacker) = 0;

    virtual bool fight(std::shared_ptr<Bear> other) = 0;
    virtual bool fight(std::shared_ptr<Elf> other) = 0;
    virtual bool fight(std::shared_ptr<Rogue> other) = 0;
    virtual void print(std::ostream &os) = 0;

    virtual void save(std::ostream &os);

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};