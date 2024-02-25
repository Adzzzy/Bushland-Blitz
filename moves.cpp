#include <iostream>
#include "moves.h"

// generic move functions
moves::moves() {
	int accuracy = 100;
    int damage = 0;
    int spiritCost = 0;
    std::string name = "NULL";
}

moves::moves(int accuracy, int damage, int spiritCost, std::string effect, std::string name) {
    this->accuracy = accuracy;
    this->damage = damage;
    this->spiritCost = spiritCost;
    this->effect = effect;
    this->name = name;
}

int moves::getAccuracy() {
    return accuracy;
}

int moves::getDamage() {
    return damage;
}

moves::~moves() {

}
