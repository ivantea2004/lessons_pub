#include"integral.h"
#include<math.h>

float integral(real_function_t f, float a, float b, float eps, int* steps)
{

    if(steps)
        *steps = 0;

    float F_left = f(a), F_right = f(b);

    float prev_sum = f((a + b) / 2);
    float prev_S = (b - a) / 6 * (F_left + F_right + 4 * prev_sum);

    for(int n = 4; n < 100000; n *= 2)
    {

        float curr_even = prev_sum;
        float curr_odd = 0;
        float h = (b - a) / n;
    
        for(int i = 1; i < n; i += 2)
        {
            float x = a + i * h;
            curr_odd += f(x);
        }

        float curr_S = h / 3 * (F_left + F_right + 4 * curr_odd + 2 * curr_even);

        if(steps)
            (*steps)++;

        if(fabs((curr_S - prev_S) / 15) < eps)
        {
            return curr_S;
        }

        prev_S = curr_S;
        prev_sum = curr_even + curr_odd;

    }

    return prev_S;
}

