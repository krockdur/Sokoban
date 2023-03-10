#include "Game.h"

Game::Game() {

	player = Player("Krock", 2, 2);
	map = Map(player.get_position());

}

void Game::init() {

}


void Game::loop() {

    while (Game::run){

        this->update();

        this->draw();

    }

}

void Game::update()
{
    char key_value = 'a';

    enum Direction{up, down, left, right};

    Direction direction;

    std::cout << "Move : ZQSD - Leave : W :";
    std::cin >> key_value;

    if (key_value == 'z')
        direction = up;

    if (key_value == 'q')
        direction = left;

    if (key_value == 's')
        direction = down;

    if (key_value == 'd')
        direction = right;

    if (key_value == 'w')
        this->run = false;

    // Maj


    switch(direction){
        case left:

            player.set_position(Case(player.get_position().get_x() - 1, player.get_position().get_y(), player.get_position().get_value()));

            break;

        case right:
            break;
/*
        case up:
            break;

        case down:
            break;

        default:
            break;*/
    }
}

void Game::draw()
{
      #ifdef WINDOWS
        system("cls");
        std::cout << "clear on windows" << std::endl;
      #endif
      #ifdef LINUX
        system("clear");
        std::cout << "clear on linux" << std::endl;
      #endif

    map.print_map();
}
