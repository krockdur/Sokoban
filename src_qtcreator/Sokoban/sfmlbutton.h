
#ifndef SFMLBUTTON_H
#define SFMLBUTTON_H


#include <SFML/Graphics.hpp>
#include <iostream>


class SfmlButton
{
private:

    sf::Vector2f _btn_position;
    float _btn_scale;
    int _button_type;

    //-----------------------------------
    // RECTANGE DEFINITION
    sf::RectangleShape _rect_shape_btn;
    sf::Vector2f _rect_shape_btn_size;
    sf::Color _rect_shape_outline_color;
    float _rect_shape_outline_thickness;
    sf::Color _rect_shape_fill_color;
    sf::Vector2f _rect_shape_position;

    // RECTANGLE OVER DEFINITION
    sf::Color _rect_shape_outline_color_over;
    sf::Color _rect_shape_fill_color_over;


    //-----------------------------------
    // TEXT DEFINITION
    std::string _text_btn;
    sf::Vector2f _text_position;
    int _text_size;
    sf::Color _text_color;
    std::string _text_value;

    // TEXT DEFINITION
    sf::Color _text_color_over;
    std::string _text_value_over;

    //-----------------------------------
    // RECT DEFINITION
    sf::FloatRect _rect_btn;


    //-----------------------------------
    // LIFE DEFINITION
    void build();
    bool is_clicked;


public:
    SfmlButton() = default;
    SfmlButton(
        std::string text,
        sf::Vector2f size,
        sf::Vector2f center_position
        );

    void update();
    void draw(sf::RenderWindow* game_window);
    bool get_clicked(){ return this->is_clicked; };
};

#endif // SFMLBUTTON_H
