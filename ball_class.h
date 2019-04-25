#ifndef BALL_CLASS_H_INCLUDED
#define BALL_CLASS_H_INCLUDED
extern double all_time;
extern double elapsed_time;

class Ball
{
private:
    static double constexpr grow_time = 0.05;
public:
    float p;
    float x, y, ux, uy;
    int num;
    int st;
    bool del = 0;
    double created;
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
        this -> created = all_time;
        p = 60 +  num*13;
    }
    void adj_size() {
        if (all_time - created > grow_time) {
            p = 60 + num * 13;
        }
        else{
            p = 60 + (all_time - created)/grow_time * num* 13;
        }
    }


    void app()
    {
        x += ux*elapsed_time;
        y += uy*elapsed_time;

        if (y > 800 - p) {uy *= -1; y = 800 - p;}
        if (y <  p)      {uy *= -1; y =  p;}
        if (x <  p)      {ux *= -1; x = p;}
        if (x > 800 - p) {ux *= -1; x = 800 - p;}
    }

    void low2( float fx, float fy)
    {
        //cout << elapsed_time << endl;
        ux += fx*elapsed_time;
        uy += fy*elapsed_time;
    }
};



#endif // BALL_CLASS_H_INCLUDED
