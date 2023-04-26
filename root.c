#include"root.h"
#include<math.h>

static real_t calc_diff(real_function_t f, real_function_t g, real_t x)
{
    return f(x) - g(x);
}

static int first_derivative_sign(real_function_t f, real_function_t g, real_t a, real_t b)
{
    real_t y1 = calc_diff(f, g, a), y2 = calc_diff(f, g, b);
    if(y1 < y2)
        return 1;
    else if(y1 > y2)
        return -1;
    else
        return 0;
}

static int second_derivative_sign(real_function_t f, real_function_t g, real_t a, real_t b)
{
    real_t m = (a + b) / 2;
    real_t y1 = calc_diff(f, g, a), y2 = calc_diff(f, g, m), y3 = calc_diff(f, g, b);
    real_t y4 = (y1 + y3) / 2;
    if(y2 > y4)
        return -1;
    else if(y2 < y4)
        return 1;
    else
        return 0;
}

typedef enum
{
    DIRECTION_LEFT, // from right to left
    DIRECTION_RIGHT // from left to right
} DIRECTION;

static real_t chord_method_step(real_function_t f, real_function_t g, real_t a, real_t b, DIRECTION dir)
{
    if(dir == DIRECTION_LEFT)
    {
        return b - (a - b) * calc_diff(f, g, b) / (calc_diff(f, g, a) - calc_diff(f, g, b));
    }
    else
    {
        return a - (b - a) * calc_diff(f, g, a) / (calc_diff(f, g, b) - calc_diff(f, g, a));
    }
}

static real_t newton_method_step(real_function_t f, real_function_t f_der, real_function_t g, real_function_t g_der, real_t x)
{
    return x - calc_diff(f, g, x) / calc_diff(f_der, g_der, x);
}

// calculated root of (f(x) - g(x)) == 0 equation with precision eps by combined method
real_t root(real_function_t f, real_function_t f_der, real_function_t g, real_function_t g_der, real_t a, real_t b, real_t eps, int*steps)
{
    if(steps)
        *steps = 0;

    int s1 = first_derivative_sign(f, g, a, b);
    int s2 = second_derivative_sign(f, g, a, b);

    DIRECTION dir = s1 * s2 > 0 ? DIRECTION_RIGHT : DIRECTION_LEFT; // direction of chord method

    for(int i = 0;; i++)
    {

        if(i > 1000)
        {
            if(steps)
                *steps = -1;
            return 0;
        }

        if(steps)
            (*steps)++;

        if(dir == DIRECTION_RIGHT)
        {
            b = newton_method_step(f, f_der, g, g_der, b);
            if(fabs(b - a) < eps)
                return a;
            a = chord_method_step(f, g, a, b, dir);
        }
        else
        {
            a = newton_method_step(f, f_der, g, g_der, a);
            if(fabs(b - a) < eps)
                return a;
            b = chord_method_step(f, g, a, b, dir);
        }

        if(steps)
            (*steps)++;
        
        if(fabs(b - a) < eps)
            return a;
    }
}
