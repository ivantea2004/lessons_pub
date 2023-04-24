#include"integral.h"


float pass(differentiable_function_t f, float a, float b, int splits)
{
    int N = splits;

    float s = 0;

    for(int i = 0; i < N; i++)
    {
        float delta = (b - a) / N;
        float ksi = delta * i + a;
        s += f.function(ksi) * delta;
    }
    return s;
}

float integral(differentiable_function_t f, float a, float b, float eps, int* steps)
{

    if(steps)
        *steps = 0;

    float s = pass(f, a, b, 1);

    for(int N = 2;; N *= 2)
    {

        float s1 = pass(f, a, b, N);
        (*steps)++;
        if(s1 - s < eps && s1 - s > -eps)
        {
            return s1;
        }
        s = s1;
    }

}

