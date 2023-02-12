#include<stdlib.h>
#include"rand.h"
#include<time.h>

void init_rand()
{
	srand(time(NULL));
}

int32_t rand_int32()
{
	return rand() - RAND_MAX / 2;
}

int64_t rand_int64()
{
	int64_t x = rand_int32();
	x <<= 32;
	x |= rand_int32();
	return x;
}

double rand_double()
{
	double x = rand_int32();
	return x / RAND_MAX;
}
