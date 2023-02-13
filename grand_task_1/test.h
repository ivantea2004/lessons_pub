#pragma once
#ifndef TEST_H
#define TEST_H

#include"sort.h"

#define MAX_TESTS 7

void run_tests(generator_t gen, comparator_t cmp, sort_t*sorts, char**sort_names, size_t sorts_count, size_t*sizes, size_t sizes_count);

#endif
