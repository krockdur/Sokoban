/*
 * Player.cpp
 *
 *  Created on: 6 mars 2023
 *      Author: a430885
 */

#include "Player.h"


bool Player::check_collision(std::string direction)
{
    bool collision = false;

    int next_case_x = current_case_x;
    int next_case_y = current_case_y;

    if (direction == "up")
    {
        next_case_y -= 1;
    }
    else if (direction == "left")
    {
        next_case_x -= 1;
    }
    else if (direction == "right")
    {
        next_case_x += 1;
    }
    else if (direction == "down")
    {
        next_case_y += 1;
    }

    if (Map::get_case_value(next_case_x, next_case_y) == 1 || Map::get_case_value(next_case_x, next_case_y) == 4)
    {
        collision = true;
    }

    return collision;

}

int Player::check_movable_object(std::string direction)
{
    int object_collision = 0;

    int next_case_x = current_case_x;
    int next_case_y = current_case_y;

    if (direction == "up")
    {
        next_case_y -= 1;
    }
    else if (direction == "left")
    {
        next_case_x -= 1;
    }
    else if (direction == "right")
    {
        next_case_x += 1;
    }
    else if (direction == "down")
    {
        next_case_y += 1;
    }

    if (Map::get_case_value(next_case_x, next_case_y) == 3 || Map::get_case_value(next_case_x, next_case_y) == 5)
    {
        object_collision = Map::get_case_value(next_case_x, next_case_y);
    }

    return object_collision;
}



Player::Player(int init_case_x, int init_case_y)
{
    current_case_x = init_case_x;
    current_case_y = init_case_y;
}

bool Player::move_player(std::string direction)
{
    // Si mouvement pr�par� pas de collision avec un m�r
    if (!check_collision(direction))
    {
        // Si mouvement pr�par� pas en collision avec un objet d�placable
        if (check_movable_object(direction) == 0)
        {
            // On d�place le player � la nouvelle position
            if (direction == "up")
            {
                current_case_y -= 1;
            }
            else if (direction == "left")
            {
                current_case_x -= 1;
            }
            else if (direction == "right")
            {
                current_case_x += 1;
            }
            else if (direction == "down")
            {
                current_case_y += 1;
            }
            Map::set_player_position(current_case_x, current_case_y);
        }
        else
        {
            // V�rifier que l'objet peut �tre d�placer quand le player le "pousse"
            int object_case_x = 0;
            int object_case_y = 0;

            // Nouvelle position du player si le mouvement est possible
            int new_player_case_x = 0;
            int new_player_case_y = 0;

            bool object_movable = false;
            if (direction == "up")
            {
                object_case_x = current_case_x; object_case_y = current_case_y - 1;

                // si dans la direction o� l'objet est pouss�, la case est vide alors
                if (Map::get_case_value(object_case_x, object_case_y - 1) == 0 || Map::get_case_value(object_case_x, object_case_y - 1) == 4)
                {
                    object_movable = true;
                }
            }
            else if (direction == "down")
            {
                object_case_x = current_case_x; object_case_y = current_case_y + 1;

                // si dans la direction o� l'objet est pouss�, la case est vide alors
                if (Map::get_case_value(object_case_x, object_case_y + 1) == 0 || Map::get_case_value(object_case_x, object_case_y + 1) == 4)
                {
                    object_movable = true;
                }
            }
            else if (direction == "left")
            {
                object_case_x = current_case_x - 1; object_case_y = current_case_y;

                // si dans la direction o� l'objet est pouss�, la case est vide alors
                if (Map::get_case_value(object_case_x - 1, object_case_y) == 0 || Map::get_case_value(object_case_x - 1, object_case_y) == 4)
                {
                    object_movable = true;
                }
            }
            else if (direction == "right")
            {
                object_case_x = current_case_x + 1; object_case_y = current_case_y;

                // si dans la direction o� l'objet est pouss�, la case est vide alors
                int next_case_value = Map::get_case_value(object_case_x + 1, object_case_y);
                if (next_case_value == 0 || next_case_value == 4)
                {
                    object_movable = true;
                }
            }

            // Si d�placement objet possible -> on bouge l'objet puis le player
            if (object_movable)
            {
                Map::move_object(object_case_x, object_case_y, direction);

                // Maj position player
                current_case_x = object_case_x;
                current_case_y = object_case_y;
                Map::set_player_position(current_case_x, current_case_y);
            }
        }
    }

    return false;
}

/*
* Retourne la valeur de la prochaine case
*/
int Player::check_next_case(std::string direction)
{
    int object_collision = 0;

    int next_case_x = current_case_x;
    int next_case_y = current_case_y;

    if (direction == "up")
    {
        next_case_y -= 1;
    }
    else if (direction == "left")
    {
        next_case_x -= 1;
    }
    else if (direction == "right")
    {
        next_case_x += 1;
    }
    else if (direction == "down")
    {
        next_case_y += 1;
    }


    object_collision = Map::get_case_value(next_case_x, next_case_y);


    return object_collision;
}

void Player::player_organizer(std::string direction)
{
    switch (check_next_case(direction))
    {
    case 0:
        this->new_move_player(direction);
        break;
    case 1:
        break;
    case 2:

        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    default:
        break;
    }
}

/*
* D�placement du joueur
*/
void Player::new_move_player(std::string direction)
{
    if (direction == "up")
    {
        current_case_y -= 1;
    }
    else if (direction == "left")
    {
        current_case_x -= 1;
    }
    else if (direction == "right")
    {
        current_case_x += 1;
    }
    else if (direction == "down")
    {
        current_case_y += 1;
    }
    Map::set_player_position(current_case_x, current_case_y);
}

void Player::player_collide_3(std::string direction)
{
    // Obtenir la valeur de la case suivante � la case en collision
    int next_case_x = current_case_x;
    int next_case_y = current_case_y;
    int after_next_case_x = current_case_x;
    int after_next_case_y = current_case_y;

    if (direction == "up")
    {
        next_case_y -= 1;
        after_next_case_y -= 2;
    }
    else if (direction == "left")
    {
        next_case_x -= 1;
        after_next_case_x -= 2;
    }
    else if (direction == "right")
    {
        next_case_x += 1;
        after_next_case_x += 2;
    }
    else if (direction == "down")
    {
        next_case_y += 1;
        after_next_case_y += 2;
    }

    int after_next_case_value = Map::get_case_value(after_next_case_x, after_next_case_y);

    switch (after_next_case_value)
    {
    case 0:
        Map::move_object(next_case_x, next_case_y, direction);
        break;
    case 1:
        break;
    case 4:
        break;
    case 5:
        break;
    }
}

void Player::player_collide_4(std::string direction)
{
}

void Player::player_collide_5(std::string direction)
{
}
