#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <vector>
#include<fstream>
#include<string>

#include "egine.h"
#include "drawing.h"
#include "game_scene.h"
#include "openning_scene.h"
#include "change_scene.h"
#include "menu_scene.h"

using namespace sf;
using namespace std;
double all_time = 0;
double elapsed_time;

int main()
{

    change_scene(0);

    RenderWindow window(sf::VideoMode(820, 920),"2048 - Balls",  Style::None );
    int bestscr;

    Clock clock;
    fstream file;
    string highs;
    file.open("highscore", ios::in);
    if(!file.good()) bestscr = 0;
    else{
        getline(file, highs);
        bestscr = stoi(highs);
    }
    file.close();


    while (window.isOpen())
    {
        window.clear(Color(182, 92, 0));

        elapsed_time = clock.getElapsedTime().asMicroseconds();
        //cout << elapsed_time << endl;
        clock.restart();
        all_time += elapsed_time/1e6;
        elapsed_time/=7e5*0.6;
        elapsed_time = (elapsed_time > 0.5)?0.5:elapsed_time;
        // cout<<get_still()<<"\n";

        Vector2i pixelPos = Mouse::getPosition(window);
        Vector2f pos = window.mapPixelToCoords(pixelPos);

        if (get_still() == 0) still_oppening(&window,1.5*all_time);
        if (get_still() == 1) {
            bestscr = max(bestscr, still_game(&window, bestscr));
            //cout << bestscr << endl;
        }
        if (get_still() == 2) still_menu(&window);

        window.display();
    }
    file.open("highscore", ios::out | ios::trunc);
    file << bestscr;
    file.close();

    return 0;
}
