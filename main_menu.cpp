#include <iostream>
#include <ncurses.h>

extern int game();

void clear_terminal() {
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
    std::cout << "                          \r" << std::endl;
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
    std::cout << "     SETTINGS             \r" << std::endl;
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
                        std::cout << "     SETTINGS             \r" << std::endl;
                        std::cout << " --> EXIT                 \r" << std::endl;
                }
                else if (highlightedOption == 2) {
                    highlightedOption = 1;
                        clear_terminal();
                        std::cout << "WELCOME TO BUSHLAND BLITZ \r" << std::endl;
                        std::cout << " --> START GAME           \r" << std::endl;
                        std::cout << "     SETTINGS             \r" << std::endl;
                        std::cout << "     EXIT                 \r" << std::endl;
                }
                else if (highlightedOption == 3) {
                    highlightedOption = 2;
                        clear_terminal();
                        std::cout << "WELCOME TO BUSHLAND BLITZ \r" << std::endl;
                        std::cout << "     START GAME           \r" << std::endl;
                        std::cout << " --> SETTINGS             \r" << std::endl;
                        std::cout << "     EXIT                 \r" << std::endl;
                }
                break;
            case KEY_DOWN:
                if (highlightedOption == 3) {
                    highlightedOption = 1;
                    clear_terminal();
                    std::cout << "WELCOME TO BUSHLAND BLITZ \r" << std::endl;
                    std::cout << " --> START GAME           \r" << std::endl;
                    std::cout << "     SETTINGS             \r" << std::endl;
                    std::cout << "     EXIT                 \r" << std::endl;
                }
                else if (highlightedOption == 2) {
                    highlightedOption = 3;
                    clear_terminal();
                    std::cout << "WELCOME TO BUSHLAND BLITZ \r" << std::endl;
                    std::cout << "     START GAME           \r" << std::endl;
                    std::cout << "     SETTINGS             \r" << std::endl;
                    std::cout << " --> EXIT                 \r" << std::endl;
                }
                else if (highlightedOption == 1) {
                    highlightedOption = 2;
                    clear_terminal();
                    std::cout << "WELCOME TO BUSHLAND BLITZ \r" << std::endl;
                    std::cout << "     START GAME           \r" << std::endl;
                    std::cout << " --> SETTINGS             \r" << std::endl;
                    std::cout << "     EXIT                 \r" << std::endl;
                }
                break;
            case 10:
                if (highlightedOption == 1) {
	                refresh();
                    endwin();
                    game();
                }
                else if (highlightedOption == 2) {
                    // go to settings
                }
                else if (highlightedOption == 3) {
	                refresh();
                    endwin();
                    return 0;
                }
                break;
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