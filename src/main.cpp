#include <iostream>
#include "Game.h"

int main()
{
    /*
    Map map;
    map.load_lvl(1);
    map.print_map();
    */



	Game game;
	game.init();
	game.loop();

	std::cout << "test" << std::endl;

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
}