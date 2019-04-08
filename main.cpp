#include "Controller/Game.h"

/**
 * Readme
 * All code is split into 3 main groups:
 *      - Model is a physics engine
 *      - View is drawing
 *      - Controller is the main part that connects Model & View together and manage scenes.
 * All ..Scene.h classes work in the same way: show must be call every step and it returns the next scene to show
 */
int main() {
    Game game;
    game.run();
    return 0;
}
