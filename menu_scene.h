#ifndef MENU_SCENE_H_INCLUDED
#define MENU_SCENE_H_INCLUDED

#include "change_scene.h"

void still_menu(RenderWindow* window)
{
    Vector2i pixelPos = Mouse::getPosition(*window);
    Vector2f pos = window->mapPixelToCoords(pixelPos);
    drawing_button(window, button_active(410-200,390-70,400,140,"START", 100), pos.x, pos.y);
    drawing_button(window, button_active(410-200,530-70,400,140,"EXIT", 100), pos.x, pos.y);

    sf::Event event;
    while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window->close();
            if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
                if (event.key.code == Mouse::Left)//а именно левая
                {
                    if (button_active(410-200,390-70,400,140,"START", 100).is_in(pos.x, pos.y))
                    {
                        //window->close();
                        game_start();
                        change_scene(1);
                    }
                    if (button_active(410-200,530-70,400,140,"START", 100).is_in(pos.x, pos.y))
                    {
                        window->close();
                    }
                }
        }
    window->setMouseCursorVisible(1);
}

#endif // MENU_SCENE_H_INCLUDED
