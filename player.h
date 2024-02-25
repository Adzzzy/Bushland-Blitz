#ifndef PLAYER_H
#define PLAYER_H

#include "moves.h"
#include "enemy.h"
#include "items.h"
#include <iostream>

class enemy;
class moves;
class player;
class items;

// player class
class player {
public:
	player();

    bool player_turn;
    bool player_death;

    int attacks; // number of attacks, spells and items
    int spells;
    int item;

    int attacks_capacity;
    int spells_capacity;
    int items_capacity;

    std::string *learnt_attacks; //dynamic array of attacks with two default values
    std::string *learnt_spells; //dynamic array of spells
    std::string *gained_items; // dynamic array of items

    void learn_attack(std::string pattack); // function for adding a new attack onto the array
    void learn_spell(std::string pspell);
    void gain_item(std::string pitem);

    void getAttacks(); //returns all the values in the array
    void getSpells();
    void getItems();

    std::string getAttack(int index); //returns a specific value in the array
    std::string getSpell(int index);
    std::string getItem(int index);

    std::string use_item(items pitem);
    void lose_item(std::string pitem);

	int max_health;
    int max_spirit;
    int health;
    int spirit;
    int health_regen;
    int spirit_regen;
    std::string name;
    int enemiesDefeated;
    std::string effect;

    void getName(std::string p_name);

    void increaseHealth(int health_regen);
    void decreaseHealth(int damage);
    void increaseSpirit(int spirit_regen);
    void decreaseSpirit(int spirit_cost);

    void updateMaxHealth(int amount);
    void updateMaxSpirit(int amount);

    int getHealth();
    int getSpirit();
    int getMaxHealth();
    int getMaxSpirit();

    void setHealth(int p_health);
    void setSpirit(int p_spirit);

    void checkDeath();

    std::string attack(moves pattack, enemy *badFellow);
    void block(int damage, int turn_count);
    void wait(); // possibly unneeded

    ~player();
};

#endif