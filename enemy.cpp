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
	float multiplier = float(player1->enemiesDefeated) / 10 + 1;
	switch (rNum2) {
		case 0:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 10 * multiplier;
				player1->setHealth(tempHealth);
				return "Green Snake used Chomp, dealing " + std::to_string(int(10 * multiplier)) + " damage";
			}
			else {
				return "Green Snake tried using Chomp, but it missed!";
			}
			break;
		case 1:
			if (rNum < 90)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 15 * multiplier;
				player1->setHealth(tempHealth);
				return "Green Snake used Strangle, dealing " + std::to_string(int(15 * multiplier)) + " damage";
			}
			else {
				return "Green Snake tried using Strangle, but it missed!";
			}
			break;
		case 2:
			if (rNum < 70)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 25 * multiplier;
				player1->setHealth(tempHealth);
				return "Green Snake used Slithery Slap, dealing " + std::to_string(int(25 * multiplier)) + " damage";
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
	float multiplier = float(player1->enemiesDefeated) / 10 + 1;
	switch (rNum2) {
		case 0:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 10 * multiplier;
				player1->setHealth(tempHealth);
				return "Echidna used Quillshot, dealing " + std::to_string(int(10 * multiplier)) + " damage";
			}
			else {
				return "Echidna tried using Quillshot, but it missed!";
			}
			break;
		case 1:
			if (rNum < 80)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 20 * multiplier;
				player1->setHealth(tempHealth);
				return "Echidna used Spike, dealing " + std::to_string(int(20 * multiplier)) + " damage";
			}
			else {
				return "Echidna tried using Spike, but it missed!";
			}
			break;
		case 2:
			if (rNum < 35)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 40 * multiplier;
				player1->setHealth(tempHealth);
				return "Echidna used Spiny Charge, dealing a massive " + std::to_string(int(40 * multiplier)) + " damage";
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
	float multiplier = float(player1->enemiesDefeated) / 10 + 1;
	switch (rNum2) {
		case 0:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 25 * multiplier;
				player1->setHealth(tempHealth);
				return "Spider used Web Shot, dealing " + std::to_string(int(25 * multiplier)) + " damage";
			}
			else {
				return "Spider tried using Web Shot, but it missed!";
			}
			break;
		case 1:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 15 * multiplier;
				player1->setHealth(tempHealth);
				return "Spider used Crazy Crawl, dealing " + std::to_string(int(15 * multiplier)) + " damage";
			}
			else {
				return "Spider tried using Crazy Crawl, but it missed!";
			}
			break;
		case 2:
			if (rNum < 100)	{
				if (player1->effect == "NULL") {
					player1->effect = "poison";
					return "Spider used Poison Bite, which deals no damage but poisons you, dealing damage each turn";
				}
				else {
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 25 * multiplier;
				player1->setHealth(tempHealth);
				return "Spider used Web Shot, dealing " + std::to_string(int(25 * multiplier)) + " damage";
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
	float multiplier = float(player1->enemiesDefeated) / 10 + 1;
	switch (rNum2) {
		case 0:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 15 * multiplier;
				player1->setHealth(tempHealth);
				return "Scorpion used Pincer Pinch, dealing " + std::to_string(int(15 * multiplier)) + " damage";
			}
			else {
				return "Scorpion tried using Pincer Pinch, but it missed!";
			}
			break;
		case 1:
			if (rNum < 80)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 25 * multiplier;
				player1->setHealth(tempHealth);
				return "Scorpion used Sting, dealing " + std::to_string(int(25 * multiplier)) + " damage";
			}
			else {
				return "Scorpion tried using Sting, but it missed!";
			}
			break;
		case 2:
			if (rNum < 100)	{
				if (player1->effect == "NULL") {
					player1->effect = "poison";
					return "Scorpion used Poison Skewer, which deals no damage but poisons you, dealing damage each turn";
				}
				else {
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 15 * multiplier;
				player1->setHealth(tempHealth);
				return "Scorpion used Pincer Pinch, dealing " + std::to_string(int(15 * multiplier)) + " damage";
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
	float multiplier = float(player1->enemiesDefeated) / 10 + 1;
	switch (rNum2) {
		case 0:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 10 * multiplier;
				player1->setHealth(tempHealth);
				return "Kangaroo used Kick, dealing " + std::to_string(int(10 * multiplier)) + " damage";
			}
			else {
				return "Kangaroo tried using Kick, but it missed!";
			}
			break;
		case 1:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 15 * multiplier;
				player1->setHealth(tempHealth);
				return "Kangaroo used Punch, dealing " + std::to_string(int(15 * multiplier)) + " damage";
			}
			else {
				return "Kangaroo tried using Punch, but it missed!";
			}
			break;
		case 2:
			if (rNum < 90)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 20 * multiplier;
				player1->setHealth(tempHealth);
				return "Kangaroo used Tail Slam, dealing " + std::to_string(int(20 * multiplier)) + " damage";
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
	float multiplier = float(player1->enemiesDefeated) / 10 + 1;
	switch (rNum2) {
		case 0:
			if (rNum < 100)	{
				if (health <= 20) {
					health = health + 10 * multiplier;
					return "Koala went to Sleep, healing itself for " + std::to_string(int(10 * multiplier)) + " health";
				}
				else {
					int tempHealth = player1->getHealth();
					tempHealth = tempHealth - 10 * multiplier;
					player1->setHealth(tempHealth);
					return "Koala used Claw Swipe, dealing " + std::to_string(int(10 * multiplier)) + " damage";
				}
			}
			else {
				return "Koala tried going to Sleep, but it failed!";
			}
			break;
		case 1:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 10 * multiplier;
				player1->setHealth(tempHealth);
				return "Koala used Claw Swipe, dealing " + std::to_string(int(10 * multiplier)) + " damage";
			}
			else {
				return "Koala tried using Claw Swipe, but it missed!";
			}
			break;
		case 2:
			if (rNum < 100)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 20 * multiplier;
				player1->setHealth(tempHealth);
				return "Koala used Bear Hug, dealing " + std::to_string(int(20 * multiplier)) + " damage";
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
	float multiplier = float(player1->enemiesDefeated+1) / 10 + 1; //wave enemies defeated would be 9 by the time wave 2 starts so add 1 for a clean 2 times multiplier
	switch (rNum2) {
		case 0:
			if (player1->effect != "poison") {
				if (rNum < 80)	{
					int tempHealth = player1->getHealth();
					tempHealth = tempHealth - 20 * multiplier;
					player1->setHealth(tempHealth);
					player1->effect = "poison";
					return "Brown Snake used Lethal Lunge, dealing " + std::to_string(int(20 * multiplier)) + " damage and leaving you poisoned";
				}
				else {
					return "Brown Snake tried using Lethal Lunge, but it missed!";
				}
			}
			else {
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 10 * multiplier;
				player1->setHealth(tempHealth);
				return "Brown Snake used Chomp, dealing " + std::to_string(int(10 * multiplier)) + " damage";
			}
			break;
		case 1:
			if (rNum < 90)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 15 * multiplier;
				player1->setHealth(tempHealth);
				return "Brown Snake used Strangle, dealing " + std::to_string(int(15 * multiplier)) + " damage";
			}
			else {
				return "Brown Snake tried using Strangle, but it missed!";
			}
			break;
		case 2:
			if (rNum < 70)	{
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 25 * multiplier;
				player1->setHealth(tempHealth);
				return "Brown Snake used Slithery Slap, dealing " + std::to_string(int(25 * multiplier)) + " damage";
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
	float multiplier = float(player1->enemiesDefeated+1) / 10 + 1; //wave enemies defeated would be 9 by the time wave 2 starts so add 1 for a clean 2 times multiplier

	switch (rNum2) {
		case 0:
			if (player1->effect2 != "sluggish") {
				if (rNum < 70)	{
					int tempHealth = player1->getHealth();
					tempHealth = tempHealth - 20 * multiplier;
					player1->setHealth(tempHealth);
					player1->effect2 = "sluggish";
					return "Blue-ringed Octopus used Paralyzing Hold, dealing " + std::to_string(int(20 * multiplier)) + " damage and leaving you unable to move";
				}
				else {
					return "Blue-ringed Octopus tried using Paralyzing Hold, but it missed!";
				}
			}
			else {
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 10 * multiplier;
				player1->setHealth(tempHealth);
				return "Blue-ringed Octopus used Wacky Wrap, dealing " + std::to_string(int(10 * multiplier)) + " damage";
			}
			break;
		case 1:
			if (rNum > 80) {
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 10 * multiplier;
				player1->setHealth(tempHealth);
				player1->effect = "poison";
				return "Blue-ringed Octopus used Poisonous Peck, dealing " + std::to_string(int(10 * multiplier)) + " damage and poisoning you";
			}
			else {
				return "Blue-ringed Octopus tried using Poisonous Peck, but it missed!";
			}
			break;
		case 2:
			if (rNum > 90) {
				int tempHealth = player1->getHealth();
				tempHealth = tempHealth - 20 * multiplier;
				player1->setHealth(tempHealth);
				return "Blue-ringed Octopus used Savage Suction, dealing " + std::to_string(int(20 * multiplier)) + " damage";
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

// // dingo
// dingo::dingo() {
// 	health = 30;
// 	name = "Green Snake";
// }

// std::string dingo::attack(player *player1) {

// }

// dingo::~dingo() {

// }

// // crocodile
// crocodile::crocodile() {
// 	health = 30;
// 	name = "Green Snake";
// }

// std::string crocodile::attack(player *player1) {

// }

// crocodile::~crocodile() {

// }

// // wedge_tailed_eagle
// wedge_tailed_eagle::wedge_tailed_eagle() {
// 	health = 30;
// 	name = "Green Snake";
// }

// std::string wedge_tailed_eagle::attack(player *player1) {

// }

// wedge_tailed_eagle::~wedge_tailed_eagle() {

// }

// // shark
// shark::shark() {
// 	health = 30;
// 	name = "Green Snake";
// }

// std::string shark::attack(player *player1) {

// }

// shark::~shark() {

// }