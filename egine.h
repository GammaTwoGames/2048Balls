#ifndef EGINE_H_INCLUDED
#define EGINE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace sf;
using namespace std;

#include "ball_class.h"

int lose = 0;

void app_phys(vector<Ball>* balls, float GG, float G)
{
    float s1,s2;
        for(int k = 0; k < 3; k ++)
        {
            for (int i = 0; i < balls->size(); i ++)
            {
                (*balls)[i].app();
                (*balls)[i].low2(GG  - ((*balls)[i].ux)/3, G - ((*balls)[i].uy)/3);
            }
            for (int i = 0; i < balls->size(); i ++)
                for (int j = 0; j < balls->size(); j ++)
                {
                    if (i != j)
                    {
                        s1 = (((*balls)[i].x - (*balls)[j].x)*((*balls)[i].x - (*balls)[j].x) + ((*balls)[i].y - (*balls)[j].y)*((*balls)[i].y - (*balls)[j].y));
                        s2 = ((*balls)[i].p + (*balls)[j].p)*((*balls)[i].p + (*balls)[j].p);
                        if (s1 < s2)
                        {
                            (*balls)[i].low2((s2 - s1)*((*balls)[i].x - (*balls)[j].x)/5e3, (s2 - s1)*((*balls)[i].y - (*balls)[j].y)/5e3);
                        }
                    }
                }
        }
}

void analise_map(vector<Ball>* balls)
    {
        float s1,s2;
        float xnew, ynew, ne = 0, stnew;
        for (int i = 0; i < (*balls).size(); i ++)
                for (int j = 0; j < (*balls).size(); j ++)
                {
                    if (i != j)
                    {
                        s1 = (((*balls)[i].x - (*balls)[j].x)*((*balls)[i].x - (*balls)[j].x) + ((*balls)[i].y - (*balls)[j].y)*((*balls)[i].y - (*balls)[j].y));
                        s2 = ((*balls)[i].p + (*balls)[j].p)*((*balls)[i].p + (*balls)[j].p);
                        if ((s1 < s2) && ((*balls)[i].st == (*balls)[j].st))
                        {
                            (*balls)[i].del = 1;
                            (*balls)[j].del = 1;
                            xnew = ((*balls)[i].x + (*balls)[j].x)/2;
                            ynew = ((*balls)[i].y + (*balls)[j].y)/2;
                            stnew = (*balls)[i].num + 1;
                            ne = 1;
                        }
                    }
                }

        for (int i = 0; i < (*balls).size(); i ++)
        {
            if ((*balls)[i].del == 1)
            {
                (*balls).erase((*balls).begin() + i);
                i = (*balls).size() + 1;
            }
        }

        for (int i = 0; i < (*balls).size(); i ++)
        {
            if ((*balls)[i].del == 1)
            {
                (*balls).erase((*balls).begin() + i);
                i = (*balls).size() + 1;
            }
        }

        if (ne == 1)
        {
            (*balls).push_back(Ball(xnew,ynew, stnew));
        }
    }

class vect
{
public:
    int x, y;
    vect(int X, int Y)
    {
        x = X;
        y = Y;
    }
};

int smart_push_ball(vector<Ball>* balls)
{
    int ran;
    int n1, d1, n2, d2;
    n1 = 73; d1 = 10;
    n2 = 73; d2 = 10;

    vector<vect> vects;


    float s1,s2;
        int xp = 0, yp = 0;
        for (int i = n1; i < 800- n1; i += d1)
            for (int j = n2; j < 800 - n2; j += d2)
            {
                xp = 0;
                for (int k = 0; k < (*balls).size(); k ++)
                {
                    s1 = ((*balls)[k].x - i)*((*balls)[k].x - i) + ((*balls)[k].y - j)*((*balls)[k].y - j);
                    s2 = ((*balls)[k].p + 70)*((*balls)[k].p + 70);
                    if (s2 > s1) xp = - 1;
                }
                if (xp == 0)
                {
                    vects.push_back(vect(i,j));
                }
            }
    if (vects.size() != 0)
    {
        ran = rand()%vects.size();
        int sz = (rand()%2 + 1);
        (*balls).push_back(Ball(vects[ran].x,vects[ran].y,sz));
        return sz * 2;
    }
    else
    {
        lose = 1;
        return 0;
    }
}

void create_first_balls(vector<Ball>* balls)
{
    balls->clear();
    for (int i = 1; i < 6; i ++)
    {
        balls->push_back(Ball(rand()%600 + 100,rand()%600 + 100,i));
    }
}

int get_lose()
{
    return lose;
}

void set_lose()
{
    lose = 0;
}

int score(vector<Ball>* balls)
{
    int ret = 0;
    for (int i = 0; i < (*balls).size(); i ++)
    {
        ret += (*balls)[i].st;
    }
    return ret;
}


#endif // EGINE_H_INCLUDED
