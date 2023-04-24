#pragma once
#ifndef INTEGRAL_H
#define INTEGRAL_H

#include"differentiable_function_t.h"

float integral(differentiable_function_t f, float a, float b, float eps, int* steps);

#endif
