#include <SFML/Graphics.hpp>
#include <fstream>

#include "arial.ttf.hpp"

int main() {
    std::ofstream error_log("errors.log");
    sf::err().rdbuf(error_log.rdbuf());

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Clock", sf::Style::Fullscreen);
    window.setFramerateLimit(10);

    sf::Font font;
    if(!font.loadFromMemory(ARIAL_TTF, ARIAL_TTF_len)) {
        return 1;
    }

    sf::Text text("00:00:00", font, 250);
    text.setFillColor(sf::Color::White);
    sf::FloatRect text_bounds = text.getGlobalBounds();
    text.setPosition(window.getSize().x / 2 - text_bounds.width / 2, window.getSize().y / 2 - text_bounds.height / 2);
    
    char clock[9];
    time_t raw;
    
    sf::Event event;
    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if(window.hasFocus()) {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                window.close();
            } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                text.setFillColor(sf::Color::White);
            } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Y)) {
                text.setFillColor(sf::Color::Yellow);
            } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B)) {
                text.setFillColor(sf::Color::Blue);
            } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
                text.setFillColor(sf::Color::Red);
            } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G)) {
                text.setFillColor(sf::Color::Green);
            } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C)) {
                text.setFillColor(sf::Color::Cyan);
            } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M)) {
                text.setFillColor(sf::Color::Magenta);
            }
        }

        raw = time(nullptr);
        strftime(clock, sizeof(clock), "%H:%M:%S", localtime(&raw));
        text.setString(clock);

        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
    }
    return 0;
}