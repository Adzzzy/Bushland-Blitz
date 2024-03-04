#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "enemy.h"
#include "player.h"
#include "moves.h"

// generic enemy functions
enemy::enemy() {
	int health = 100;
	name = "NULL";
	std::string effect = "NULL";
	std::string effect2 = "NULL";
	bool alive = true;

}

// get health
int enemy::getHealth() {
	return health;
}

// set health
void enemy::setHealth(int e_health) {
	health = e_health;
}

std::string enemy::getEffect() {
	return effect;
}

void enemy::checkDeath() {
	if (health < 1) {
		alive = false;
	}
}

enemy::~enemy() {

}

// green snake
green_snake::green_snake() {
	health = 60;
	name = "Green Snake";
}

std::string green_snake::attack(player *player1) {
	int rNum = rand() % 101;
	int rNum2 = rand() % 3;
	int damage = 0;
	float multiplier = float(player1->enemiesDefeated) / 10 + 1;
	switch (rNum2) {
		case 0:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				//if player is blocking, different damage calculation and message
				if (player1->block == true) {
					damage = 10 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Green Snake used Chomp, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 10 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Green Snake used Chomp, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Green Snake tried using Chomp, but it missed!";
			}
			break;
		case 1:
			if (rNum < 90)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 15 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Green Snake used Strangle, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 15 * multiplier;
				player1->setHealth(tempHealth - damage);
				return "Green Snake used Strangle, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Green Snake tried using Strangle, but it missed!";
			}
			break;
		case 2:
			if (rNum < 70)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 25 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Green Snake used Slithery Slap, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 25 * multiplier;
				player1->setHealth(tempHealth - damage);
				return "Green Snake used Slithery Slap, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Green Snake tried using Slithery Slap, but it missed!";
			}
			break;
	}
	return "Error Failed Attack";
}

green_snake::~green_snake() {}

// echidna
echidna::echidna() {
	health = 70;
	name = "Echidna";
}

std::string echidna::attack(player *player1) {
	int rNum = rand() % 101;
	int rNum2 = rand() % 3;
	int damage = 0;
	float multiplier = float(player1->enemiesDefeated) / 10 + 1;
	switch (rNum2) {
		case 0:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 10 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Echidna used Quillshot, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 10 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Echidna used Quillshot, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Echidna tried using Quillshot, but it missed!";
			}
			break;
		case 1:
			if (rNum < 80)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 20 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Echidna used Spike, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 20 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Echidna used Spike, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Echidna tried using Spike, but it missed!";
			}
			break;
		case 2:
			if (rNum < 35)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 40 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Echidna used Spiny Charge, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 40 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Echidna used Spiny Charge, dealing a massive " + std::to_string(damage) + " damage";
			}
			else {
				return "Echidna tried using Spiny Charge, but it missed!";
			}
			break;
	}
	return "Error Failed Attack";
}

echidna::~echidna() {

}

// spider
spider::spider() {
	health = 50;
	name = "Spider";
}

std::string spider::attack(player *player1) {
    int rNum = rand() % 101;
	int rNum2 = rand() % 3;
	int damage = 0;
	float multiplier = float(player1->enemiesDefeated) / 10 + 1;
	switch (rNum2) {
		case 0:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 25 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Spider used Web Shot, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 25 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Spider used Web Shot, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Spider tried using Web Shot, but it missed!";
			}
			break;
		case 1:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 15 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Spider used Crazy Crawl, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 15 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Spider used Crazy Crawl, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Spider tried using Crazy Crawl, but it missed!";
			}
			break;
		case 2:
			if (rNum < 100)	{
				if (player1->effect == "NULL") {
					if (player1->ailmentShield == true) {
						player1->ailmentShield = false;
						return "Spider used Poison Bite. Your ailment shield protects you from getting poisoned and disappears";
					}
					player1->effect = "poison";
					return "Spider used Poison Bite, which deals no damage but poisons you, dealing damage each turn";
				}
				else {
					int tempHealth = player1->getHealth();
					if (player1->block == true) {
						damage = 25 * multiplier * player1->blockReduction;
						player1->setHealth(tempHealth-damage);
						return "Spider used Web Shot, dealing a reduced " + std::to_string(damage) + " damage";
					}
					damage = 25 * multiplier;
					player1->setHealth(tempHealth-damage);
					return "Spider used Web Shot, dealing " + std::to_string(damage) + " damage";
				}
			}
			else {
				return "Spider tried using Poison Bite, but it missed!";
			}
			break;
	}
	return "Error Failed Attack";
}

