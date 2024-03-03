#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include "player.h"

extern void clear_terminal();
void hoverAttack(player &player, enemy &enemy, std::string currentMessage) {
    clear_terminal();
    std::cout << "\r" << std::endl;
    std::cout << "  "<< enemy.name << " "; if (enemy.effect == "burn") { std::cout << "*Burnt*";}  std::cout << " Enemy Health: " << enemy.health << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << " " << currentMessage << "\r"<< std::endl;
    std::cout << " --> Attack     Spells     Items     Guard \r"<< std::endl;
    std::cout << "                                          \r"<< std::endl;
    std::cout << player.name << "  "; if (player.effect == "poison") { std::cout << "*Poisoned*";} std::cout << "  Health = "<< player.getHealth() <<"/"<< player.getMaxHealth() <<"          Spirit = "<< player.getSpirit() <<"/"<< player.getMaxSpirit() <<" \r"<< std::endl;
}

void hoverSpells(player &player, enemy &enemy, std::string currentMessage) {
    clear_terminal();
    std::cout << "\r" << std::endl;
    std::cout << "  "<< enemy.name << " "; if (enemy.effect == "burn") { std::cout << "*Burnt*";}  std::cout << " Enemy Health: " << enemy.health << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << " " << currentMessage << "\r"<< std::endl;
    std::cout << "     Attack --> Spells     Items     Guard \r"<< std::endl;
    std::cout << "                                          \r"<< std::endl;
    std::cout << player.name << "  "; if (player.effect == "poison") { std::cout << "*Poisoned*";} std::cout << "  Health = "<< player.getHealth() <<"/"<< player.getMaxHealth() <<"          Spirit = "<< player.getSpirit() <<"/"<< player.getMaxSpirit() <<" \r"<< std::endl;
}

void hoverItems(player &player, enemy &enemy, std::string currentMessage) {
    clear_terminal();
    std::cout << "\r" << std::endl;
    std::cout << "  "<< enemy.name << " "; if (enemy.effect == "burn") { std::cout << "*Burnt*";}  std::cout << " Enemy Health: " << enemy.health << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << " " << currentMessage << "\r"<< std::endl;
    std::cout << "     Attack     Spells --> Items     Guard \r"<< std::endl;
    std::cout << "                                          \r"<< std::endl;
    std::cout << player.name << "  "; if (player.effect == "poison") { std::cout << "*Poisoned*";} std::cout << "  Health = "<< player.getHealth() <<"/"<< player.getMaxHealth() <<"          Spirit = "<< player.getSpirit() <<"/"<< player.getMaxSpirit() <<" \r"<< std::endl;
}

void hoverGuard(player &player, enemy &enemy, std::string currentMessage) {
    clear_terminal();
    std::cout << "\r" << std::endl;
    std::cout << "  "<< enemy.name << " "; if (enemy.effect == "burn") { std::cout << "*Burnt*";}  std::cout << " Enemy Health: " << enemy.health << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << " " << currentMessage << "\r"<< std::endl;
    std::cout << "     Attack     Spells     Items --> Guard \r"<< std::endl;
    std::cout << "                                          \r"<< std::endl;
    std::cout << player.name << "  "; if (player.effect == "poison") { std::cout << "*Poisoned*";} std::cout << "  Health = "<< player.getHealth() <<"/"<< player.getMaxHealth() <<"          Spirit = "<< player.getSpirit() <<"/"<< player.getMaxSpirit() <<" \r"<< std::endl;
}

void hoverAttack(player &player, enemy &enemy, int highlighted_option, std::string currentMessage) {
    clear_terminal();
    std::cout << "\r" << std::endl;
    std::cout << "  "<< enemy.name << " "; if (enemy.effect == "burn") { std::cout << "*Burnt*";}  std::cout << " Enemy Health: " << enemy.health << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << " " << currentMessage << "\r"<< std::endl;
    for (int i=0; i < player.attacks; i++) {
        if (highlighted_option == i) {
            std::cout << " --> "<< player.getAttack(i);
        }
        else {
            std::cout << "     "<< player.getAttack(i);

        }
    }
    if (highlighted_option == player.attacks) {
        std::cout <<" --> Back\r"<< std::endl;
    }
    else {
        std::cout <<"     Back\r"<< std::endl;
    }
    std::cout << "                                          \r"<< std::endl;
    std::cout << player.name << "  "; if (player.effect == "poison") { std::cout << "*Poisoned*";} std::cout << "  Health = "<< player.getHealth() <<"/"<< player.getMaxHealth() <<"          Spirit = "<< player.getSpirit() <<"/"<< player.getMaxSpirit() <<" \r"<< std::endl;
}

