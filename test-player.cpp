#include <iostream>
#include "player.h"

int main() {
    player player;

    player.learn_attack("Club");
    player.learn_attack("Boomerang");

    player.learn_attack("Spear Hurl");
    player.learn_attack("Spear Hurl");
    player.learn_attack("Spear Hurl");
    player.learn_attack("Spear Hurl");

    for (int i=0; i < player.attacks; i++) {
        std::cout <<player.getAttack(i)<<std::endl;
    }

    return 0;
}