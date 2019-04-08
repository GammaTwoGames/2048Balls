#ifndef OPENNING_SCENE_H_INCLUDED
#define OPENNING_SCENE_H_INCLUDED

#include "scn.h"

class OpeningScene {
public:
    OpeningScene();
    int show(sf::RenderWindow *window, MyDraw *draw, double all_time);

private:
    Label label;
};

OpeningScene::OpeningScene() : label(410 - 10, 460 - 10, 20, 20, "Hello, Master!", 100) {}

/**
 * Call on every step to show
 * @param window sf::RenderWindow
 * @param draw implementation of MyDraw
 * @return the id of the next scene to show
 */
int OpeningScene::show(sf::RenderWindow *window, MyDraw *draw, double all_time) {
    draw->drawButton(label, (int) (85.0 * all_time));
    window->setMouseCursorVisible(false);
    if (all_time > 3) {
        window->setMouseCursorVisible(true);
        return scn::MENU;
    }
    return scn::OPENING;
}

#endif // OPENNING_SCENE_H_INCLUDED
