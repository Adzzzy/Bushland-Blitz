
all: driver

driver: player.o enemy.o moves.o items.o main.o main_menu.o
	g++ player.o enemy.o moves.o items.o main.o main_menu.o -o driver -lncurses

player.o: player.cpp player.h
	g++ -c player.cpp -o player.o

enemy.o: enemy.cpp enemy.h
	g++ -c enemy.cpp -o enemy.o

moves.o: moves.cpp moves.h
	g++ -c moves.cpp -o moves.o

items.o: items.cpp items.h
	g++ -c items.cpp -o items.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

main_menu.o: main_menu.cpp
	g++ -c main_menu.cpp -o main_menu.o

tests:
	bash iotests

moves:
	bash iotests_moves

clean:
	rm -f *.o driver
