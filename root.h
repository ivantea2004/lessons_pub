#pragma once
#ifndef ROOT_H
#define ROOT_H

#include"real_function.h"

real_t root(real_function_t f, real_function_t f_der, real_function_t g, real_function_t g_der, real_t a, real_t b, real_t eps, int*steps);

#endif
