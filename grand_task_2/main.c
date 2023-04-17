#include<stdio.h>
#include"integral.h"
#include<math.h>

float s(float x)
{
    return sin(x);
}

int main(void)
{
    
    float I = integral(s, 0, 3.141592653589793, 0.000001);

    printf("%f\n", I);

    return 0;
}