void hoverSpell(player &player, enemy &enemy, int highlighted_option, std::string currentMessage) {
    clear_terminal();
    std::cout << "\r" << std::endl;
    std::cout << "  "<< enemy.name << " "; if (enemy.effect == "burn") { std::cout << "*Burnt*";}  std::cout << " Enemy Health: " << enemy.health << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << " " << currentMessage << "\r"<< std::endl;
    if (player.spells > 0) {
        for (int i=0; i < player.spells; i++) {
            if (highlighted_option == i) {
                std::cout << " --> "<< player.getSpell(i);
            }
            else {
                std::cout << "     "<< player.getSpell(i);
            }
        }
        if (highlighted_option == player.spells) {
            std::cout <<" --> Back\r"<< std::endl;
        }
        else {
            std::cout <<"     Back\r"<< std::endl;
        }
    }
    else { std::cout <<" You haven't learnt any spells --> Back\r"<< std::endl; }
    std::cout << "                                          \r"<< std::endl;
    std::cout << player.name << "  "; if (player.effect == "poison") { std::cout << "*Poisoned*";} std::cout << "  Health = "<< player.getHealth() <<"/"<< player.getMaxHealth() <<"          Spirit = "<< player.getSpirit() <<"/"<< player.getMaxSpirit() <<" \r"<< std::endl;
}

void hoverItem(player &player, enemy &enemy, int highlighted_option, std::string currentMessage) {
    clear_terminal();
    std::cout << "\r" << std::endl;
    std::cout << "  "<< enemy.name << " "; if (enemy.effect == "burn") { std::cout << "*Burnt*";}  std::cout << " Enemy Health: " << enemy.health << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << " " << currentMessage << "\r"<< std::endl;
    if (player.item > 0) {
        for (int i=0; i < player.item; i++) {
           if (highlighted_option == i) {
                std::cout << " --> "<< player.getItem(i);
           }
           else {
               std::cout << "     "<< player.getItem(i);
           }
        }
        if (highlighted_option == player.item) {
            std::cout <<" --> Back\r"<< std::endl;
        }
        else {
            std::cout <<"     Back\r"<< std::endl;
        }
    }
    else { std::cout <<" You have no items --> Back\r"<< std::endl; }
    std::cout << "                                          \r"<< std::endl;
    std::cout << player.name << "  "; if (player.effect == "poison") { std::cout << "*Poisoned*";} std::cout << "  Health = "<< player.getHealth() <<"/"<< player.getMaxHealth() <<"          Spirit = "<< player.getSpirit() <<"/"<< player.getMaxSpirit() <<" \r"<< std::endl;
}

void hoverOK(player &player, enemy &enemy, std::string currentMessage) {
        clear_terminal();
    std::cout << "\r" << std::endl;
    std::cout << "  "<< enemy.name << " "; if (enemy.effect == "burn") { std::cout << "*Burnt*";}  std::cout << " Enemy Health: " << enemy.health << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << " " << currentMessage << "\r"<< std::endl;
    std::cout << " --> OK \r"<< std::endl;
    std::cout << "                                          \r"<< std::endl;
    std::cout << player.name << "  "; if (player.effect == "Poison") { std::cout << "*Poisoned*";} std::cout << "  Health = "<< player.getHealth() <<"/"<< player.getMaxHealth() <<"          Spirit = "<< player.getSpirit() <<"/"<< player.getMaxSpirit() <<" \r"<< std::endl;
}

