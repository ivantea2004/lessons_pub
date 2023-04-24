#include"root.h"

int first_derivative_sign(differentiable_function_t f, differentiable_function_t g, float a, float b)
{
    float y1 = f.function(a) - g.function(a), y2 = f.function(b) - g.function(b);
    if(y1 < y2)
        return 1;
    else if(y1 > y2)
        return -1;
    else
        return 0;
}

int second_derivative_sign(differentiable_function_t f, differentiable_function_t g, float a, float b)
{
    float m = (a + b) / 2;
    float y1 = f.function(a) - g.function(a), y2 = f.function(m) - g.function(m), y3 = f.function(b) - g.function(b);
    float y4 = (y1 + y3) / 2;
    if(y2 > y4)
        return -1;
    else if(y2 < y4)
        return 1;
    else
        return 0;
}

float root(differentiable_function_t f, differentiable_function_t g, float a, float b, float eps, int*steps)
{
    if(steps)
        *steps = 0;

    float c = (a + b) / 2;

    int s = first_derivative_sign(f, g, a, b);

    while(1)
    {
        float y = f.function(c) - g.function(c);
        if(s > 0)
        {
            if(y < 0)
                a = c;
            else
                b = c;
        }
        else
        {
            if(y < 0)
                b = c;
            else
                a = c;
        }
        c = (a + b) / 2;

        (*steps)++;

        if(b - a < eps)
            return c;

    }
}