spider::~spider() {

}

// scorpion
scorpion::scorpion() {
	health = 60;
	name = "Scorpion";
}

std::string scorpion::attack(player *player1) {
    int rNum = rand() % 101;
	int rNum2 = rand() % 3;
	int damage = 0;
	float multiplier = float(player1->enemiesDefeated) / 10 + 1;
	switch (rNum2) {
		case 0:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 15 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Scorpion used Pincer Pinch, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 15 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Scorpion used Pincer Pinch, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Scorpion tried using Pincer Pinch, but it missed!";
			}
			break;
		case 1:
			if (rNum < 80)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 25 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Scorpion used Sting, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 25 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Scorpion used Sting, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Scorpion tried using Sting, but it missed!";
			}
			break;
		case 2:
			if (rNum < 100)	{
				if (player1->effect == "NULL") {
					if (player1->ailmentShield == true) {
						player1->ailmentShield = false;
						return "Scorpion used Poison Skewer. Your ailment shield protects you from getting poisoned and disappears";
					}
					player1->effect = "poison";
					return "Scorpion used Poison Skewer, which deals no damage but poisons you, dealing damage each turn";
				}
				else {
					int tempHealth = player1->getHealth();
					if (player1->block == true) {
						damage = 15 * multiplier * player1->blockReduction;
						player1->setHealth(tempHealth-damage);
						return "Scorpion used Pincer Pinch, dealing a reduced " + std::to_string(damage) + " damage";
					}
					damage = 15 * multiplier;
					player1->setHealth(tempHealth-damage);
					return "Scorpion used Pincer Pinch, dealing " + std::to_string(damage) + " damage";
				}
			}
			else {
				return "Scorpion tried using Poison Skewer, but it missed!";
			}
			break;
	}
	return "Error Failed Attack";
}

scorpion::~scorpion() {

}

// kangaroo
kangaroo::kangaroo() {
	health = 100;
	name = "Kangaroo";
}

std::string kangaroo::attack(player *player1) {
    int rNum = rand() % 101;
	int rNum2 = rand() % 3;
	int damage = 0;
	float multiplier = float(player1->enemiesDefeated) / 10 + 1;
	switch (rNum2) {
		case 0:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 10 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Kangaroo used Kick, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 10 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Kangaroo used Kick, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Kangaroo tried using Kick, but it missed!";
			}
			break;
		case 1:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 15 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Kangaroo used Punch, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 15 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Kangaroo used Punch, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Kangaroo tried using Punch, but it missed!";
			}
			break;
		case 2:
			if (rNum < 80)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 20 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Kangaroo used Tail Slam, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 20 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Kangaroo used Tail Slam, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Kangaroo tried using Tail Slam, but it missed!";
			}
			break;
	}
	return "Error Failed Attack";
}

kangaroo::~kangaroo() {

}

// koala
koala::koala() {
	health = 80;
	name = "Koala";
}

