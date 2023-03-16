
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

game.o: game.cpp Config.h Map.h Player.h
	$(CC) -c game.cpp -o game.o -IC:/libs/SFML/include $(CFLAGS)
	
config.o: config.cpp
	$(CC) -c config.cpp -o config.o -IC:/libs/SFML/include $(CFLAGS)

map.o: map.cpp Case.h Player.h Context.h
	$(CC) -c map.cpp -o map.o -IC:/libs/SFML/include $(CFLAGS)

player.o: player.cpp Case.h
	$(CC) -c player.cpp -o player.o -IC:/libs/SFML/include $(CFLAGS)

clean:
	del *.o

mrproper: clean
	del /Q sokoban.exe


