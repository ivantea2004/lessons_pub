#include"defined_functions.h"
#include<math.h>

static float f1(float x)
{
    return 1 + 4 / (x * x + 1);
}

static float f1_dir(float x)
{
    return -8 * x / ((x * x + 1) * (x *x + 1)); // (-8x) / (x^2 + 1)^2
}

static float f2(float x)
{
    return x * x * x;
}

static float f2_dir(float x)
{
    return 3 * x * x;
}

static float f3(float x)
{
    return exp2f(-x);
}

static float f3_dir(float x)
{
    return -logf(2) * exp2f(x);
}

static float f4(float x)
{
    return log2f(x + 3);
}

static float f4_dir(float x)
{
    return 1 / ((x + 3) * logf(2)); 
}

static float f5(float x)
{
    return exp2f(x);
}

static float f5_dir(float x)
{
    return logf(2) * exp2f(x);
}

static float f6(float x)
{
    return sinf(x);
}

static float f6_dir(float x)
{
    return cosf(x);
}

static float f7(float x)
{
    return expf(x) + 1;
}

static float f7_dir(float x)
{
    return expf(x) + 1;
}

static float f8(float x)
{
    return 1 /(x * x);
}

static float f8_dir(float x)
{
    return -2 / (x * x * x);
}

differentiable_function_t defined_functions[DEFINED_FUNCTIONS_COUNT] = 
{
    {f1, f1_dir},
    {f2, f2_dir},
    {f3, f3_dir},
    {f4, f4_dir},
    {f5, f5_dir},
    {f6, f6_dir},
    {f7, f7_dir},
    {f8, f8_dir}
};
