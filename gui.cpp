#include<SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Password Manager", sf::Style::Titlebar | sf::Style::Close);
    sf::Color backgroundColor(30, 30, 30);

    sf::Font font;
    if (!font.loadFromFile("assets/arial.ttf"))
    {
        std::cout << "Error loading font!" << std::endl;
        return -1;
    }

    // Title
    sf::Text title("Password Manager", font, 40);
    title.setFillColor(sf::Color::White);
    title.setPosition(200, 30);

    // Username Text
    sf::Text usernameLabel("Username:", font, 24);
    usernameLabel.setFillColor(sf::Color::White);
    usernameLabel.setPosition(100, 150);

    // Password Text
    sf::Text passwordLabel("Password:", font, 24);
    passwordLabel.setFillColor(sf::Color::White);
    passwordLabel.setPosition(100, 220);

    // Username Input Box
    sf::RectangleShape usernameBox(sf::Vector2f(400, 40));
    usernameBox.setFillColor(sf::Color(50, 50, 50));
    usernameBox.setPosition(250, 150);

    // Password Input Box
    sf::RectangleShape passwordBox(sf::Vector2f(400, 40));
    passwordBox.setFillColor(sf::Color(50, 50, 50));
    passwordBox.setPosition(250, 220);

    // Input Texts
    sf::Text usernameText("", font, 24);
    usernameText.setFillColor(sf::Color::White);
    usernameText.setPosition(260, 155);

    sf::Text passwordText("", font, 24);
    passwordText.setFillColor(sf::Color::White);
    passwordText.setPosition(260, 225);

    // Buttons
    sf::RectangleShape loginButton(sf::Vector2f(200, 50));
    loginButton.setFillColor(sf::Color(70, 70, 70));
    loginButton.setPosition(150, 320);

    sf::Text loginText("Login", font, 28);
    loginText.setFillColor(sf::Color::White);
    loginText.setPosition(220, 325);

    sf::RectangleShape createButton(sf::Vector2f(200, 50));
    createButton.setFillColor(sf::Color(70, 70, 70));
    createButton.setPosition(450, 320);

    sf::Text createText("Create Account", font, 24);
    createText.setFillColor(sf::Color::White);
    createText.setPosition(460, 330);

    // Input focus tracking
    bool typingUsername = false, typingPassword = false;
    std::string usernameInput = "", passwordInput = "";

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed)
        window.close();

    // Handle mouse click for focus + button press
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        // Focus handling
        if (usernameBox.getGlobalBounds().contains(mousePos)) {
            typingUsername = true;
            typingPassword = false;
        } else if (passwordBox.getGlobalBounds().contains(mousePos)) {
            typingUsername = false;
            typingPassword = true;
        } else {
            typingUsername = typingPassword = false;
        }

        // Login button click
        if (loginButton.getGlobalBounds().contains(mousePos)) {
            std::cout << "Login Clicked\n";
            std::cout << "Username: " << usernameInput << " | Password: " << passwordInput << std::endl;
            // here you can later call your OOP function like:
            // userManager.login(usernameInput, passwordInput);
        }

        // Create Account button click
        if (createButton.getGlobalBounds().contains(mousePos)) {
            std::cout << "Create Account Clicked\n";
            std::cout << "Username: " << usernameInput << " | Password: " << passwordInput << std::endl;
            // here you can later call your OOP function like:
            // userManager.createAccount(usernameInput, passwordInput);
        }
    }

    // Handle text input
    if (event.type == sf::Event::TextEntered) {
        if (typingUsername) {
            if (event.text.unicode == 8 && !usernameInput.empty()) { // backspace
                usernameInput.pop_back();
            } else if (event.text.unicode < 128 && event.text.unicode != 8) {
                usernameInput += static_cast<char>(event.text.unicode);
            }
            usernameText.setString(usernameInput);
        }
        if (typingPassword) {
            if (event.text.unicode == 8 && !passwordInput.empty()) { // backspace
                passwordInput.pop_back();
            } else if (event.text.unicode < 128 && event.text.unicode != 8) {
                passwordInput += static_cast<char>(event.text.unicode);
            }
            passwordText.setString(std::string(passwordInput.length(), '*'));
        }
    }
}


        // Draw window
        window.clear(backgroundColor);
        window.draw(title);
        window.draw(usernameLabel);
        window.draw(passwordLabel);
        window.draw(usernameBox);
        window.draw(passwordBox);
        window.draw(usernameText);
        window.draw(passwordText);
        window.draw(loginButton);
        window.draw(loginText);
        window.draw(createButton);
        window.draw(createText);
        window.display();
    }

    return 0;
}
