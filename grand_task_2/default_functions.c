#include"default_functions.h"
#include<math.h>

real_t default_f1(real_t x)
{
    return 1 + 4 / (x * x + 1);
}

real_t default_f1_derivative(real_t x)
{
    return -8 * x / ((x * x + 1) * (x *x + 1));
}

char default_f1_formula[] = "y = 1 + 4/(x^2 + 1)";

real_t default_f2(real_t x)
{
    return x * x * x;
}

real_t default_f2_derivative(real_t x)
{
    return 3 * x * x;
}

char default_f2_formula[] = "y = x^3";

real_t default_f3(real_t x)
{
    return exp2(-x);
}

real_t default_f3_derivative(real_t x)
{
    return -logf(2) * exp2(x);
}

char default_f3_formula[] = "y = 2^(-x)";
