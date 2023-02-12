#pragma once
#ifndef CMP_H
#define CMP_H

#include"type.h"

typedef int(*comparator_t)(Type, Type);

size_t get_comparations();
void clear_comparations();

int greater(Type, Type);
int less(Type, Type);

int greater_abs(Type, Type);
int less_abs(Type, Type);

#endif CMP_H
