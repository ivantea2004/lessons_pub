#pragma once
#ifndef ROOT_H
#define ROOT_H

#include"differentiable_function_t.h"

float root(differentiable_function_t f, differentiable_function_t g, float a, float b, float eps, int*steps);

#endif
