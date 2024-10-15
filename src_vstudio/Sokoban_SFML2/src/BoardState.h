
#ifndef BOARDSTATE_H
#define BOARDSTATE_H

#include <vector>

#include "Case.h"

class BoardState
{
private:
    std::vector< std::vector<Case> > tab_states;

    int nb_states;

public:
    BoardState();

    // Add state
    void save_state( std::vector<Case> map );

    // Get Number of states
    int get_numbers_of_states() { return tab_states.size(); };

    // Get last board state
    std::vector<Case> get_back();

    // Clean vector states
    void clean_states();
};

#endif // BOARDSTATE_H
