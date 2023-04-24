#include"funcs.h"
#include<math.h>

float f1(float x)
{
    return 1 + 4 / (x * x + 1);
}

float f2(float x)
{
    return x * x * x;
}


float f3(float x)
{
    return exp2f(-x);
}

float f4(float x)
{
    return log2f(x + 3);
}

float f5(float x)
{
    return exp2(x);
}
