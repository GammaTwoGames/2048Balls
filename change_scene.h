#ifndef CHANGE_SCENE_H_INCLUDED
#define CHANGE_SCENE_H_INCLUDED

#include "game_scene.h"

int still;

void change_scene(int scene) {
    if (scene == 0) { still = 0; }
    if (scene == 1) { still = 1; /*game_start();*/}
    if (scene == 2) { still = 2; /*game_start();*/}
}

int get_still() {
    return still;
}

#endif // CHANGE_SCENE_H_INCLUDED
