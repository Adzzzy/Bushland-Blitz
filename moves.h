#ifndef MOVES_H
#define MOVES_H

#include <iostream>

// moves class
class moves {
public:
	moves();
    moves(int accuracy, int damage, int spiritCost, std::string effect, std::string name);

	int accuracy;
    int damage;
    int spiritCost;
    std::string effect;
    std::string name;

    int getAccuracy();
    int getDamage();

	~moves();
};

#endif