std::string koala::attack(player *player1) {
    int rNum = rand() % 101;
	int rNum2 = rand() % 3;
	int damage = 0;
	int heal = 0;
	float multiplier = float(player1->enemiesDefeated) / 10 + 1;
	switch (rNum2) {
		case 0:
			if (rNum < 100)	{
				if (health <= 30) {
					heal = 10 * multiplier;
					health = health + heal;
					return "Koala went to Sleep, healing itself for " + std::to_string(heal) + " health";
				}
				else {
					int tempHealth = player1->getHealth();
					if (player1->block == true) {
						damage = 10 * multiplier * player1->blockReduction;
						player1->setHealth(tempHealth-damage);
						return "Koala used Claw Swipe, dealing a reduced " + std::to_string(damage) + " damage";
					}
					damage = 10 * multiplier;
					player1->setHealth(tempHealth-damage);
					return "Koala used Claw Swipe, dealing " + std::to_string(damage) + " damage";
				}
			}
			else {
				return "Koala tried going to Sleep, but it failed!";
			}
			break;
		case 1:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 10 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Koala used Claw Swipe, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 10 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Koala used Claw Swipe, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Koala tried using Claw Swipe, but it missed!";
			}
			break;
		case 2:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 20 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Koala used Bear Hug, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 20 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Koala used Bear Hug, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Koala tried using Bear Hug, but it missed!";
			}
			break;
	}
	return "Error Failed Attack";
}

koala::~koala() {

}

// brown_snake
brown_snake::brown_snake() {
	health = 100;
	name = "Brown Snake";
}

std::string brown_snake::attack(player *player1) {
	int rNum = rand() % 101;
	int rNum2 = rand() % 3;
	int damage = 0;
	float multiplier = float(player1->enemiesDefeated+1) / 10 + 1; //wave enemies defeated would be 9 by the time wave 2 starts so add 1 for a clean 2 times multiplier
	switch (rNum2) {
		case 0:
			if (player1->effect != "poison") {
				if (rNum < 80)	{
					int tempHealth = player1->getHealth();
					if (player1->block == true) {
						damage = 20 * multiplier * player1->blockReduction;
						player1->setHealth(tempHealth-damage);
						//if player has ailment shield, protect from poison
						if (player1->ailmentShield == true) {
							player1->ailmentShield = false;
							return "Brown Snake used Lethal Lunge, dealing a reduced " + std::to_string(damage) + ". Your ailment shield protects you from getting poisoned and disappears";
						}
						player1->effect = "poison";
						return "Brown Snake used Lethal Lunge, dealing a reduced " + std::to_string(damage) + " damage and leaving you poisoned";
					}
					damage = 20 * multiplier;
					player1->setHealth(tempHealth-damage);
					//if player has ailment shield, protect from poison
					if (player1->ailmentShield == true) {
						player1->ailmentShield = false;
						return "Brown Snake used Lethal Lunge, dealing " + std::to_string(damage) + ". Your ailment shield protects you from getting poisoned and disappears";
					}
					player1->effect = "poison";
					return "Brown Snake used Lethal Lunge, dealing " + std::to_string(damage) + " damage and leaving you poisoned";
				}
				else {
					return "Brown Snake tried using Lethal Lunge, but it missed!";
				}
			}
			else {
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 10 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Brown Snake used Chomp, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 10 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Brown Snake used Chomp, dealing " + std::to_string(damage) + " damage";
			}
			break;
		case 1:
			if (rNum < 90)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 15 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Brown Snake used Strangle, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 15 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Brown Snake used Strangle, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Brown Snake tried using Strangle, but it missed!";
			}
			break;
		case 2:
			if (rNum < 70)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 25 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Brown Snake used Slithery Slap, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 25 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Brown Snake used Slithery Slap, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Brown Snake tried using Slithery Slap, but it missed!";
			}
			break;
	}
	return "Error Failed Attack";
}

brown_snake::~brown_snake() {

}

//blue_ringed_octopus
blue_ringed_octopus::blue_ringed_octopus() {
	health = 80;
	name = "Blue-ringed Octopus";
}

