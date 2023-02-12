#include"shell_sort.h"
#include"swap.h"

void shell_sort_pass(Type*arr, size_t size, comparator_t cmp, size_t d)
{
	for (size_t _i = d; _i < size; _i++)
	{
		size_t offset = _i % d;
		size_t i = _i / d;
		for (size_t j = i; j > 0 && cmp(arr[j * d + offset], arr[(j - 1) * d + offset]) < 0; j -= 1)
		{
			swap(arr + j * d + offset, arr + (j - 1) * d + offset);
		}
	}
}

void shell_sort(Type* arr, size_t size, comparator_t cmp)
{
	for (size_t d = size / 2; d > 0; d /= 2)
		shell_sort_pass(arr, size, cmp, d);
}
