
#include "sfmlbutton.h"

// Button type 1
// Back and white simple button
SfmlButton::SfmlButton( std::string text, sf::Font* font, int text_size, sf::Vector2f size, sf::Vector2f top_left_position)
{
    _button_type = 1;

    this->_rect_shape_btn_size = size;
    this->_btn_position = top_left_position;

    this->_text_btn = text;
    this->_text_font = font;
    this->_text_size = text_size;

    this->build();
}

void SfmlButton::build()
{
    // Create font

    if (this->_button_type == 1)
    {
        this->_rect_shape_btn.setSize(this->_rect_shape_btn_size);
        this->_rect_shape_btn.setOutlineColor(sf::Color::Black);
        this->_rect_shape_btn.setFillColor(sf::Color::White);
        //this->_rect_shape_btn.setOrigin( sf::Vector2f( this->_rect_shape_btn_size.x / 2, this->_rect_shape_btn_size.y / 2 ) );
        this->_rect_shape_btn.setPosition(this->_btn_position);


        this->_sf_text_btn.setString(this->_text_btn);
        this->_sf_text_btn.setFont(*_text_font);


        this->_sf_text_btn.setPosition(sf::Vector2f(this->_btn_position.x, this->_btn_position.y));



        this->_sf_text_btn.setFillColor(sf::Color::Black);
        this->_sf_text_btn.setCharacterSize(this->_text_size);
        this->_rect_btn = sf::FloatRect(this->_btn_position, this->_rect_shape_btn_size);
    }
}

void SfmlButton::update()
{

    if( this->_rect_btn.contains( sf::Vector2f((float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y)) )
    {
        if ( sf::Mouse::isButtonPressed(sf::Mouse::Left) )
        {
            this->is_clicked = true;
        }
        else
        {
            this->is_clicked = false;
        }
    }
    else
    {
        this->is_clicked = false;
    }

}

void SfmlButton::draw(sf::RenderWindow* game_window)
{
    game_window->draw(this->_rect_shape_btn);
    game_window->draw(this->_sf_text_btn);
}