std::string blue_ringed_octopus::attack(player *player1) {
	int rNum = rand() % 101;
	int rNum2 = rand() % 3;
	int damage = 0;
	float multiplier = float(player1->enemiesDefeated+1) / 10 + 1; //wave enemies defeated would be 9 by the time wave 2 starts so add 1 for a clean 2 times multiplier

	switch (rNum2) {
		case 0:
			if (player1->effect2 != "sluggish") {
				if (rNum < 70)	{
					int tempHealth = player1->getHealth();
					if (player1->block == true) {
						damage = 20 * multiplier * player1->blockReduction;
						player1->setHealth(tempHealth-damage);
						if (player1->ailmentShield == true) {
							player1->ailmentShield = false;
							return "Blue-ringed Octopus used Paralyzing Hold, dealing a reduced " + std::to_string(damage) + ". Your ailment shield protects you from getting trapped and disappears";
						}
						player1->effect2 = "sluggish";
						return "Blue-ringed Octopus used Paralyzing Hold, dealing a reduced " + std::to_string(damage) + " damage and leaving you unable to move";
					}
					damage = 20 * multiplier;
					player1->setHealth(tempHealth-damage);
					if (player1->ailmentShield == true) {
						player1->ailmentShield = false;
						return "Blue-ringed Octopus used Paralyzing Hold, dealing " + std::to_string(damage) + ". Your ailment shield protects you from getting trapped and disappears";
					}
					player1->effect2 = "sluggish";
					return "Blue-ringed Octopus used Paralyzing Hold, dealing " + std::to_string(damage) + " damage and leaving you unable to move";
				}
				else {
					return "Blue-ringed Octopus tried using Paralyzing Hold, but it missed!";
				}
			}
			else {
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 10 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Blue-ringed Octopus used Wacky Wrap, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 10 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Blue-ringed Octopus used Wacky Wrap, dealing " + std::to_string(damage) + " damage";
			}
			break;
		case 1:
			if (rNum < 80) {
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 10 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					if (player1->ailmentShield == true) {
						player1->ailmentShield = false;
						return "Blue-ringed Octopus used Poisonous Peck, dealing a reduced " + std::to_string(damage) + ". Your ailment shield protects you from getting poisoned and disappears";
					}
					player1->effect = "poison";
					return "Blue-ringed Octopus used Poisonous Peck, dealing a reduced " + std::to_string(damage) + " damage and poisoning you";
				}
				damage = 10 * multiplier;
				player1->setHealth(tempHealth-damage);
				if (player1->ailmentShield == true) {
					player1->ailmentShield = false;
					return "Blue-ringed Octopus used Poisonous Peck, dealing " + std::to_string(damage) + ". Your ailment shield protects you from getting poisoned and disappears";
				}
				player1->effect = "poison";
				return "Blue-ringed Octopus used Poisonous Peck, dealing " + std::to_string(damage) + " damage and poisoning you";
			}
			else {
				return "Blue-ringed Octopus tried using Poisonous Peck, but it missed!";
			}
			break;
		case 2:
			if (rNum < 90) {
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 20 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Blue-ringed Octopus used Savage Suction, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 20 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Blue-ringed Octopus used Savage Suction, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Blue-ringed Octopus tried using Savage Suction, but it missed!";
			}
			break;
	}
	return "Error Failed Attack";
}

blue_ringed_octopus::~blue_ringed_octopus() {

}

// dingo
dingo::dingo() {
	health = 100;
	name = "Dingo";
}

//dingo will always attack twice
std::string dingo::attack(player *player1) {
	int rNum = rand() % 101;
	int rNum2 = rand() % 3;
	int damage = 0;
	int heal = 0;
	float multiplier = float(player1->enemiesDefeated+1) / 10 + 1; //wave enemies defeated would be 9 by the time wave 2 starts so add 1 for a clean 2 times multiplier
	switch (rNum2) {
		case 0:
			if (rNum < 100)	{
				if (health <= 50) {
					heal = 5 * multiplier;
					health = health + heal;
					return "Dingo used Wound Lick, healing itself for " + std::to_string(heal) + " health";
				}
				else {
					int tempHealth = player1->getHealth();
					if (player1->block == true) {
						damage = 10 * multiplier * player1->blockReduction;
						player1->setHealth(tempHealth-damage);
						return "Dingo used Chomp, dealing a reduced " + std::to_string(damage) + " damage";
					}
					damage = 10 * multiplier;
					player1->setHealth(tempHealth-damage);
					return "Dingo used Chomp, dealing " + std::to_string(damage) + " damage";
				}
			}
			else {
				return "Dingo tried licking its wounds, but it failed!";
			}
			break;
		case 1:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 10 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Dingo used Chomp, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 10 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Dingo used Chomp, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Dingo tried using Chomp, but it missed!";
			}
			break;
		case 2:
			if (rNum < 80)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 15 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Dingo used Dog Dive, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 15 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Dingo used Dog Dive, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Dingo tried using Dog Dive, but it missed!";
			}
			break;
	}
	return "Error Failed Attack";
}

