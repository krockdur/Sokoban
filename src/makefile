
CC=g++
CFLAGS=-DSFML_STATIC -O3 -g -Wall -m64
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

EXEC=sokoban.exe

all: $(EXEC)

debug: main.o game.o config.o map.o player.o
	$(CC) -g -o $(EXEC) main.o game.o config.o map.o player.o -LC:/libs/SFML/lib $(LDFLAGS)

$(EXEC): main.o game.o config.o map.o player.o
	$(CC) -o $(EXEC) main.o game.o config.o map.o player.o -LC:/libs/SFML/lib $(LDFLAGS)

main.o : main.cpp Game.h
	$(CC) -c main.cpp -o main.o -IC:/libs/SFML/include $(CFLAGS)

game.o: Game.cpp Config.h Map.h Player.h
	$(CC) -c Game.cpp -o game.o -IC:/libs/SFML/include $(CFLAGS)
	
map.o: Map.cpp Case.h Player.h Context.h Config.h
	$(CC) -c Map.cpp -o map.o -IC:/libs/SFML/include $(CFLAGS)

player.o: Player.cpp Case.h
	$(CC) -c Player.cpp -o player.o -IC:/libs/SFML/include $(CFLAGS)

config.o: Config.cpp
	$(CC) -c Config.cpp -o config.o -IC:/libs/SFML/include $(CFLAGS)

clean:
	rm *.o

mrproper: clean
	rm sokoban.exe


