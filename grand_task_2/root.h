#pragma once
#ifndef ROOT_H
#define ROOT_H

#include"real_function.h"

float root(real_function_t f, real_function_t f_der, real_function_t g, real_function_t g_der, float a, float b, float eps, int*steps);

#endif
