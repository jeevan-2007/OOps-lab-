#include <iostream>
using namespace std;

class character {
    int id;
    string name;
    int level;
    int health;
public:
    character(int id, string name, int level, int health) {
        this->id = id;
        this->name = name;
        this->level = level;
        this->health = health;
    }
    virtual void attack() { cout << "Character attacked" << endl; }
    virtual void defend() { cout << "Character defended" << endl; }
    virtual void display() {
        cout << "ID: " << id << "\nName: " << name << "\nLevel: " << level << "\nHealth: " << health << endl;
    }
    virtual ~character() {}
};

class warrior : public character {
    int armorstrength, mele_damage;
public:
    warrior(int id, string name, int level, int health, int armorstrength, int mele_damage)
        : character(id, name, level, health), armorstrength(armorstrength), mele_damage(mele_damage) {}
    void attack() { cout << "Warrior attacked with melee damage: " << mele_damage << endl; }
};

class mage : public character {
    int spellpower, mana;
public:
    mage(int id, string name, int level, int health, int spellpower, int mana)
        : character(id, name, level, health), spellpower(spellpower), mana(mana) {}
    void defend() { cout << "Mage defended with spell power: " << spellpower << " and mana: " << mana << endl; }
};

class archer : public character {
    int arrow_count, range_accuracy;
public:
    archer(int id, string name, int level, int health, int arrow_count, int range_accuracy)
        : character(id, name, level, health), arrow_count(arrow_count), range_accuracy(range_accuracy) {}
    void defend() { cout << "Archer defended with long-range combat arrows" << endl; }
};

class rogue : public character {
    int stealth_level, agility;
public:
    rogue(int id, string name, int level, int health, int stealth_level, int agility)
        : character(id, name, level, health), stealth_level(stealth_level), agility(agility) {}
    void display() {
        character::display();
        cout << "Stealth Level: " << stealth_level << "\nAgility: " << agility << endl;
    }
};

int main() {
    character *c1 = new warrior(1, "Warrior", 1, 100, 50, 20);
    character *c2 = new mage(2, "Mage", 1, 100, 50, 20);
    character *c3 = new archer(3, "Archer", 1, 100, 50, 20);
    character *c4 = new rogue(4, "Rogue", 1, 100, 50, 20);
    
    c1->attack();
    c2->defend();
    c3->defend();
    c4->display();

    delete c1;
    delete c2;
    delete c3;
    delete c4;
    return 0;
}
