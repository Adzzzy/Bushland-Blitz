#include <iostream>
#include <string>
#include "player.h"
#include "enemy.h"
#include "moves.h"
#include "items.h"

class enemy;
class moves;
class player;
class items;

//default player constructor
player::player()
{
    max_health = 100;
    max_spirit = 50;
    health = 100;
    spirit = 50;
    name = "NULL";
    enemiesDefeated = 0;
    effect = "NULL";
    effect2 = "NULL";
    learnt_attacks = { new std::string[0] };
    learnt_spells = { new std::string[0] };
    gained_items = { new std::string[0] };

    attacks = 0;
    spells = 0;
    item = 0;
    attacks_capacity = 0;
    spells_capacity = 0;
    items_capacity = 0;

    player_turn = true; // player gets the first turn
    player_death = false;
}

// get player name
void player::getName(std::string p_name) {
    name = p_name;
}

// update health based on damage taken
void player::decreaseHealth(int damage) {
    // take damage from health if health is greater than damage
    if (health > damage) {
        health = health - damage;
    }
    // if health is less than damage, initiate death
    else if (health <= damage) {
        player_death = true;
    }
}

// increase health by specified amount, capped at max_health value
void player::increaseHealth(int health_regen) {
    if (health + health_regen <= max_health) {
        health = health + health_regen;
    }
    else if (health + health_regen > max_health) {
        health = max_health;
    }
}

// update spirit based on cost of spirit to perform action
void player::decreaseSpirit(int spirit_cost) {
        spirit = spirit - spirit_cost;
}

//increase spirit by specified amount, capped at max_spirit value
void player::increaseSpirit(int spirit_regen) {
    if (spirit + spirit_regen <= max_spirit) {
        spirit = spirit + spirit_regen;
    }
    else if (spirit + spirit_regen > max_spirit) {
        spirit = max_spirit;
    }
}

// update max health
void player::updateMaxHealth(int amount) {
    max_health = max_health + amount;
}

//update max spirit
void player::updateMaxSpirit(int amount) {
    max_spirit += amount;
}

void player::block(int damage, int turn_count) {
    // code here
}

std::string player::attack(moves pattack, enemy *badFellow){
	int acc = pattack.getAccuracy();
	int rNum = rand() % 100;

    if (pattack.effect == "WeakHeal") {
        increaseHealth(25);
        return "You used " + pattack.name + ", which healed you for 25 health";
    }
    else if (pattack.effect == "StrongHeal") {
        increaseHealth(50);
        return "You used " + pattack.name + ", which healed you for 50 health";
    }
    else if (pattack.effect == "FullHeal") {
        increaseHealth(max_health);
        return "You used " + pattack.name + ", fully restoring your health";
    }
    else if (pattack.effect == "Cleanse") {
        effect = "NULL";
        return "You used " + pattack.name + ", cleansing you of all ill effects";
    }
    else if (pattack.effect == "Burn") {
        badFellow->effect = "burn";
        int tempHealth = badFellow->getHealth();
    	tempHealth = tempHealth - pattack.damage;
    	badFellow->setHealth(tempHealth);
        return "You used " + pattack.name + ", dealing " + std::to_string(pattack.damage) + " damage and burning the " + badFellow->name + " for 10 damage every turn";
    }
    else if (pattack.effect == "Sluggish") {
        effect2 = "sluggish";
        int tempHealth = badFellow->getHealth();
    	tempHealth = tempHealth - pattack.damage;
    	badFellow->setHealth(tempHealth);
        return "You used " + pattack.name + ", dealing " + std::to_string(pattack.damage) + " damage";
    }

    else {
    	if (rNum < acc)
    	{
    		int tempHealth = badFellow->getHealth();
    		tempHealth = tempHealth - pattack.getDamage();
    		badFellow->setHealth(tempHealth);
    		return "You used " + pattack.name + ", which dealt " + std::to_string(pattack.damage) + " damage";
    	}
        else {
    		return "You tried using " + pattack.name + ", but it missed!";
    	}
    }
    
	return "Error - Player Attack";
}

void player::wait() {
    player_turn = false; // set the players turn to completed
}

