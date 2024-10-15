#include "score.h"

Score::Score( int lvl )
{
    lvl_number = lvl;
    nb_moves = 0;
}

void Score::add_one_move()
{
    nb_moves++;
}

void Score::reset()
{
    nb_moves = 0;
}
