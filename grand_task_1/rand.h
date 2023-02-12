#include"config.h"
#include<stdint.h>

void init_rand();
int32_t rand_int32();
int64_t rand_int64();
double rand_double();

#if TEST_TYPE == TEST_32
#define rand_Type rand_int32
#elif TEST_TYPE == TEST_64
#define rand_Type rand_int64
#elif TEST_TYPE == TEST_DOUBLE
#define rand_Type rand_double
#else
#error "Invalid TEST_TYPE"
#endif
