#ifndef MENU_SCENE_H_INCLUDED
#define MENU_SCENE_H_INCLUDED

class MenuScene {
public:
    MenuScene();
    int show(sf::RenderWindow *window, MyDraw *draw);

private:
    Button startButton;
    Button exitButton;
};

MenuScene::MenuScene() : startButton(410 - 200, 390 - 70, 400, 140, "START", 100),
                         exitButton(410 - 200, 530 - 70, 400, 140, "EXIT", 100) {}

/**
 * Call on every step to show
 * @param window sf::RenderWindow
 * @param draw implementation of MyDraw
 * @return the id of the next scene to show
 */
int MenuScene::show(sf::RenderWindow *window, MyDraw *draw) {
    sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
    sf::Vector2f pos = window->mapPixelToCoords(pixelPos);
    draw->drawButton(startButton, pos.x, pos.y);
    draw->drawButton(exitButton, pos.x, pos.y);

    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) window->close();
        if (event.type == sf::Event::MouseButtonPressed)
            if (event.key.code == sf::Mouse::Left) {
                if (startButton.is_in(pos.x, pos.y)) {
                    return scn::GAME;
                }
                if (exitButton.is_in(pos.x, pos.y)) {
                    window->close();
                }
            }
    }
    return scn::MENU;
}

#endif // MENU_SCENE_H_INCLUDED
