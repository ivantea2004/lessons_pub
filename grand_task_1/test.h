#pragma once
#ifndef TEST_H
#define TEST_H

#include<stddef.h>
#include"cmp.h"
#include"generate.h"

#define MAX_TESTS 7

typedef void(*sort_t)(Type*, size_t, comparator_t);

void execute_sort(sort_t sort, Type* arr, size_t size, comparator_t cmp, size_t* cmps, size_t* swaps);
void test_sort(sort_t, generator_t, comparator_t, size_t);
void run_tests(generator_t gen, comparator_t cmp, sort_t*sorts, char**sort_names, size_t sorts_count, size_t*sizes, size_t sizes_count);

#endif
