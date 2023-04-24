#include"defined_functions.h"
#include<math.h>

static float f1(float x)
{
    return 1 + 4 / (x * x + 1);
}

static float f1_der(float x)
{
    return -8 * x / ((x * x + 1) * (x *x + 1));
}

static float f2(float x)
{
    return x * x * x;
}

static float f2_der(float x)
{
    return 3 * x * x;
}

static float f3(float x)
{
    return exp2f(-x);
}

static float f3_der(float x)
{
    return -logf(2) * exp2f(x);
}

static float f4(float x)
{
    return log2f(x + 3);
}

static float f4_der(float x)
{
    return 1 / ((x + 3) * logf(2)); 
}

static float f5(float x)
{
    return exp2f(x);
}

static float f5_der(float x)
{
    return logf(2) * exp2f(x);
}

static float f6(float x)
{
    return sinf(x);
}

static float f6_der(float x)
{
    return cosf(x);
}

static float f7(float x)
{
    return expf(x) + 1;
}

static float f7_der(float x)
{
    return expf(x) + 1;
}

static float f8(float x)
{
    return 1 /(x * x);
}

static float f8_der(float x)
{
    return -2 / (x * x * x);
}

static float f9(float x)
{
    return (x + 2) * (x + 2);
}

static float f9_der(float x)
{
    return 2 * x + 4;
}

static float f10(float x)
{
    return sinf(x) + 4;
}

static float f10_der(float x)
{
    return cosf(x);
}

static float f11(float x)
{
    return 2 * logf(x) / x;
}

static float f11_der(float x)
{
    return 2 * (1 - logf(x)) / (x * x);
}

static float f12(float x)
{
    return 1 / sqrtf(x);
}

static float f12_der(float x)
{
    return -0.5 / sqrtf(x * x * x);
}

differentiable_function_t defined_functions[DEFINED_FUNCTIONS_COUNT] = 
{
    {f1, f1_der},
    {f2, f2_der},
    {f3, f3_der},
    {f4, f4_der},
    {f5, f5_der},
    {f6, f6_der},
    {f7, f7_der},
    {f8, f8_der},
    {f9, f9_der},
    {f10, f10_der},
    {f11, f11_der},
    {f12, f12_der}
};

char* function_formulas[DEFINED_FUNCTIONS_COUNT] = 
{
    "y = 1 + 4/(x^2 + 1)",
    "y = x^3",
    "y = 2^(-x)",
    "y = log(2, x + 3)",
    "y = 2^x",
    "y = sinx",
    "y = e^x",
    "y = 1/x^2",
    "y = (x + 2)^2",
    "y = sinx + 4",
    "y = 2(lnx)/x",
    "y = 1/sqrt(x)"
};