// get current health
int player::getHealth() {
    return health;
}

// get current spirit
int player::getSpirit() {
    return spirit;
}

// get max health
int player::getMaxHealth() {
    return max_health;
}

// get max spirit
int player::getMaxSpirit() {
    return max_spirit;
}

// set health
void player::setHealth(int p_health) {
    health = p_health;
}

// set spirit
void player::setSpirit(int p_spirit) {
    spirit = p_spirit;
}

void player::learn_attack(std::string pattack) {
  std::string *temp;
  if (attacks >= attacks_capacity) {
    temp = new std::string[attacks_capacity + 1];
    for (int i=0; i<attacks_capacity; i++) {
      temp[i] = learnt_attacks[i];
    }
    attacks_capacity++;
    delete [] learnt_attacks;
    learnt_attacks = temp;
  }
  learnt_attacks[attacks] = pattack;
  attacks++;
}

void player::learn_spell(std::string pspell) {
  std::string *temp;
  if (spells >= spells_capacity) {
    temp = new std::string[spells_capacity + 1];
    for (int i=0; i<spells_capacity; i++) {
      temp[i] = learnt_spells[i];
    }
    spells_capacity++;
    delete [] learnt_spells;
    learnt_spells = temp;
  }
  learnt_spells[spells] = pspell;
  spells++;
}

void player::gain_item(std::string pitem) {
  std::string *temp;
  if (item >= items_capacity) {
    temp = new std::string[items_capacity + 1];
    for (int i=0; i<items_capacity; i++) {
      temp[i] = gained_items[i];
    }
    items_capacity++;
    delete [] gained_items;
    gained_items = temp;
  }
  gained_items[item] = pitem;
  item++;
}

void player::lose_item(std::string pitem) {
  std::string *temp;
  bool item_removed = false;
  int index = 0;
  if (item >= items_capacity) {
    temp = new std::string[items_capacity - 1];
    for (int i=0; i<items_capacity; i++) {
        if (item_removed || gained_items[i] != pitem) {
            temp[index] = gained_items[i];
            index++;
        }
        else {
            item_removed = true;
        }

    }
    items_capacity--;
    delete [] gained_items;
    gained_items = temp;
  }
  item--;
}

void player::getAttacks() {
    for (int i = 0; i < attacks; i++) {
        std::cout << learnt_attacks[i] << std::endl;
    }
}

void player::getSpells() {
    for (int i = 0; i < spells; i++) {
        std::cout << learnt_spells[i] << std::endl;
    }
}

void player::getItems() {
    for (int i = 0; i < item; i++) {
        std::cout << gained_items[i] << std::endl;
    }
}

std::string player::getAttack(int index) {
    return learnt_attacks[index];
}

std::string player::getSpell(int index) {
    return learnt_spells[index];
}

std::string player::getItem(int index) {
    return gained_items[index];
}

void player::checkDeath() {
    if (health < 1) {
        player_death = true;
    }
}

std::string player::use_item(items pitem) {
    if (pitem.name == "Yam") {increaseHealth(50); lose_item(pitem.name); return "You ate the Yam. It healed you for 50 health";}
    else if (pitem.name == "Brush Berry") {increaseSpirit(30); lose_item(pitem.name); return "You ate the Brush Berry. It restored your spirit by 30";}
    else if (pitem.name == "Bush Tomato") {updateMaxHealth(10); lose_item(pitem.name); return "You ate the Bush Tomato. Your max health increased by 10";}
    else if (pitem.name == "Desert Lime") {updateMaxSpirit(10); lose_item(pitem.name); return "You ate the Desert Lime. Your max spirit increased by 10";}
    else if (pitem.name == "Wild Orange") {effect = "NULL"; lose_item(pitem.name); return "You ate the Wild Orange. You were cured of any ailments";}
    else if (pitem.name == "Witchetty Grub") {increaseHealth(100); lose_item(pitem.name); return "You ate the Witchetty Grub. It healed you for 100 health";}

    return "Error - use_item";
}

player::~player() {
    delete[] learnt_attacks;
    delete[] learnt_spells;
    delete[] gained_items;
}