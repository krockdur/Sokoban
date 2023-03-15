#g++ -std=c++17 -Wall -Wextra -Werror *.cpp -o output/sokoban -lsfml-graphics -lsfml-window -lsfml-system
CC=g++
CFLAGS=-std=c++17 -Wall -Wextra -Werror
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

EXEC=sokoban

all: $(EXEC)

$(EXEC): main.o game.o config.o map.o player.o
	$(CC) -o $(EXEC) main.o game.o config.o map.o player.o $(LDFLAGS)

main.o : main.cpp Game.h
	$(CC) -c main.cpp -o main.o $(CFLAGS)

game.o: Game.cpp Config.h Map.h Player.h
	$(CC) -c Game.cpp -o game.o $(CFLAGS)
	
config.o: Config.cpp
	$(CC) -c Config.cpp -o config.o $(CFLAGS)

map.o: Map.cpp Case.h Player.h Context.h Config.h
	$(CC) -c Map.cpp -o map.o $(CFLAGS)

player.o: Player.cpp Case.h
	$(CC) -c Player.cpp -o player.o $(CFLAGS)

clean:
	rm *.o

mp: clean
	rm -rf output/$(EXEC)	


