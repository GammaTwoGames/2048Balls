#ifndef OPENNING_SCENE_H_INCLUDED
#define OPENNING_SCENE_H_INCLUDED

#include "change_scene.h"


void still_oppening(RenderWindow* window, float a_time)
{
    drawing_button(window, button_zero(410-10,460-10,20,20,"Hello, Master!", 100), (int)(85.0*a_time));
    window->setMouseCursorVisible(0);
    if (a_time > 3) change_scene(2);
}


#endif // OPENNING_SCENE_H_INCLUDED
