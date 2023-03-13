#include <iostream>
#include <stdlib.h>

#include "Game.h"

int main()
{

	Game game;
	game.init();
	game.loop();



/*
    char key_value = 'a';
    while (key_value != 'w')
    {
        std::cout << "mouvement (zqsd) :";
        std::cin >> key_value;
        if (key_value == 'z')
        {
        }
        if (key_value == 'q')
        {
        }
        if (key_value == 's')
        {
        }
        if (key_value == 'd')
        {
        }
    }
*/

    return 0;
}

// g++ -std=c++17 -Wall -Wextra -Werror *.cpp -o output/sokoban -lsfml-graphics -lsfml-window -lsfml-system

// g++ -c main.cpp -o main.o -IC:/SFML-w64/include -DSFML_STATIC -O3 -g -Wall -m64 && g++ main.o -o run.exe -LC:/SFML-w64/lib -lsfml-graphics -lsfml-window -lsfml-system

// g++ -c main.cpp -o main.o -IC:/SFML-w64/include -DSFML_STATIC -O3 -g -Wall -m64
// g++ main.o -o run.exe -LC:/SFML-w64/lib -lsfml-graphics -lsfml-window -lsfml-system

// rm output\win\run.exe && g++ -c *.cpp -IC:/libs/SFML/include -DSFML_STATIC -O3 -g -Wall -m64 && g++ *.o -o output/win/run.exe -LC:/libs/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system && rm *.o

// g++ *.o -o output/win/run.exe -LC:/libs/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system