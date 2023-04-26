#include"defined_functions.h"
#include"default_functions.h"
#include<math.h>


static real_t f4(real_t x)
{
    return log2(x + 3);
}

static real_t f4_der(real_t x)
{
    return 1 / ((x + 3) * log(2)); 
}

static real_t f5(real_t x)
{
    return exp2(x);
}

static real_t f5_der(real_t x)
{
    return log(2) * exp2(x);
}

static real_t f6(real_t x)
{
    return sin(x);
}

static real_t f6_der(real_t x)
{
    return cos(x);
}

static real_t f7(real_t x)
{
    return exp(x) + 1;
}

static real_t f7_der(real_t x)
{
    return exp(x) + 1;
}

static real_t f8(real_t x)
{
    return 1 /(x * x);
}

static real_t f8_der(real_t x)
{
    return -2 / (x * x * x);
}

static real_t f9(real_t x)
{
    return (x + 2) * (x + 2);
}

static real_t f9_der(real_t x)
{
    return 2 * x + 4;
}

static real_t f10(real_t x)
{
    return sin(x) + 4;
}

static real_t f10_der(real_t x)
{
    return cos(x);
}

static real_t f11(real_t x)
{
    return 2 * log(x) / x;
}

static real_t f11_der(real_t x)
{
    return 2 * (1 - log(x)) / (x * x);
}

static real_t f12(real_t x)
{
    return 1 / sqrt(x);
}

static real_t f12_der(real_t x)
{
    return -0.5 / sqrt(x * x * x);
}

static real_t f13(real_t x)
{
    return x;
}

static real_t f13_der(real_t x)
{
    return 1;
}


static real_t f14(real_t x)
{
    return 1 / x;
}

static real_t f14_der(real_t x)
{
    return -1 / (x * x);
}


static real_t f15(real_t x)
{
    return 3 * x * x + 2;
}

static real_t f15_der(real_t x)
{
    return 6 * x;
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
    f13,
    f14,
    f15
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
    f12_der,
    f13_der,
    f14_der,
    f15_der
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
    "y = 1/sqrt(x)",
    "y  = x",
    "y = 1/x",
    "y = 3x^2 + 2"
};
