//============================================================================
// Name        : Sokoban.cpp
// Author      : Julien F
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>

#include "Map.h"
#include "Player.h"

int main()
{
    /*
    Map map;
    map.load_lvl(1);
    map.print_map();
    */

    Player p(5, 5);

    Map::load_lvl(1);
    Map::print_map(true);

    char key_value = 'a';

    while (key_value != 'w')
    {
        std::cout << "mouvement (zqsd) :";
        std::cin >> key_value;

        if (key_value == 'z')
        {
            p.move_player("up");
        }
        if (key_value == 'q')
        {
            p.move_player("left");
        }
        if (key_value == 's')
        {
            p.move_player("down");
        }
        if (key_value == 'd')
        {
            p.move_player("right");
        }

        system("cls");
        Map::check_if_win();
        Map::print_map(true);
    }

}
d
