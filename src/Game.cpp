#include "Game.h"

Game::Game() {

}

void Game::init() {
	player = Player("Krock", 2, 2);
	map = Map(player);
}


void Game::loop() {

    while (Game::run){

        sf::Time elapsed_time = Clock.getElapsedTime();


        if (elapsed_time.asMilliseconds() >= TIME_BETWEEN_FRAME){
            this->update();

            this->draw();
            Clock.restart();
            std::cout << elapsed_time.asMicroseconds() << std::endl;
        }

    }

}

bool moved = false;
void Game::update()
{

    enum Direction{up, down, left, right, none};

    Direction direction;
    direction = none;
    
    // Autoriser le déplacement
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) ){
        moved = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        direction = up;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        direction = left;
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        direction = down;
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        direction = right;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->run = false;
        direction = none;
    }

    Context context = map.get_case_context(player.get_position());


    if (!moved){
        switch(direction){
            case left:
                if(context.l1 == Config::c_empty_tile){
                    player.set_position(Case(player.get_position().get_x() - 1, player.get_position().get_y(), player.get_position().get_value()));
                    moved = true;
                }
                else if (context.l1 == Config::c_wall_tile){
                }

                break;

            case right:
                if(context.r1 == Config::c_empty_tile){
                    player.set_position(Case(player.get_position().get_x() + 1, player.get_position().get_y(), player.get_position().get_value()));
                    moved = true;
                }
                else if (context.r1 == Config::c_wall_tile){

                }
                break;

            case up:
                if(context.t1 == Config::c_empty_tile){
                    player.set_position(Case(player.get_position().get_x(), player.get_position().get_y() - 1, player.get_position().get_value()));
                    moved = true;
                }
                break;

            case down:
                if(context.b1 == Config::c_empty_tile){
                    player.set_position(Case(player.get_position().get_x(), player.get_position().get_y() + 1, player.get_position().get_value()));
                    moved = true;
                }
                break;

            default:
                break;
        }
    }



    map.update_player_pos_in_map(player);

}   

void Game::draw()
{
    #ifdef WINDOWS
    system("cls");
    #endif
    #ifdef LINUX
    system("clear");
    #endif

    map.print_map();

    debug(map.get_case_context(player.get_position()));
}

void Game::debug(Context c){
    std::cout << "    " << c.t2 << std::endl;
    std::cout << "    " << c.t1 << std::endl;
    std::cout <<   c.l2   <<   c.l1   << "[   ]" <<   c.r1   <<   c.r2   << std::endl;
    std::cout << "    " <<  c.b1   << std::endl;
    std::cout << "    " <<  c.b2   << std::endl;
}
