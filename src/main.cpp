#include <iostream>
#include <stdlib.h>
#include "Game.h"

int main()
{

    char * toto;

    toto = (char *)malloc(5);

    toto = "abaa";

    //toto[1] = 'c';
/*
    if (toto == "acaa"){
        std::cout << "test";
    }
*/
    free(toto);
/*

	Game game;
	game.init();
	game.loop();


*/
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
