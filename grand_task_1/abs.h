#pragma once
#ifndef ABS_H
#define ABS_H

#include<math.h>
#include"config.h"

#define abs_int32 abs
#define abs_int64 llabs
#define abs_double fabs

#if TEST_TYPE == TEST_32
#define abs_Type abs_int32
#elif TEST_TYPE == TEST_64
#define abs_Type abs_int64
#elif TEST_TYPE == TEST_DOUBLE
#define abs_Type abs_double
#else
#error "Invalid TEST_TYPE"
#endif

#endif 
