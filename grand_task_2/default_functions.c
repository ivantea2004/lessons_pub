#include"default_functions.h"
#include<math.h>

float default_f1(float x)
{
    return 1 + 4 / (x * x + 1);
}

float default_f1_derivative(float x)
{
    return -8 * x / ((x * x + 1) * (x *x + 1));
}

char default_f1_formula[] = "y = 1 + 4/(x^2 + 1)";

float default_f2(float x)
{
    return x * x * x;
}

float default_f2_derivative(float x)
{
    return 3 * x * x;
}

char default_f2_formula[] = "y = x^3";

float default_f3(float x)
{
    return exp2f(-x);
}

float default_f3_derivative(float x)
{
    return -logf(2) * exp2f(x);
}

char default_f3_formula[] = "y = 2^(-x)";
