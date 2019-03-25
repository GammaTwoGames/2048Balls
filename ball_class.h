#ifndef BALL_CLASS_H_INCLUDED
#define BALL_CLASS_H_INCLUDED


class Ball
{
private:
public:
    float p;
    float x, y, ux, uy;
    int num;
    int st;
    bool del = 0;

    Ball(float _x,float _y, int _num)
    {
        x = _x;
        y = _y;
        ux = 0;
        uy = 0;
        num = _num;
        st = 1;
        for (int i = 0; i < num; i ++)
        {
            st*=2;
        }
        p = 60 +  num*13;
    }

    void app(float time)
    {
        x += ux*time;
        y += uy*time;

        if (y > 800 - p) {uy *= -1; y = 800 - p;}
        if (y <  p)      {uy *= -1; y =  p;}
        if (x <  p)      {ux *= -1; x = p;}
        if (x > 800 - p) {ux *= -1; x = 800 - p;}
    }

    void low2(float time, float fx, float fy)
    {
        ux += fx*time;
        uy += fy*time;
    }
};



#endif // BALL_CLASS_H_INCLUDED
