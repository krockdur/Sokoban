#include <iostream>
#include <stdlib.h>

#include "ScreenManager.h"

int main()
{
    /*
    Game game;
    game.init();
    game.loop();
    */

    ScreenManager sm;

    sm.init();
    sm.run();
    
    return 0;
}