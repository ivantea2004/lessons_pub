#pragma once
#ifndef TYPE_H
#define TYPE_H

#include<stdint.h>
#include<inttypes.h>
#include"config.h"

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

#endif
