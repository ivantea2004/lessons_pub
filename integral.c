#include"integral.h"
#include<math.h>

// calculated integral of f ob [a, b] with precision eps by Simpson method
real_t integral(real_function_t f, real_t a, real_t b, real_t eps, int* steps)
{

    if(steps)
        *steps = 1;

    real_t F_left = f(a), F_right = f(b);
    real_t prev_sum = f((a + b) / 2);
    real_t prev_S = (b - a) / 6 * (F_left + F_right + 4 * prev_sum);

    for(int n = 4, k = 1; k < 20; n *= 2, k++)
    {
        
        real_t curr_even = prev_sum;
        real_t curr_odd = 0;
        real_t h = (b - a) / n;
    
        for(int i = 1; i < n; i += 2)
        {
            real_t x = a + i * h;
            curr_odd += f(x);
        }

        real_t curr_S = h / 3 * (F_left + F_right + 4 * curr_odd + 2 * curr_even);
        
        if(steps)
            (*steps)++;

        if(fabs((curr_S - prev_S) / 15) < eps)
        {
            return curr_S;
        }

        prev_S = curr_S;
        prev_sum = curr_even + curr_odd;

    }

    if(steps)
        *steps = -1;

    return 0;
}

