
CC=g++
CFLAGS=-DSFML_STATIC -O3 -g -Wall -m64
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
EXEC=sokoban
ODW=output/win/

all: $(EXEC)

sokoban: main.o game.o config.o map.o player.o
	$(CC) -o $(ODW)$(EXEC).exe $(ODW)main.o $(ODW)game.o $(ODW)config.o $(ODW)map.o $(ODW)player.o -LC:/libs/SFML/lib $(LDFLAGS)

main.o : main.cpp Game.h
	$(CC) -c main.cpp -o $(ODW)main.o -IC:/libs/SFML/include $(CFLAGS)

game.o: game.cpp Config.h Map.h Player.h
	$(CC) -c game.cpp -o $(ODW)game.o -IC:/libs/SFML/include $(CFLAGS)
	
config.o: config.cpp
	$(CC) -c config.cpp -o $(ODW)config.o -IC:/libs/SFML/include $(CFLAGS)

map.o: map.cpp Case.h Player.h Context.h
	$(CC) -c map.cpp -o $(ODW)map.o -IC:/libs/SFML/include $(CFLAGS)

player.o: player.cpp Case.h
	$(CC) -c player.cpp -o $(ODW)player.o -IC:/libs/SFML/include $(CFLAGS)

clean:
	rm $(ODW)*.o

mrproper: clean
	rm $(ODW)$(EXEC).exe