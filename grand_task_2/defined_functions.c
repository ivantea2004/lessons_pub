#include"defined_functions.h"
#include"default_functions.h"
#include<math.h>

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

real_function_t defined_functions[DEFINED_FUNCTIONS_COUNT] = 
{
    default_f1,
    default_f2,
    default_f3,
    f4, 
    f5,
    f6,
    f7,
    f8,
    f9,
    f10,
    f11,
    f12,
};

real_function_t defined_derivatives[DEFINED_FUNCTIONS_COUNT] = {
    default_f1_derivative,
    default_f2_derivative,
    default_f3_derivative,
    f4_der,
    f5_der,
    f6_der,
    f7_der,
    f8_der,
    f9_der,
    f10_der,
    f11_der,
    f12_der
};

char* function_formulas[DEFINED_FUNCTIONS_COUNT] = 
{
    default_f1_formula,
    default_f2_formula,
    default_f3_formula,
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
