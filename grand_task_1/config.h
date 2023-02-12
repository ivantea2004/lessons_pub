#include<stdint.h>
#include<inttypes.h>

#define TEST_DOUBLE 1
#define TEST_32 2
#define TEST_64 3

#define TEST_TYPE TEST_64

#if TEST_TYPE == TEST_64
typedef int64_t Type;
#define PRIType PRIi64
#define SCNType SCNi64
#elif TEST_TYPE == TEST_32
typedef int32_t Type;
#define PRIType PRIi32
#define SCNType SCNi32
#elif TEST_TYPE == TEST_DOUBLE
typedef double Type;
#define PRIType "lf"
#define SCNType "lf"
#else
#error "Invalid TEST_TYPE"
#endif
