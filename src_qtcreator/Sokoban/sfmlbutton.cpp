
#include "sfmlbutton.h"

// Button type 1
// Back and white simple button
SfmlButton::SfmlButton( std::string text, sf::Vector2f size, sf::Vector2f center_position)
{
    _button_type = 1;

    this->_text_btn = text;
    this->_rect_shape_btn_size = size;
    this->_btn_position = center_position;

    this->build();
}

void SfmlButton::build()
{
    if (this->_button_type == 1)
    {
        this->_rect_shape_btn.setSize(this->_rect_shape_btn_size);
        this->_rect_shape_btn.setOutlineColor(sf::Color::Black);
        this->_rect_shape_btn.setFillColor(sf::Color::White);
        this->_rect_shape_btn.setOrigin( sf::Vector2f( this->_rect_shape_btn_size.x / 2, this->_rect_shape_btn_size.y / 2 ) );
        this->_rect_shape_btn.setPosition(this->_btn_position);


        this->_rect_btn = sf::FloatRect(this->_btn_position, this->_rect_shape_btn_size);
    }
}

void SfmlButton::update()
{
    if( this->_rect_btn.contains( sf::Vector2f((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y)))
    {
        this->is_clicked = true;
    }
    else
    {
        this->is_clicked = false;
    }
}

void SfmlButton::draw(sf::RenderWindow* game_window)
{
    game_window->draw(this->_rect_shape_btn);
}
