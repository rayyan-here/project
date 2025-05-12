#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;

public:
    Button(float x, float y, float width, float height, const sf::Font& font, const std::string& label) {
        shape.setPosition(x, y);
        shape.setSize({ width, height });
        shape.setFillColor(sf::Color(50, 50, 50));

        text.setFont(font);
        text.setString(label);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);
        sf::FloatRect bounds = text.getLocalBounds();
        text.setPosition(x + (width - bounds.width) / 2 - 5, y + (height - bounds.height) / 2 - 10);
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(shape);
        window.draw(text);
    }

    bool isClicked(sf::Vector2f mousePos) const {
        return shape.getGlobalBounds().contains(mousePos);
    }
};

#endif
