
#include "boardstate.h"

BoardState::BoardState()
{
    nb_states = 0;
}

void BoardState::save_state( std::vector<Case> map)
{
    tab_states.push_back(map);
    nb_states++;
}

std::vector<Case> BoardState::get_back()
{
    std::vector<Case> vc_ret;

    if (tab_states.size() > 1)
    {
        // store last state
        vc_ret = tab_states[tab_states.size() - 2];
        // remove last state
        tab_states.pop_back();

        // adjust nb states
        nb_states--;
    }
    else
    {
        std::vector<Case> vc_ret = tab_states[0];
    }

    // return
    return vc_ret;

}

void BoardState::clean_states()
{
    tab_states.clear();
}
