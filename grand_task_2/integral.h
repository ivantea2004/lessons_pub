#pragma once
#ifndef INTEGRAL_H
#define INTEGRAL_H

#include"real_function.h"

real_t integral(real_function_t f, real_t a, real_t b, real_t eps, int* steps);

#endif
