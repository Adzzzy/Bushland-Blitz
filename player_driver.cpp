#include <iostream>
#include "player.h"
#include "moves.h"
#include "enemy.h"
#include "items.h"

int main(void) {
    // create player object
    player one;

// testing increaseHealth function
int x;
int y;
std::string a;
std::string b;

// x = 0;
one.health = 50; // for accurate testing change health to 50
std::cin >> x;
one.increaseHealth(x);
std::cout << one.health << std::endl;

// x = 51
one.health = 50;
std::cin >> x;
one.increaseHealth(x);
std::cout << one.health << std::endl;

// x = 50
one.health = 50;
std::cin >> x;
one.increaseHealth(x);
std::cout << one.health << std::endl;

// x = 49
one.health = 50;
std::cin >> x;
one.increaseHealth(x);
std::cout << one.health << std::endl;


//increaseSpirit function
// x = 0, 25, 26, 24
for (int i = 0; i < 4; i++) {
    one.spirit = 25;
    std::cin >> x;
    one.increaseSpirit(x);
    std::cout << one.spirit << std::endl;
}


//getHealth and setHealth functions
std::cin >> x;
one.setHealth(x);
std::cout << one.getHealth() << std::endl;

//getSpirit and setHealth functions
std::cin >> x;
one.setSpirit(x);
std::cout << one.getSpirit() << std::endl;

// learn_attack function
std::cin >> a;
std::cin >> b;
one.learn_attack(a);
one.learn_attack(b);
for (int i = 0; i < one.attacks; i++) {
    std::cout << one.learnt_attacks[i] << std::endl;
}

//getAttacks function
one.getAttacks();

//getAttack function
std::cin >> x;
one.getAttack(x);

// learn_spell function
std::cin >> a;
std:: cin >> b;
one.learn_spell(a);
one.learn_spell(b);
for (int i = 0; i < one.spells; i++) {
    std::cout << one.learnt_spells[i] << std::endl;
}

// getSpells function
one.getSpells();

//getSpell function
std::cin >> x;
one.getSpell(x);

// gain_item function
std::cin >> a;
std:: cin >> b;
one.gain_item(a);
one.gain_item("Kangaroo tail");
for (int i = 0; i < one.item; i++) {
    std::cout << one.gained_items[i] << std::endl;
}

// getItems function
one.getItems();

//getItem function
std::cin >> x;
one.getItem(x);


// lose_item function
one.lose_item("Kangaroo tail")
    return 0;
};