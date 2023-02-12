#include"shell_sort.h"
#include"swap.h"

void shell_sort_pass_impl(Type*arr, size_t size, comparator_t cmp, size_t d, size_t offset)
{
	for(size_t i = 1; offset + i * d < size; i++)
		for (size_t j = i; j > 0 && cmp(arr[j * d + offset], arr[(j - 1) * d + offset]) < 0; j -= 1)
		{
			swap(arr + j * d + offset, arr + (j - 1) * d + offset);
		}
}

void shell_sort_pass(Type*arr, size_t size, comparator_t cmp, size_t d)
{
	for (size_t i = 0; i < d; i++)
		shell_sort_pass_impl(arr, size, cmp, d, i);
}

void shell_sort(Type* arr, size_t size, comparator_t cmp)
{
	for (size_t d = size / 2; d > 0; d /= 2)
		shell_sort_pass(arr, size, cmp, d);
}
