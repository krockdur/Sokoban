#ifndef CONFIG_H
#define CONFIG_H


class Config
{
    public:

        static const char c_wall_tile = '#';
        static const char c_box_tile = '$';
        static const char c_objective_tile = '.';
        static const char c_empty_tile = ' ';
        static const char c_player_tile = '@';
        static const char c_player_on_objective_tile = '+';
        static const char c_box_on_objective = '*';

        static const int NB_TILE_X = 20;
        static const int NB_TILE_Y = 20;

        static inline const float TILE_W = 32.0f;

};

#endif // CONFIG_H
