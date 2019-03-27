#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <vector>

#include "egine.h"
#include "drawing.h"
#include "game_scene.h"
#include "openning_scene.h"
#include "change_scene.h"
#include "menu_scene.h"

int main() {

    change_scene(0);

    sf::RenderWindow window(sf::VideoMode(820, 920), "2048 - Balls", sf::Style::None);

    sf::Clock clock;

    float all_time = 0;

    while (window.isOpen()) {
        window.clear(sf::Color(182, 92, 0));

        double time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        all_time += time / 1e6;
        time = time / 1.8e5 * 0.6;
        time = (time > 0.5) ? 0.5 : time;
        std::cout << get_still() << "\n";

        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        sf::Vector2f pos = window.mapPixelToCoords(pixelPos);

        if (get_still() == 0) still_oppening(&window, time, 1.5 * all_time);
        if (get_still() == 1) still_game(&window, time);
        if (get_still() == 2) still_menu(&window);

        window.display();
    }
    return 0;
}
