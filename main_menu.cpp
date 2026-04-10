#include <iostream>
#include <ncurses.h>

extern int game();

//For BushDex
extern bool seenCleanse;
extern bool seenSpear;
extern bool seenWala;
extern bool seenAxe;
extern bool seenElder;
extern bool seenNargun;
extern bool seenGambit;
extern bool seenRainbowR;
extern bool seenHefty;
extern bool seenWambeen;

extern bool seenYam;
extern bool seenBrush;
extern bool seenTomato;
extern bool seenLime;
extern bool seenOrange;
extern bool seenGrub;

extern bool seenGSnake;
extern bool seenEchidna;
extern bool seenKangaroo;
extern bool seenScorpion;
extern bool seenSpider;
extern bool seenKoala;
extern bool seenBSnake;
extern bool seenBROctopus;
extern bool seenShark;
extern bool seenDingo;
extern bool seenCrocodile;
extern bool seenWTEagle;
extern bool seenRSerpent;

void clear_terminal() {
    for (int i = 0; i < 40; i++) {
        std::cout << "                          \r" << std::endl;
    }
}


void bushdex() {
    std::string entityArray[20] = {"PLAYER", "GREEN SNAKE", "ECHIDNA", "KANGAROO", "SCORPION", "SPIDER", "KOALA", "BROWN SNAKE", "BLUE-RINGED OCTOPUS", "SHARK", "DINGO", "CROCODILE", "WEDGE-TAILED EAGLE", "RAINBOW SERPENT", "YAM", "BRUSH BERRY", "BUSH TOMATO", "DESERT LIME", "WILD ORANGE", "WITCHETTY GRUB"};
    int entity = 0; //will modulo by 20 upon incrementing or decrementing to stay in the array bounds

    clear_terminal();
    std::cout << "THE BUSHDEX (1/20)\r" << std::endl;
    std::cout << "Use left & right arrow keys to scroll through \r" << std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "[PLAYER]\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "ATTACKS\r"<< std::endl;
    std::cout << "<Club Smack>: Acc: 100  Dmg: 10\r"<< std::endl;
    std::cout << "<Boomerang Toss> Acc: 80  Dmg: 15\r"<< std::endl;
    if (seenSpear) {
        std::cout << "<Spear Hurl> Acc: 50  Dmg: 30\r"<< std::endl;    
    }
    else {
        std::cout << "?????\r" << std::endl;
    }
    if (seenAxe) {
        std::cout << "<Axe Swipe> Acc: 100  Dmg: 20\r"<< std::endl;    
    }
    else {
        std::cout << "?????\r" << std::endl;
    }
    if (seenGambit) {
        std::cout << "<Gnarly Gambit> Acc: 35  Dmg: 50\r"<< std::endl;    
    }
    else {
        std::cout << "?????\r" << std::endl;
    }
    if (seenHefty) {
        std::cout << "<Hefty Club> Acc: 100  Dmg: 60  Effect: Can't attack on next turn\r"<< std::endl;    
    }
    else {
        std::cout << "?????\r" << std::endl;
    }
    std::cout << "\r"<< std::endl;
    std::cout << "SPELLS\r"<< std::endl;
    std::cout << "<Heal> Cost: 10  Effect: Heals 30HP\r"<< std::endl;
    if (seenCleanse) {
        std::cout << "<Cleanse> Cost: 10  Effect: Removes ailments or grants ailment shield. Also heals 20HP\r"<< std::endl;    
    }
    else {
        std::cout << "?????\r" << std::endl;
    }
    if (seenWala) {
        std::cout << "<Flame of Wala> Cost: 20  Effect: Deals 5 damage and burns the enemy causing them 10 damage every turn\r"<< std::endl;    
    }
    else {
        std::cout << "?????\r" << std::endl;
    }
    if (seenElder) {
        std::cout << "<Elder Heal> Cost: 20  Effect: Heals 80HP\r"<< std::endl;    
    }
    else {
        std::cout << "?????\r" << std::endl;
    }
    if (seenNargun) {
        std::cout << "<Nargun's Fist> Cost: 20  Effect: Deals 50 damage\r"<< std::endl;    
    }
    else {
        std::cout << "?????\r" << std::endl;
    }
    if (seenRainbowR) {
        std::cout << "<Rainbow Restoration> Cost: 50  Effect: Fully restores all health and cleanses ailments\r"<< std::endl;    
    }
    else {
        std::cout << "?????\r" << std::endl;
    }
    if (seenWambeen) {
        std::cout << "<Wambeen's Wrath> Cost: 70  Effect: Deals 80 damage and burns the enemy for 10 damage each turn\r"<< std::endl;    
    }
    else {
        std::cout << "?????\r" << std::endl;
    }
    
    std::cout << "\r"<< std::endl;
    std::cout << "Exit with Esc or q keys\r" << std::endl;
    timeout(-1);//turn on blocking read for getch
    int ch;
    while(1) {
        ch = getch();
        switch (ch)
        {
            case KEY_LEFT:
                entity = entity - 1;
                if (entity < 0) {
                    entity += 20;
                }
                break;
            case KEY_RIGHT:
                entity += 1;
                if (entity > 19) {
                    entity -= 20;
                }
                break;
            case 27 :
            case 'q':
                clear_terminal();
                return;
        }

        //print bushdex page
        clear_terminal();
        std::cout << "THE BUSHDEX (" << entity+1 << "/20)\r" << std::endl;
        std::cout << "Use left & right arrow keys to scroll through \r" << std::endl;
        std::cout << "\r"<< std::endl;
        //Print the the bushdex information for the current entity
        if (entityArray[entity] == "PLAYER") {
            std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
            std::cout << "\r"<< std::endl;
            std::cout << "ATTACKS\r"<< std::endl;
            std::cout << "<Club Smack>: Acc: 100  Dmg: 10\r"<< std::endl;
            std::cout << "<Boomerang Toss> Acc: 80  Dmg: 15\r"<< std::endl;
            if (seenSpear) {
                std::cout << "<Spear Hurl> Acc: 50  Dmg: 30\r"<< std::endl;    
            }
            else {
                std::cout << "?????\r" << std::endl;
            }
            if (seenAxe) {
                std::cout << "<Axe Swipe> Acc: 100  Dmg: 20\r"<< std::endl;    
            }
            else {
                std::cout << "?????\r" << std::endl;
            }
            if (seenGambit) {
                std::cout << "<Gnarly Gambit> Acc: 35  Dmg: 50\r"<< std::endl;    
            }
            else {
                std::cout << "?????\r" << std::endl;
            }
            if (seenHefty) {
                std::cout << "<Hefty Club> Acc: 100  Dmg: 60  Effect: Can't attack on next turn\r"<< std::endl;    
            }
            else {
                std::cout << "?????\r" << std::endl;
            }
            std::cout << "\r"<< std::endl;
            std::cout << "SPELLS\r"<< std::endl;
            std::cout << "<Heal> Cost: 10  Effect: Heals 30HP\r"<< std::endl;
            if (seenCleanse) {
                std::cout << "<Cleanse> Cost: 10  Effect: Removes ailments or grants ailment shield. Also heals 20HP\r"<< std::endl;    
            }
            else {
                std::cout << "?????\r" << std::endl;
            }
            if (seenWala) {
                std::cout << "<Flame of Wala> Cost: 20  Effect: Deals 5 damage and burns the enemy causing them 10 damage every turn\r"<< std::endl;    
            }
            else {
                std::cout << "?????\r" << std::endl;
            }
            if (seenElder) {
                std::cout << "<Elder Heal> Cost: 20  Effect: Heals 80HP\r"<< std::endl;    
            }
            else {
                std::cout << "?????\r" << std::endl;
            }
            if (seenNargun) {
                std::cout << "<Nargun's Fist> Cost: 20  Effect: Deals 50 damage\r"<< std::endl;    
            }
            else {
                std::cout << "?????\r" << std::endl;
            }
            if (seenRainbowR) {
                std::cout << "<Rainbow Restoration> Cost: 50  Effect: Fully restores all health and cleanses ailments\r"<< std::endl;    
            }
            else {
                std::cout << "?????\r" << std::endl;
            }
            if (seenWambeen) {
                std::cout << "<Wambeen's Wrath> Cost: 70  Effect: Deals 80 damage and burns the enemy for 10 damage each turn\r"<< std::endl;    
            }
            else {
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "GREEN SNAKE") {
            if (seenGSnake) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "HP: 60\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "ATTACKS\r"<< std::endl;
                std::cout << "<Chomp> Acc: 99  Dmg: 10\r"<< std::endl;
                std::cout << "<Strangle> Acc: 90  Dmg: 15\r"<< std::endl;
                std::cout << "<Slithery Slap> Acc: 70  Dmg: 25\r"<< std::endl;
                std::cout << "*Final attack damages are affected by a level multiplier\r"<< std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "ECHIDNA") {
            if (seenEchidna) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "HP: 70\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "ATTACKS\r"<< std::endl;
                std::cout << "<Quillshot> Acc: 99  Dmg: 10\r"<< std::endl;
                std::cout << "<Spike> Acc: 80  Dmg: 20\r"<< std::endl;
                std::cout << "<Spiny Charge> Acc: 35  Dmg: 40\r"<< std::endl;
                std::cout << "*Final attack damages are affected by a level multiplier\r"<< std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "KANGAROO") {
            if (seenKangaroo) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "HP: 100\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "ATTACKS\r"<< std::endl;
                std::cout << "<Kick> Acc: 99  Dmg: 10\r"<< std::endl;
                std::cout << "<Punch> Acc: 99  Dmg: 15\r"<< std::endl;
                std::cout << "<Tail Slam> Acc: 80  Dmg: 20\r"<< std::endl;
                std::cout << "*Final attack damages are affected by a level multiplier\r"<< std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "SCORPION") {
            if (seenScorpion) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "HP: 60\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "ATTACKS\r"<< std::endl;
                std::cout << "<Pincer Pinch> Acc: 99  Dmg: 15\r"<< std::endl;
                std::cout << "<Sting> Acc: 80  Dmg: 25\r"<< std::endl;
                std::cout << "<Poison Skewer> Acc: 99  Dmg: 0  Effect: Poisons player dealing damage each turn\r"<< std::endl;
                std::cout << "*Final attack damages are affected by a level multiplier\r"<< std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "SPIDER") {
            if (seenSpider) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "HP: 50\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "ATTACKS\r"<< std::endl;
                std::cout << "<Web Shot> Acc: 99  Dmg: 25\r"<< std::endl;
                std::cout << "<Crazy Crawl> Acc: 99  Dmg: 15\r"<< std::endl;
                std::cout << "<Poison Bite> Acc: 99  Dmg: 0  Effect: Poisons player dealing damage each turn\r"<< std::endl;
                std::cout << "*Final attack damages are affected by a level multiplier\r"<< std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "KOALA") {
            if (seenKoala) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "HP: 80\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "ATTACKS\r"<< std::endl;
                std::cout << "<Claw Swipe> Acc: 99  Dmg: 10\r"<< std::endl;
                std::cout << "<Bear Hug> Acc: 99  Dmg: 20\r"<< std::endl;
                std::cout << "<Sleep> Acc: 99  Dmg: 0  Effect: Heals itself for 10HP\r"<< std::endl;
                std::cout << "*Final damage & heal amounts are affected by a level multiplier\r"<< std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "BROWN SNAKE") {
            if (seenBSnake) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "HP: 100\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "ATTACKS\r"<< std::endl;
                std::cout << "<Chomp> Acc: 100  Dmg: 10\r"<< std::endl;
                std::cout << "<Strangle> Acc: 90  Dmg: 15\r"<< std::endl;
                std::cout << "<Slithery Slap> Acc: 70  Dmg: 25\r"<< std::endl;
                std::cout << "<Lethal Lunge> Acc: 80  Dmg: 20  Effect: Poisons player dealing damage each turn\r"<< std::endl;
                std::cout << "*Final attack damages are affected by a level multiplier\r"<< std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "BLUE-RINGED OCTOPUS") {
            if (seenBROctopus) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "HP: 80\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "ATTACKS\r"<< std::endl;
                std::cout << "<Paralyzing Hold> Acc: 70  Dmg: 20  Effect: Traps the player leaving them immobilised\r"<< std::endl;
                std::cout << "<Wacky Wrap> Acc: 100  Dmg: 10\r"<< std::endl;
                std::cout << "<Poisonous Peck> Acc: 80  Dmg: 10  Effect: Poisons player dealing damage each turn\r"<< std::endl;
                std::cout << "<Savage Suction> Acc: 90  Dmg: 20\r"<< std::endl;
                std::cout << "*Final attack damages are affected by a level multiplier\r"<< std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "SHARK") {
            if (seenShark) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "HP: 120\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "ATTACKS\r"<< std::endl;
                std::cout << "<Rapid Rush> Acc: 80  Dmg: 10  Effect: User becomes swift and attacks again\r"<< std::endl;
                std::cout << "<Fin Smack> Acc: 99  Dmg: 10\r"<< std::endl;
                std::cout << "<Cutting Crunch> Acc: 80  Dmg: 15\r"<< std::endl;
                std::cout << "*Final attack damages are affected by a level multiplier\r"<< std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "DINGO") {
            if (seenDingo) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "HP: 100\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "ATTACKS  (Dingo Always Attacks Twice)\r"<< std::endl;
                std::cout << "<Chomp> Acc: 99  Dmg: 10\r"<< std::endl;
                std::cout << "<Wound Lick> Acc: 99  Dmg: 0  Effect: Heals itself for 5HP\r"<< std::endl;
                std::cout << "<Dog Dive> Acc: 80  Dmg: 15\r"<< std::endl;
                std::cout << "*Final damage & heal amounts are affected by a level multiplier\r"<< std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "CROCODILE") {
            if (seenCrocodile) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "HP: 130\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "ATTACKS\r"<< std::endl;
                std::cout << "<Croc Crunch> Acc: 99  Dmg: 15\r"<< std::endl;
                std::cout << "<Death Roll> Acc: 70  Dmg: 20  Effect: Traps the player leaving them immobilised\r"<< std::endl;
                std::cout << "<Surge> Acc: 80  Dmg: 40  Effect: A turn is spent preparing before the attack\r"<< std::endl;
                std::cout << "*Final attack damages are affected by a level multiplier\r"<< std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "WEDGE-TAILED EAGLE") {
            if (seenWTEagle) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "HP: 100\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "ATTACKS\r"<< std::endl;
                std::cout << "<Wing Whack> Acc: 99  Dmg: 10\r"<< std::endl;
                std::cout << "<Talon Swipe> Acc: 80  Dmg: 20\r"<< std::endl;
                std::cout << "<Sky Dive> Acc: 70  Dmg: 40  Effect: A turn is spent preparing before the attack\r"<< std::endl;
                std::cout << "*Final attack damages are affected by a level multiplier\r"<< std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "RAINBOW SERPENT") {
            if (seenRSerpent) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "HP: 200\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "ATTACKS\r"<< std::endl;
                std::cout << "<Serpent Strike> Acc: 100  Dmg: 40\r"<< std::endl;
                std::cout << "<Venomous Jet> Acc: 80  Dmg: 50  Effect: Poisons player dealing damage each turn\r"<< std::endl;
                std::cout << "<Death Grip> Acc: 70  Dmg: 50  Effect: Traps the player leaving them immobilised\r"<< std::endl;
                std::cout << "<Healing Mist> Acc: 100  Dmg: 0  Effect: One-time use. Heals itself for 75HP\r"<< std::endl;
                std::cout << "<Creator God> Acc: 80  Dmg: 120  Effect: A turn is spent preparing before the attack\r"<< std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "YAM") {
            if (seenYam) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "A wild yam found in the ground.\r" << std::endl;
                std::cout << "Heals 60HP when eaten.\r" << std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "BRUSH BERRY") {
            if (seenBrush) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "A berry discovered among the brush.\r" << std::endl;
                std::cout << "Fully restores your spirit.\r" << std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "BUSH TOMATO") {
            if (seenTomato) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "A tomato-like growth plucked from a desert bush.\r" << std::endl;
                std::cout << "Increases max health by 15.\r" << std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "DESERT LIME") {
            if (seenLime) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "A lone lime found on a withering shrub in the desert.\r" << std::endl;
                std::cout << "Increases max spirit by 10.\r" << std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "WILD ORANGE") {
            if (seenOrange) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "A strange orange found in the arid outback.\r" << std::endl;
                std::cout << "Removes ailments or, if healthy, grants ailment shield.\r" << std::endl;
                std::cout << "On top of this, health is restored by 30.\r" << std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        else if (entityArray[entity] == "WITCHETTY GRUB") {
            if (seenGrub) {
                std::cout << "[" << entityArray[entity] << "]" << "\r"<< std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "A huge, nutritious grub hidden beneath the desert sand.\r" << std::endl;
                std::cout << "Restores health by a whopping 150HP.\r" << std::endl;
            }
            else {
                std::cout << "?????\r" << std::endl;
                std::cout << "\r"<< std::endl;
                std::cout << "?????\r" << std::endl;
                std::cout << "?????\r" << std::endl;
            }
        }
        std::cout << "\r"<< std::endl;
        std::cout << "Exit with Esc or q keys\r" << std::endl;

    }
    clear_terminal();
	return;
} 



int main() {

    // initializes ncurses window
    initscr();
    clear();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
	noecho();
	refresh();
	raw();
	cbreak();
	curs_set(0);

    // default screen - cursor on first option
    clear_terminal();
    std::cout << "WELCOME TO BUSHLAND BLITZ \r" << std::endl;
    std::cout << " --> START GAME           \r" << std::endl;
    std::cout << "     BUSHDEX              \r" << std::endl;
    std::cout << "     EXIT                 \r" << std::endl;

    int ch;
    int highlightedOption = 1;
    while(1) {
        ch = getch();
        switch (ch)
        {
            case KEY_UP:
                if (highlightedOption == 1) {
                    highlightedOption = 3;
                        clear_terminal();
                        std::cout << "WELCOME TO BUSHLAND BLITZ \r" << std::endl;
                        std::cout << "     START GAME           \r" << std::endl;
                        std::cout << "     BUSHDEX              \r" << std::endl;
                        std::cout << " --> EXIT                 \r" << std::endl;
                }
                else if (highlightedOption == 2) {
                    highlightedOption = 1;
                        clear_terminal();
                        std::cout << "WELCOME TO BUSHLAND BLITZ \r" << std::endl;
                        std::cout << " --> START GAME           \r" << std::endl;
                        std::cout << "     BUSHDEX              \r" << std::endl;
                        std::cout << "     EXIT                 \r" << std::endl;
                }
                else if (highlightedOption == 3) {
                    highlightedOption = 2;
                        clear_terminal();
                        std::cout << "WELCOME TO BUSHLAND BLITZ \r" << std::endl;
                        std::cout << "     START GAME           \r" << std::endl;
                        std::cout << " --> BUSHDEX              \r" << std::endl;
                        std::cout << "     EXIT                 \r" << std::endl;
                }
                break;
            case KEY_DOWN:
                if (highlightedOption == 3) {
                    highlightedOption = 1;
                    clear_terminal();
                    std::cout << "WELCOME TO BUSHLAND BLITZ \r" << std::endl;
                    std::cout << " --> START GAME           \r" << std::endl;
                    std::cout << "     BUSHDEX              \r" << std::endl;
                    std::cout << "     EXIT                 \r" << std::endl;
                }
                else if (highlightedOption == 2) {
                    highlightedOption = 3;
                    clear_terminal();
                    std::cout << "WELCOME TO BUSHLAND BLITZ \r" << std::endl;
                    std::cout << "     START GAME           \r" << std::endl;
                    std::cout << "     BUSHDEX              \r" << std::endl;
                    std::cout << " --> EXIT                 \r" << std::endl;
                }
                else if (highlightedOption == 1) {
                    highlightedOption = 2;
                    clear_terminal();
                    std::cout << "WELCOME TO BUSHLAND BLITZ \r" << std::endl;
                    std::cout << "     START GAME           \r" << std::endl;
                    std::cout << " --> BUSHDEX              \r" << std::endl;
                    std::cout << "     EXIT                 \r" << std::endl;
                }
                break;
            case 10:
                if (highlightedOption == 1) {
	                refresh();
                    endwin();
                    game();
                    std::cout << "WELCOME TO BUSHLAND BLITZ \r" << std::endl;
                    std::cout << " --> START GAME           \r" << std::endl;
                    std::cout << "     BUSHDEX              \r" << std::endl;
                    std::cout << "     EXIT                 \r" << std::endl;
                    break;
                }
                else if (highlightedOption == 2) {
                    // go to bushdex
                    bushdex();
                    std::cout << "WELCOME TO BUSHLAND BLITZ \r" << std::endl;
                    std::cout << "     START GAME           \r" << std::endl;
                    std::cout << " --> BUSHDEX              \r" << std::endl;
                    std::cout << "     EXIT                 \r" << std::endl;
                    break;
                }
                else if (highlightedOption == 3) {
	                refresh();
                    endwin();
                    return 0;
                }
                break;
            //escape key or q quits the program
            case 27 :
            case 'q':
                endwin();
                return 0;
                break;
        }

    }
	refresh();
    endwin();

	return 0;
}