void hoverPause(player &player, enemy &enemy, std::string currentMessage) {
        clear_terminal();
    std::cout << "\r" << std::endl;
    std::cout << "  "<< enemy.name << " "; if (enemy.effect == "burn") { std::cout << "*Burnt*";}  std::cout << " Enemy Health: " << enemy.health << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << "\r"<< std::endl;
    std::cout << " " << currentMessage << "\r"<< std::endl;
    std::cout << "                                          \r"<< std::endl;
    std::cout << player.name << "  "; if (player.effect == "poison") { std::cout << "*Poisoned*";} std::cout << "  Health = "<< player.getHealth() <<"/"<< player.getMaxHealth() <<"          Spirit = "<< player.getSpirit() <<"/"<< player.getMaxSpirit() <<" \r"<< std::endl;
}


int game() {

    clear_terminal();

    // objects created here
    player player;
    items yam("Yam");
    items brush_berry("Brush Berry");
    items bush_tomato("Bush Tomato");
    items desert_lime("Desert Lime");
    items wild_orange("Wild Orange");
    items witchetty_grub("Witchetty Grub");

    // other variables created here
    std::string *enemies{ new std::string[19] }; // 19 enemies for now, allocate space depending on difficulty later
    std::string currentMessage; // what outputs to the user, usually declarations of moves and items, etc
    int numberOfEnemies = 18; // stores total number of enemies (not including rainbow serpent)
    int rNum, rNum2;
    srand(time(NULL));

    for (int i=0; i < numberOfEnemies / 2; i++) { // randomly generates first half of easy enemies
        rNum = rand() % 6 + 1;
        switch (rNum) {
            case 1: if (enemies[i - 1] != "Green Snake") { enemies[i] = "Green Snake"; } else { enemies[i] = "Echidna"; }; break;
            case 2: if (enemies[i - 1] != "Echidna") { enemies[i] = "Echidna"; } else { enemies[i] = "Kangaroo"; }; break;
            case 3: if (enemies[i - 1] != "Kangaroo") { enemies[i] = "Kangaroo"; } else { enemies[i] = "Scorpion"; }; break;
            case 4: if (enemies[i - 1] != "Scorpion") { enemies[i] = "Scorpion"; } else { enemies[i] = "Spider"; }; break;
            case 5: if (enemies[i - 1] != "Spider") { enemies[i] = "Spider"; } else { enemies[i] = "Koala"; }; break;
            case 6: if (enemies[i - 1] != "Koala") { enemies[i] = "Koala"; } else { enemies[i] = "Green Snake"; }; break;
        }
    }

    for (int i=0; i < numberOfEnemies / 2; i++) { // randomly generates second half of harder enemies
        rNum = rand() % 6 + 1;
        switch (rNum) {
            case 1: enemies[i + numberOfEnemies / 2] = "Brown Snake"; break;
            case 2: enemies[i + numberOfEnemies / 2] = "Blue-ringed Octopus"; break;
            case 3: enemies[i + numberOfEnemies / 2] = "Shark"; break;
            case 4: enemies[i + numberOfEnemies / 2] = "Dingo"; break;
            case 5: enemies[i + numberOfEnemies / 2] = "Crocodile"; break;
            case 6: enemies[i + numberOfEnemies / 2] = "Wedge-tailed Eagle"; break;
        }
    }

    enemies[numberOfEnemies] = "Rainbow Serpent";

    std::string current_enemy = enemies[0]; // displays what enemy is currently being fought

    //One Attack and spell are learned every 3 levels (These are arranged in the order the moves are learned)
    // regular moves (Start with boomerang and club)
    //Basic attack for damage (low damage and 100 acc)
    moves club(100, 10, 0, "NULL", "Club Smack");
    //Slighty more damage and slightly less accuracy than club
    moves boomerang(80, 15, 0, "NULL", "Boomerang Toss");
    //Good damage but much less accuracy
    moves spear(50, 30, 0, "NULL", "Spear Hurl" );
    //Reliable 100 acc move with decent damage
    moves axe(100, 20, 0, "NULL", "Axe Swipe");
    //All or nothing, low accuracy high damage
    moves gnarly_gambit(35, 50, 0, "NULL", "Gnarly Gambit");
    //Hefty club Player can't attack on next turn
    moves hefty_club(100, 60, 0, "Sluggish", "Hefty Club");


    // spells (Arranged in the order that they are obtained)
    //WeakHeal effect heals 25hp
    moves heal(100, 0, 10, "WeakHeal", "Heal");
    //Cleanse gets rid of poison status (and others if they are added)
    moves cleanse(100, 0, 10, "Cleanse", "Cleanse");
    //Does five damage and burns enemy for 10 damage at the end of each turn
    moves flame_of_wala(100, 5, 20, "Burn", "Flame of Wala");
    //StrongHeal effect heals 50hp
    moves elder_heal(100, 0, 30, "StrongHeal", "Elder Heal");
    //Good spell for damage
    moves nargun_fist(100, 40, 20, "NULL","Nargun's Fist");
    //FullHeal effect heals health to full
    moves rainbow_restoration(100, 0, 50, "FullHeal", "Rainbow Restoration");
    //Big damage spell needs lots of spirit
    moves wrath_of_wambeen(100, 75, 60, "NULL", "Wambeen's Wrath");

    // player starts with two moves and a spell learnt
    player.learn_attack("Club");
    player.learn_attack("Boomerang");
    player.learn_spell("Heal");

    // prompts user for character name and stores into into player object
    std::cout << "Please enter your characters name: ";
    char player_name[50];
    std::cin.getline(player_name,50);
    player.getName(player_name);

    // initilize the ncurses window
    initscr();
    clear();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
	noecho();
	refresh();
	raw();
	cbreak();
	curs_set(0);

    enemy *enemy;

    int ch;
    bool ok_screen = false;
    int highlightedOption = 1;
    int selectedMenu = 1; // main is 1, attack is 2, spells is 3 and items is 4
    bool encounterMessage = true;
    bool effectMessage = true;
    bool enemyEffectMessage = true;
    bool playerTurn = false;
    bool firstEnemy = true;
    //keep track of groups of moves learned so moves don't get learned several times.
    int moveGroup = 0;


    // while loop of entire game
    while(player.player_death == false) {

    if (encounterMessage == true) {

        green_snake *gs = new green_snake();
        echidna *e = new echidna();
        kangaroo *ka = new kangaroo();
        scorpion *sc = new scorpion();
        spider *sp = new spider();
        koala *ko = new koala();

        if (firstEnemy == true) {firstEnemy = false;}
        else {player.enemiesDefeated = player.enemiesDefeated + 1;}

        if (enemies[player.enemiesDefeated] == "Green Snake") {enemy = gs; delete e; delete ka; delete sc; delete sp; delete ko;}
        else if (enemies[player.enemiesDefeated] == "Echidna") {enemy = e; delete gs; delete ka; delete sc; delete sp; delete ko;}
        else if (enemies[player.enemiesDefeated] == "Kangaroo") {enemy = ka; delete gs; delete e; delete sc; delete sp; delete ko;}
        else if (enemies[player.enemiesDefeated] == "Scorpion") {enemy = sc; delete gs; delete e; delete ka; delete sp; delete ko;}
        else if (enemies[player.enemiesDefeated] == "Spider") {enemy = sp; delete gs; delete e; delete ka; delete sc; delete ko;}
        else if (enemies[player.enemiesDefeated] == "Koala") {enemy = ko; delete gs; delete e; delete ka; delete sc; delete sp;}

        // else if (enemies[enemiesDefeated] == "Brown Snake") {brown_Snake bs; *enemy = &bs;}
        // else if (enemies[enemiesDefeated] == "Blue-ringed Octopus") {blue_ringed_octopus bro; *enemy = &bro;}
        // else if (enemies[enemiesDefeated] == "Shark") {shark sh; *enemy = &sh;}
        // else if (enemies[enemiesDefeated] == "Dingo") {dingo d; *enemy = &d;}
        // else if (enemies[enemiesDefeated] == "Crocodile") {crocodile c; *enemy = &c;}
        // else if (enemies[enemiesDefeated] == "Wedge-tailed_Eagle") {wedge_tailed_eagle wte; *enemy = &wte;}

    }
    
    // every three enemies and before the last enemy (boss), give the player a move / spell
    if (player.enemiesDefeated == 3 && moveGroup == 0) {
        player.learn_spell("Cleanse");
        player.learn_attack("Spear Hurl");
        moveGroup++;
    } else if (player.enemiesDefeated == 6 && moveGroup == 1) {
        player.learn_spell("Flame of Wala");
        player.learn_attack("Axe Swipe");
        moveGroup++;
    } else if (player.enemiesDefeated == 9 && moveGroup == 2) {
        player.learn_spell("Elder Heal");
        moveGroup++;
    } else if (player.enemiesDefeated == 12 && moveGroup == 3) {
        player.learn_spell("Nargun's Fist");
        player.learn_attack("Gnarly Gambit");
        moveGroup++;
    } else if (player.enemiesDefeated == 15 && moveGroup == 4) {
        player.learn_spell("Rainbow Restoration");
        player.learn_attack("Hefty Club");
        moveGroup++;
    } else if (player.enemiesDefeated == 17 && moveGroup == 5) {
        player.learn_spell("Wambeen's Wrath");
        moveGroup++;
    }

    // first output of UI
    if (encounterMessage == true) {
        currentMessage = "You encountered a " + enemies[player.enemiesDefeated] + "!";
        hoverAttack(player, *enemy, currentMessage);
        encounterMessage = false;
    }

    ch = getch();

    if (player.player_turn == true) { // players turn
        switch (ch) // main switch statement
        {
            case KEY_LEFT:
            if (ok_screen != true) {
                switch(selectedMenu) // checks which menu your in
                {
                    case 1:
                        switch (highlightedOption) // checks and changes selected option in main
                        {
                            case 1:
                            highlightedOption = 4;
                            hoverGuard(player, *enemy, currentMessage);
                                break;
                            case 2:
                            highlightedOption--;
                            hoverAttack(player, *enemy, currentMessage);
                                break;
                            case 3:
                            highlightedOption--;
                            hoverSpells(player, *enemy, currentMessage);
                                break;
                            case 4:
                            highlightedOption--;
                            hoverItems(player, *enemy, currentMessage);
                            break;
                        }
                        break;
                    case 2:
                        highlightedOption--;
                        if (highlightedOption == -1) {
                            highlightedOption = player.attacks;
                            hoverAttack(player, *enemy, highlightedOption, currentMessage);
                        }
                        else {
                            hoverAttack(player, *enemy, highlightedOption, currentMessage);
                        }
                        break;
                    case 3:
                    if (player.spells > 0) {
                        highlightedOption--;
                        if (highlightedOption == -1) {
                            highlightedOption = player.spells;
                            hoverSpell(player, *enemy, highlightedOption, currentMessage);
                        }
                        else {
                            hoverSpell(player, *enemy, highlightedOption, currentMessage);
                        }
                    }
                        break;
                    case 4:
                    if (player.item > 0) {
                        highlightedOption--;
                        if (highlightedOption == -1) {
                            highlightedOption = player.item;
                            hoverItem(player, *enemy, highlightedOption, currentMessage);
                        }
                        else {
                            hoverItem(player, *enemy, highlightedOption, currentMessage);
                        }
                    }
                        break;
                }
                break;
            }
            case KEY_RIGHT:
            if (ok_screen != true) {
                switch(selectedMenu) // checks which menu you're in
                {
                    case 1:
                        switch (highlightedOption) // checks and changes selected option in main
                        {
                            case 1:
                            highlightedOption++;
                            hoverSpells(player, *enemy, currentMessage);
                                break;
                            case 2:
                            highlightedOption++;
                            hoverItems(player, *enemy, currentMessage);
                                break;
                            case 3:
                            highlightedOption++;
                            hoverGuard(player, *enemy, currentMessage);
                                break;
                            case 4:
                            highlightedOption = 1;
                            hoverAttack(player, *enemy, currentMessage);
                            break;
                        }
                        break;
                    case 2:
                        highlightedOption++;
                        if (highlightedOption == player.attacks + 1) {
                            highlightedOption = 0;
                            hoverAttack(player, *enemy, highlightedOption, currentMessage);
                        }
                        else {
                            hoverAttack(player, *enemy, highlightedOption, currentMessage);
                        }
                        break;
                    case 3:
                    if (player.spells > 0) {
                        highlightedOption++;
                        if (highlightedOption == player.spells + 1) {
                            highlightedOption = 0;
                            hoverSpell(player, *enemy, highlightedOption, currentMessage);
                        }
                        else {
                            hoverSpell(player, *enemy, highlightedOption, currentMessage);
                        }
                    }
                        break;
                    case 4:
                    if (player.item > 0) {
                        highlightedOption++;
                        if (highlightedOption == player.item + 1) {
                            highlightedOption = 0;
                            hoverItem(player, *enemy, highlightedOption, currentMessage);
                        }
                        else {
                            hoverItem(player, *enemy, highlightedOption, currentMessage);
                        }
                    }
                        break;
                }
                break;
            }
            case 10: // on return press
                if (ok_screen == true) {
                    if (playerTurn == true) {player.player_turn = true; playerTurn = false;}
                    else {player.player_turn = false; playerTurn = false;}
                    ok_screen = false;
                }
            else {
                switch(selectedMenu) // checks which menu your in
                {
                    case 1:
                        switch (highlightedOption) // checks selected option in main
                        {
                            case 1:
                                highlightedOption = 0;
                                selectedMenu = 2;
                                hoverAttack(player, *enemy, highlightedOption, currentMessage);
                                break;
                            case 2:
                                highlightedOption = 0;
                                selectedMenu = 3;
                                hoverSpell(player, *enemy, highlightedOption, currentMessage);
                                break;
                            case 3:
                                selectedMenu = 4;
                                highlightedOption = 0;
                                hoverItem(player, *enemy, highlightedOption, currentMessage);
                                break;
                            case 4:
                                highlightedOption = 1;
                                player.block = true;
                                currentMessage = "You raise your arms to block incoming damage";
                                hoverOK(player, *enemy, currentMessage);
                                ok_screen = true;
                                break;
                        }
                        break;
                    case 2: // checks selected option in attack
                        if (highlightedOption < player.attacks) {
                            if (player.learnt_attacks[highlightedOption] == "Club") {
                                currentMessage = player.attack(club, enemy);
                                if (enemy->health < 1) { enemy->health = 0; }
                            } else if (player.learnt_attacks[highlightedOption] == "Boomerang") {
                                currentMessage = player.attack(boomerang, enemy);
                                if (enemy->health < 1) { enemy->health = 0; }
                            } else if (player.learnt_attacks[highlightedOption] == "Spear Hurl") {
                                currentMessage = player.attack(spear, enemy);
                                if (enemy->health < 1) { enemy->health = 0; }
                            } else if (player.learnt_attacks[highlightedOption] == "Axe Swipe") {
                                currentMessage = player.attack(axe, enemy);
                                if (enemy->health < 1) { enemy->health = 0; }
                            } else if (player.learnt_attacks[highlightedOption] == "Gnarly Gambit") {
                                currentMessage = player.attack(gnarly_gambit, enemy);
                                if (enemy->health < 1) { enemy->health = 0; }
                            } else if (player.learnt_attacks[highlightedOption] == "Hefty Club") {
                                currentMessage = player.attack(hefty_club, enemy);
                                if (enemy->health < 1) { enemy->health = 0; }
                            }
                            highlightedOption = 1;
                            selectedMenu = 1;
                            hoverOK(player, *enemy, currentMessage);
                            ok_screen = true;
                        }
                        else if (highlightedOption == player.attacks) {
                            highlightedOption = 1;
                            selectedMenu = 1;
                            hoverAttack(player, *enemy, currentMessage);
                        }
                        break;
                    case 3:
                        if (highlightedOption < player.spells) {
                            if (player.learnt_spells[highlightedOption] == "Heal") {
                                if (heal.spiritCost > player.getSpirit()) {
                                    currentMessage = "Not enough spirit for that move";
                                    playerTurn = true;
                                } else {
                                    currentMessage = player.attack(heal, enemy);
                                    player.decreaseSpirit(heal.spiritCost);
                                }
                            } else if (player.learnt_spells[highlightedOption] == "Cleanse") {
                                if (cleanse.spiritCost > player.getSpirit()) {
                                    currentMessage = "Not enough spirit for that move";
                                    playerTurn = true;
                                } else {
                                    currentMessage = player.attack(cleanse, enemy);
                                    player.decreaseSpirit(cleanse.spiritCost);
                                }
                            } else if (player.learnt_spells[highlightedOption] == "Flame of Wala") {
                                if (flame_of_wala.spiritCost > player.getSpirit()) {
                                    currentMessage = "Not enough spirit for that move";
                                    playerTurn = true;
                                } else {
                                    currentMessage = player.attack(flame_of_wala, enemy);
                                    player.decreaseSpirit(flame_of_wala.spiritCost);
                                    enemyEffectMessage = false; //Enemy won't take burn damage until the turn after the move is used
                                }
                            } else if (player.learnt_spells[highlightedOption] == "Elder Heal") {
                                if (elder_heal.spiritCost > player.getSpirit()) {
                                    currentMessage = "Not enough spirit for that move";
                                    playerTurn = true;
                                } else {
                                    currentMessage = player.attack(elder_heal, enemy);
                                    player.decreaseSpirit(elder_heal.spiritCost);
                                }
                            } else if (player.learnt_spells[highlightedOption] == "Nargun's Fist") {
                                if (nargun_fist.spiritCost > player.getSpirit()) {
                                    currentMessage = "Not enough spirit for that move";
                                    playerTurn = true;
                                } else {
                                    currentMessage = player.attack(nargun_fist, enemy);
                                    player.decreaseSpirit(nargun_fist.spiritCost);
                                }
                            } else if (player.learnt_spells[highlightedOption] == "Rainbow Restoration") {
                                if (rainbow_restoration.spiritCost > player.getSpirit()) {
                                    currentMessage = "Not enough spirit for that move";
                                    playerTurn = true;
                                } else {
                                    currentMessage = player.attack(rainbow_restoration, enemy);
                                    player.decreaseSpirit(rainbow_restoration.spiritCost);
                                }
                            } else if (player.learnt_spells[highlightedOption] == "Wambeen's Wrath") {
                                if (wrath_of_wambeen.spiritCost > player.getSpirit()) {
                                    currentMessage = "Not enough spirit for that move";
                                    playerTurn = true;
                                } else {
                                    currentMessage = player.attack(wrath_of_wambeen, enemy);
                                    player.decreaseSpirit(wrath_of_wambeen.spiritCost);
                                }
                            }

                            highlightedOption = 1;
                            selectedMenu = 1;
                            hoverOK(player, *enemy, currentMessage);
                            ok_screen = true;
                        }
                        else if (highlightedOption == player.spells) {
                            highlightedOption = 1;
                            selectedMenu = 1;
                            hoverAttack(player, *enemy, currentMessage);
                        }
                        break;
                    case 4:

                    items yam("Yam");
    items brush_berry("Brush Berry");
    items bush_tomato("Bush Tomato");
    items desert_lime("Desert Lime");
    items wild_orange("Wild Orange");
    items witchetty_grub("Witchetty Grub");
                        if (highlightedOption < player.item) {
                            if (player.gained_items[highlightedOption] == "Yam") {
                                currentMessage = player.use_item(yam);
                                if (enemy->health < 1) { enemy->health = 0; }
                            } else if (player.gained_items[highlightedOption] == "Brush Berry") {
                                currentMessage = player.use_item(brush_berry);
                                if (enemy->health < 1) { enemy->health = 0; }
                            } else if (player.gained_items[highlightedOption] == "Bush Tomato") {
                                currentMessage = player.use_item(bush_tomato);
                                if (enemy->health < 1) { enemy->health = 0; }
                            } else if (player.gained_items[highlightedOption] == "Desert Lime") {
                                currentMessage = player.use_item(desert_lime);
                                if (enemy->health < 1) { enemy->health = 0; }
                            } else if (player.gained_items[highlightedOption] == "Wild Orange") {
                                currentMessage = player.use_item(wild_orange);
                                if (enemy->health < 1) { enemy->health = 0; }
                            } else if (player.gained_items[highlightedOption] == "Witchetty Grub") {
                                currentMessage = player.use_item(witchetty_grub);
                                if (enemy->health < 1) { enemy->health = 0; }
                            }
                            highlightedOption = 1;
                            selectedMenu = 1;
                            player.player_turn = false;
                            hoverPause(player, *enemy, currentMessage);
                            usleep(1500000);
                        }
                        else if (highlightedOption == player.item) {
                            highlightedOption = 1;
                            selectedMenu = 1;
                            hoverAttack(player, *enemy, currentMessage);
                        }
                        break;
                }
            }
                break;
            //pressing escape or q takes the player back to the main menu
            case 27 :
            case 'q':
                clear_terminal();
                delete[] enemies;
                return 0;
        }
    }
        else if (player.player_turn == false) { // on enemies turn

            if (player.effect != "NULL" && effectMessage == true && enemy->health != 0) { // checks if player has a status effect
                    if (player.effect == "poison") {
                        player.decreaseHealth(10);
                        currentMessage = "You're poisoned! You take 10 damage";
                        hoverPause(player, *enemy, currentMessage);
                        effectMessage = false;
                        usleep(1500000);
                    }
                }
                if (enemy->effect != "NULL" && enemyEffectMessage == true) { // checks if enemy has a status effect
                    if (enemy->effect == "burn") {
                        enemy->health = enemy->health - 10;
                        if (enemy->health < 1) { // when enemy dies
                             enemy->health = 0;
                        }
                        currentMessage = "The " + enemy->name + " is burnt, and takes 10 damage";
                        hoverPause(player, *enemy, currentMessage);
                        enemyEffectMessage = false;
                        usleep(1500000);
                    }
                }

            if (enemy->health < 1) { // when enemy dies
                enemy->health = 0;
                player.health = player.max_health; // reset players health
                currentMessage = "You defeated the " + enemies[player.enemiesDefeated] + "!";
                hoverPause(player, *enemy, currentMessage);
                player.effect = "NULL";
                player.effect2 = "NULL";
                usleep(1500000);
                rNum2 = rand() % 5;
                    switch (rNum2) {
                        case 0:
                            player.gain_item("Yam");
                            currentMessage = "The " + enemy->name + " dropped a Yam!";
                            break;
                        case 1:
                            player.gain_item("Brush Berry");
                            currentMessage = "The " + enemy->name + " dropped a Brush Berry!";
                            break;
                        case 2:
                            player.gain_item("Bush Tomato");
                            currentMessage = "The " + enemy->name + " dropped a Bush Tomato!";
                            break;
                        case 3:
                            player.gain_item("Desert Lime");
                            currentMessage = "The " + enemy->name + " dropped a Desert Lime!";
                            break;
                        case 4:
                            player.gain_item("Wild Orange");
                            currentMessage = "The " + enemy->name + " dropped a Wild Orange!";
                            break;
                        case 5:
                            player.gain_item("Witchetty Grub");
                            currentMessage = "The " + enemy->name + " dropped a Witchetty Grub!";
                            break;
                    }
                hoverPause(player, *enemy, currentMessage);
                usleep(1500000);
                encounterMessage = true;
                player.block = false;
                player.player_turn = true;
                effectMessage = true;
                enemyEffectMessage = true;
            }
            else { // enemy doesnt die
                currentMessage = enemy->attack(&player); // attacks the player
                //Ensure health doesn't display as negative
                if (player.health < 0) {
                    player.setHealth(0);
                }
                if (player.effect2 != "sluggish") {
                    hoverAttack(player, *enemy, currentMessage);
                }
                else {
                    hoverPause(player, *enemy, currentMessage);
                }

                if (player.effect2 == "sluggish") {
                    ok_screen = true; //This line causes the enemy to attack again, because pressing enter while this is true changes it to the enemy's turn
                    currentMessage = "You try to move but don't have the strength";
                    usleep(1500000);
                    hoverOK(player, *enemy, currentMessage);
                    player.effect2 = "NULL";
                }

                player.checkDeath();
                enemy->checkDeath();
                player.block = false;
                player.player_turn = true;
                effectMessage = true;
                enemyEffectMessage = true;
            }

        }
    }
    // player dies here
    delete[] enemies;
    usleep(1500000);
    clear_terminal();
    std::cout << " You died! \r" << std::endl;
    usleep(1500000);
    clear_terminal();
    return 0;

}