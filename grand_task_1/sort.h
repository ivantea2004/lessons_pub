#include"config.h"
#include"cmp.h"

typedef void(*sort_t)(Type*, size_t, comparator_t);
typedef void(*generator_t)(Type* arr, size_t size);

void execute_sort(sort_t sort, Type* arr, size_t size, comparator_t cmp, size_t* cmps, size_t* swaps);
void test_sort(sort_t, generator_t, comparator_t, size_t);