dingo::~dingo() {

}

// crocodile
crocodile::crocodile() {
	health = 130;
	name = "Crocodile";
	charging = false;
}

std::string crocodile::attack(player *player1) {
	int rNum = rand() % 101;
	int rNum2 = rand() % 3;
	int damage = 0;
	float multiplier = float(player1->enemiesDefeated+1) / 10 + 1; //wave enemies defeated would be 9 by the time wave 2 starts so add 1 for a clean 2 times multiplier

	if (charging == true) {
		charging = false;
		if (rNum < 80) {
			int tempHealth = player1->getHealth();
			if (player1->block == true) {
				damage = 40 * multiplier * player1->blockReduction;
				player1->setHealth(tempHealth-damage);
				return "Crocodile surges forward, slamming you to the ground. You manage to block some of its bites, sustaining " + std::to_string(damage) + " damage";
			}
			damage = 40 * multiplier;
			player1->setHealth(tempHealth-damage);
			return "Crocodile surges forward, slamming you to the ground and tearing into you with its teeth, dealing a colossal  " + std::to_string(damage) + " damage";
			}
		else {
			return "Crocodile surges forward, missing you by a fraction";
		}
	}

	switch (rNum2) {
		case 0:
			if (rNum < 100) {
				charging = true;
				return "Crocodile anchors itself, preparing to lunge";
			}
			else {
				return "Crocodile sits motionless, eyeing you";
			}
			break;
		case 1:
			if (player1->effect2 != "sluggish") {
				if (rNum < 70)	{
					int tempHealth = player1->getHealth();
					if (player1->block == true) {
						damage = 20 * multiplier * player1->blockReduction;
						player1->setHealth(tempHealth-damage);
						if (player1->ailmentShield == true) {
							player1->ailmentShield = false;
							return "Crocodile used Death Roll, dealing a reduced " + std::to_string(damage) + ". Your ailment shield protects you from getting trapped and disappears";
						}
						player1->effect2 = "sluggish";
						return "Crocodile grabbed you in a death roll, dealing a reduced " + std::to_string(damage) + " damage";
					}
					damage = 20 * multiplier;
					player1->setHealth(tempHealth-damage);
					if (player1->ailmentShield == true) {
						player1->ailmentShield = false;
						return "Crocodile used Death Roll, dealing " + std::to_string(damage) + ". Your ailment shield protects you from getting trapped and disappears";
					}
					player1->effect2 = "sluggish";
					return "Crocodile grabbed you in a death roll, dealing " + std::to_string(damage) + " damage";
				}
				else {
					return "Crocodile tried using Death Roll, but it missed!";
				}
			}
			else {
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 15 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Crocodile used Croc Crunch, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 15 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Crocodile used Croc Crunch, dealing " + std::to_string(damage) + " damage";
			}
			break;
		case 2:
			if (rNum < 100) {
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 15 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Crocodile used Croc Crunch, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 15 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Crocodile used Croc Crunch, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Crocodile tried using Croc Crunch, but it missed!";
			}
			break;
	}
	return "Error Failed Attack";
}

crocodile::~crocodile() {

}

// wedge_tailed_eagle
wedge_tailed_eagle::wedge_tailed_eagle() {
	health = 100;
	name = "Wedge-tailed Eagle";
	charging = false;
}

