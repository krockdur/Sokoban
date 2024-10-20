#ifndef SCORE_H
#define SCORE_H

#include <iostream>

class Score
{
private:
    int lvl_number;
    int nb_moves;
    std::string player;
public:
    Score() = default;
    Score( int lvl );
    void add_one_move();
    int get_score() { return nb_moves; };
    void set_player_name( std::string name );
    void set_lvl_number( int lvl_number ) { this->lvl_number = lvl_number; };
    void save_to_file();
    void reset();
};

#endif // SCORE_H
