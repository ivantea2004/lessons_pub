#include"config.h"
#include<math.h>

#define abs_int32 abs
#define abs_int64 llabs
#define abs_double fabs

#if TEST_TYPE == TEST_32
#define abs_Type abs_int32
#elif TEST_TYPE == TEST_64
#define abs_Type abs_int64
#elif TEST_TYPE == TEST_OOUBLE
#define abs_Type abs_double
#else
#error "Invalid TEST_TYPE"
#endif
