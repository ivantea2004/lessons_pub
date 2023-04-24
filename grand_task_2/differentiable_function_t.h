#pragma once
#ifndef DIFFERENTIABLE_FUNCTION_T_H
#define DIFFERENTIABLE_FUNCTION_T_H

typedef float(*real_function_t)(float);

typedef struct{
    real_function_t function;
    real_function_t derivative;
} differentiable_function_t;

#endif
