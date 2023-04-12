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

        static int NB_TILE_X;
        static int NB_TILE_Y;

        //static inline const float TILE_W = 32.0f;
        static const int TILE_W = 32;

        static const int TILE_MENU_W = 32;
        static const int SPACE_BETWEEN_TILE_MENU = 5;
        static const int TEXTURE_MENU_TITLE_W = 384;
        static const int TEXTURE_MENU_TITLE_H = 32;
        static const int TEXTURE_MENU_BTN_PLAY_W = 128;
        static const int TEXTURE_MENU_BTN_PLAY_H = 32;
        static const int TEXTURE_MENU_BTN_SCORE_W = 160;
        static const int TEXTURE_MENU_BTN_SCORE_H = 32;

        // scales
        static float GLOBAL_SCALE;

        static const int WINDOW_WIDTH = 1280;
        static const int WINDOW_HEIGHT = 768;

        static int CURRENT_WINDOW_WIDTH;
        static int CURRENT_WINDOW_HEIGHT;

        static float SCREEN_RATIO;

        static const int PLAYER_TIME_BETWEEN_TWO_MOVE = 75;
};



#endif // CONFIG_H