std::string wedge_tailed_eagle::attack(player *player1) {
	int rNum = rand() % 101;
	int rNum2 = rand() % 3;
	int damage = 0;
	float multiplier = float(player1->enemiesDefeated+1) / 10 + 1; //wave enemies defeated would be 9 by the time wave 2 starts so add 1 for a clean 2 times multiplier

	if (charging == true) {
		charging = false;
		if (rNum < 70) {
			int tempHealth = player1->getHealth();
			if (player1->block == true) {
				damage = 40 * multiplier * player1->blockReduction;
				player1->setHealth(tempHealth-damage);
				return "Wedge-tailed Eagle used Sky Dive, plummeting down onto you. You manage to block part of the attack, sustaining " + std::to_string(damage) + " damage";
			}
			damage = 40 * multiplier;
			player1->setHealth(tempHealth-damage);
			return "Wedge-tailed Eagle used Sky Dive, plummeting down onto you and dealing a monstrous " + std::to_string(damage) + " damage";
			}
		else {
			setHealth(health-10);
			return "Wedge-tailed Eagle used Sky Dive, but narrowly misses you, barrelling into the ground. It takes 10 damage.";
		}
	}

	switch (rNum2) {
		case 0:
			if (rNum < 100) {
				charging = true;
				return "Wedge-Tailed Eagle flies high, lining you up in its sights";
			}
			else {
				return "Wedge-Tailed Eagle pecks at the ground";
			}
			break;
		case 1:
			if (rNum < 80)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 20 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Wedge-Tailed Eagle used Talon Swipe, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 20 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Wedge-Tailed Eagle used Talon Swipe, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Wedge-Tailed Eagle tried using Talon Swipe, but it missed!";
			}
			break;
		case 2:
			if (rNum < 100) {
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 10 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Wedge-tailed Eagle used Wing Whack, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 10 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Wedge-tailed Eagle used Wing Whack, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Wedge-tailed Eagle tried using Wing Whack, but it missed!";
			}
			break;
	}
	return "Error Failed Attack";
}

wedge_tailed_eagle::~wedge_tailed_eagle() {

}

// shark
shark::shark() {
	health = 120;
	name = "Shark";
}

std::string shark::attack(player *player1) {
	int rNum = rand() % 101;
	int rNum2 = rand() % 3;
	int damage = 0;
	float multiplier = float(player1->enemiesDefeated+1) / 10 + 1; //wave enemies defeated would be 9 by the time wave 2 starts so add 1 for a clean 2 times multiplier
	switch (rNum2) {
		case 0:
			if (effect2 != "swift") {
				if (rNum < 80)	{
					int tempHealth = player1->getHealth();
					if (player1->block == true) {
						damage = 10 * multiplier * player1->blockReduction;
						player1->setHealth(tempHealth-damage);
						effect2 = "swift";
						return "Shark used Rapid Rush, dealing a reduced " + std::to_string(damage) + " damage and seizing the opportunity for another attack";
					}
					damage = 10 * multiplier;
					player1->setHealth(tempHealth-damage);
					effect2 = "swift";
					return "Shark used Rapid Rush, dealing " + std::to_string(damage) + " damage and seizing the opportunity for another attack";
				}
				else {
					return "Shark tried using Rapid Rush, but it missed!";
				}
			}
			else {
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 10 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Shark used Fin Smack, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 10 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Shark used Fin Smack, dealing " + std::to_string(damage) + " damage";
			}
			break;
		case 1:
			if (rNum < 80)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 15 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Shark used Cutting Crunch, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 15 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Shark used Cutting Crunch, dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Shark tried using Cutting Crunch, but it missed!";
			}
			break;
		case 2:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				if (player1->block == true) {
					damage = 10 * multiplier * player1->blockReduction;
					player1->setHealth(tempHealth-damage);
					return "Shark used Fin Smack, dealing a reduced " + std::to_string(damage) + " damage";
				}
				damage = 10 * multiplier;
				player1->setHealth(tempHealth-damage);
				return "Shark used Fin Smack dealing " + std::to_string(damage) + " damage";
			}
			else {
				return "Shark tried using Fin Smack, but it missed!";
			}
			break;
	}
	return "Error Failed Attack";
}

shark::~shark() {

}

//rainbow_serpent
rainbow_serpent::rainbow_serpent() {
	health = 200;
	name = "Rainbow Serpent";
}

std::string rainbow_serpent::attack(player *player1) {
	//serpent strike

	return "Error Failed Attack";
}

rainbow_serpent::~rainbow_serpent() {

}