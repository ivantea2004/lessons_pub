#pragma once
#ifndef INTEGRAL_H
#define INTEGRAL_H

#include"real_function.h"

float integral(real_function_t f, float a, float b, float eps, int* steps);

#endif
