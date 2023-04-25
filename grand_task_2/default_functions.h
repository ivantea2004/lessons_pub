#pragma once
#ifndef DEFAULT_FUNCTIONS_H
#define DEFAULT_FUNCTIONS_H

#include<assert.h>
#include"real.h"

static_assert(sizeof(real_t) == sizeof(float), "real_t is not float");

real_t default_f1(real_t);
real_t default_f1_derivative(real_t);
extern char default_f1_formula[];

real_t default_f2(real_t);
real_t default_f2_derivative(real_t);
extern char default_f2_formula[];

real_t default_f3(real_t);
real_t default_f3_derivative(real_t);
extern char default_f3_formula[];

#endif
