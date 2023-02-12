#pragma once
#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include<stddef.h>
#include"type.h"
#include"cmp.h"

void bubble_sort(Type* arr, size_t size, comparator_t cmp);

#endif
