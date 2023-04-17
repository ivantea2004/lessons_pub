#include"root.h"

float root(func_t f, func_t g, float a, float b, float eps, int*steps)
{
    if(steps)
        *steps = 0;

    float c = (a + b) / 2;

    int N = 100;

    for(int i = 0; i < N; i++)
    {
        float y = f(c) - g(c);
        if(y < 0)
        {
            a = c;
        }
        else
        {
            b = c;
        }
        c = (a + b) / 2;
    }

    return c;
}
