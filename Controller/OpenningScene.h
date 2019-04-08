#ifndef OPENNING_SCENE_H_INCLUDED
#define OPENNING_SCENE_H_INCLUDED

#include "scn.h"

class OpeningScene {
public:
    OpeningScene();
    int show(sf::RenderWindow *window, MyDraw *draw, double totalTime);

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
int OpeningScene::show(sf::RenderWindow *window, MyDraw *draw, double totalTime) {
    draw->drawLabel(label, (int) (85.0 * totalTime));
    window->setMouseCursorVisible(false);
    if (totalTime > 3) {
        window->setMouseCursorVisible(true);
        return scn::MENU;
    }
    return scn::OPENING;
}

#endif // OPENNING_SCENE_H_INCLUDED
