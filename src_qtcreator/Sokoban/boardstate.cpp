
#include "boardstate.h"

BoardState::BoardState()
{

}

void BoardState::save_state( std::vector<Case> map)
{
    tab_states.push_back(map);
}

void BoardState::clean_states()
{
    tab_states.clear();
}
