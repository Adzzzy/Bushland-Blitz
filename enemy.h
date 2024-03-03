#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include "player.h"
#include "moves.h"

class player;
class moves;
class enemy;

// enemy class
class enemy {
public:
	enemy();

	int health;
	std::string effect; //for non-volatile effects, e.g. burn
	std::string effect2; //for volatile effects, e.g. sluggish
	bool alive;
	std::string name;

	void dropItem(player player1);
	virtual std::string attack(player *player1) =0; // declares the enemies move, polymorphed depending on enemy

    int getHealth();
    void setHealth(int e_health);
    std::string getEffect();

    void checkDeath();
	void destroyPointer(enemy *enemy);

	virtual ~enemy();
};

class green_snake : public enemy {
public:
	green_snake();
	virtual std::string attack(player *player1); // declares the enemies move, polymorphed depending on enemy

	~green_snake();
};

class echidna : public enemy {
public:
	echidna();
	std::string attack(player *player1); // declares the enemies move, polymorphed depending on enemy

	~echidna();
};

class spider : public enemy {
public:
	spider();
	std::string attack(player *player1); // declares the enemies move, polymorphed depending on enemy

	~spider();
};

class scorpion : public enemy {
public:
	scorpion();
	std::string attack(player *player1); // declares the enemies move, polymorphed depending on enemy

	~scorpion();
};

class kangaroo : public enemy {
public:
	kangaroo();
	std::string attack(player *player1); // declares the enemies move, polymorphed depending on enemy

	~kangaroo();
};

class koala : public enemy {
public:
	koala();
	std::string attack(player *player1); // declares the enemies move, polymorphed depending on enemy

	~koala();
};

class brown_snake : public enemy {
public:
	brown_snake();
	std::string attack(player *player1); // declares the enemies move, polymorphed depending on enemy

 	~brown_snake();
};

class blue_ringed_octopus : public enemy {
public:
	blue_ringed_octopus();
	std::string attack(player *player1); // declares the enemies move, polymorphed depending on enemy

	~blue_ringed_octopus();
};

class dingo : public enemy {
	public:
	dingo();
	std::string attack(player *player1); // declares the enemies move, polymorphed depending on enemy

	~dingo();
};

class crocodile : public enemy {
public:
	crocodile();
	bool charging;

	std::string attack(player *player1); // declares the enemies move, polymorphed depending on enemy

	~crocodile();
};

class wedge_tailed_eagle : public enemy {
public:
	wedge_tailed_eagle();
	bool charging;

	std::string attack(player *player1); // declares the enemies move, polymorphed depending on enemy

	~wedge_tailed_eagle();
};

class shark : public enemy {
public:
	shark();
	std::string attack(player *player1); // declares the enemies move, polymorphed depending on enemy

	~shark();
};


#endif