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

        //static inline const float TILE_W = 32.0f;
        static const int TILE_W = 32;

        static const int TILE_MENU_W = 32;

        // scales
        static const float GLOBAL_SCALE;
        static const float MENU_TITLE_SCALE;
        static const float MENU_LVL_GRID_SCALE;
        static const float MENU_BTN_PLAY_SCALE;
        static const float MENU_BTN_SCORE_SCALE;

        static const int WINDOW_WIDTH = 1280;
        static const int WINDOW_HEIGHT = 768;

        static const int PLAYER_TIME_BETWEEN_TWO_MOVE = 75;
};



#endif // CONFIG_H
