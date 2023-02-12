#pragma once
#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include<stddef.h>
#include"type.h"
#include"cmp.h"

void heap_sort(Type* arr, size_t size, comparator_t);

#endif HEAP_SORT_H
