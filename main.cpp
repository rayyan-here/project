#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"

enum class AppState { LOGIN, MENU, ADD, VIEW, EXIT };

bool authenticate(const std::string& username, const std::string& password) {
    return username == "admin" && password == "SecureMaster123!";
}

void showAddWindow(const sf::Font& font) {
    sf::RenderWindow window(sf::VideoMode(400, 300), "Add Account");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(20, 20, 20));
        // Add your Add Account fields here
        sf::Text txt("Add Account - [stub]", font, 20);
        txt.setPosition(50, 130);
        txt.setFillColor(sf::Color::White);
        window.draw(txt);
        window.display();
    }
}

void showPasswordWindow(const sf::Font& font) {
    sf::RenderWindow window(sf::VideoMode(400, 300), "View Passwords");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(20, 20, 20));
        // Add password view logic here
        sf::Text txt("Password List - [stub]", font, 20);
        txt.setPosition(50, 130);
        txt.setFillColor(sf::Color::White);
        window.draw(txt);
        window.display();
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 400), "Password Manager");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font.\n";
        return -1;
    }

    AppState state = AppState::LOGIN;
    std::string inputUsername, inputPassword;

    sf::Text loginMsg("Login - Username: admin, Password: SecureMaster123!", font, 18);
    loginMsg.setPosition(30, 30);
    loginMsg.setFillColor(sf::Color::White);

    Button loginBtn(200, 250, 200, 40, font, "Login");
    Button addBtn(200, 100, 200, 40, font, "Add Account");
    Button viewBtn(200, 160, 200, 40, font, "View Passwords");
    Button exitBtn(200, 220, 200, 40, font, "Exit");

    while (window.isOpen()) {
        sf::Event event;
        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (state == AppState::LOGIN && loginBtn.isClicked(mousePos)) {
                    inputUsername = "admin";   // mock input
                    inputPassword = "SecureMaster123!";
                    if (authenticate(inputUsername, inputPassword))
                        state = AppState::MENU;
                }

                else if (state == AppState::MENU) {
                    if (addBtn.isClicked(mousePos)) {
                        showAddWindow(font);
                    } else if (viewBtn.isClicked(mousePos)) {
                        showPasswordWindow(font);
                    } else if (exitBtn.isClicked(mousePos)) {
                        window.close();
                    }
                }
            }
        }

        window.clear(sf::Color(30, 30, 30));
        if (state == AppState::LOGIN) {
            window.draw(loginMsg);
            loginBtn.draw(window);
        } else if (state == AppState::MENU) {
            addBtn.draw(window);
            viewBtn.draw(window);
            exitBtn.draw(window);
        }
        window.display();
    }

    return 0;
}
