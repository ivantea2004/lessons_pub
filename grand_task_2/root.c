#include"root.h"
#include<math.h>

static float calc_F(differentiable_function_t f, differentiable_function_t g, float x)
{
    return f.function(x) - g.function(x);
}

static float calc_F_der(differentiable_function_t f, differentiable_function_t g, float x)
{
    return f.derivative(x) - g.derivative(x);
}

static int first_derivative_sign(differentiable_function_t f, differentiable_function_t g, float a, float b)
{
    float y1 = calc_F(f, g, a), y2 = calc_F(f, g, b);
    if(y1 < y2)
        return 1;
    else if(y1 > y2)
        return -1;
    else
        return 0;
}

static int second_derivative_sign(differentiable_function_t f, differentiable_function_t g, float a, float b)
{
    float m = (a + b) / 2;
    float y1 = calc_F(f, g, a), y2 = calc_F(f, g, m), y3 = calc_F(f, g, b);
    float y4 = (y1 + y3) / 2;
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

static float chord_method_step(differentiable_function_t f, differentiable_function_t g, float a, float b, DIRECTION dir)
{
    if(dir == DIRECTION_LEFT)
    {
        return b - (a - b) * calc_F(f, g, b) / (calc_F(f, g, a) - calc_F(f, g, b));
    }
    else
    {
        return a - (b - a) * calc_F(f, g, a) / (calc_F(f, g, b) - calc_F(f, g, a));
    }
}

static float newton_method_step(differentiable_function_t f, differentiable_function_t g, float x)
{
    return x - calc_F(f, g, x) / calc_F_der(f, g, x);
}

float root(differentiable_function_t f, differentiable_function_t g, float a, float b, float eps, int*steps)
{
    if(steps)
        *steps = 0;

    int s1 = first_derivative_sign(f, g, a, b);
    int s2 = second_derivative_sign(f, g, a, b);

    DIRECTION dir = s1 * s2 > 0 ? DIRECTION_RIGHT : DIRECTION_LEFT;

    for(int i = 0;; i++)
    {

        if(i > 100)
            return a;

        if(steps)
            (*steps)++;

        if(dir == DIRECTION_RIGHT)
        {
            b = newton_method_step(f, g, b);
            if(fabs(b - a) < eps)
                return a;
            a = chord_method_step(f, g, a, b, dir);
        }
        else
        {
            a = newton_method_step(f, g, a);
            if(fabs(b - a) < eps)
                return a;
            b = chord_method_step(f, g, a, b, dir);
        }
        
        if(fabs(b - a) < eps)
            return a;
    }
}
