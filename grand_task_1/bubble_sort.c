#include"bubble_sort.h"
#include"swap.h"

void bubble_sort(Type* arr, size_t size, comparator_t cmp)
{
	for (size_t i = size; i > 0; i--)
		for (size_t j = 0; j + 1 < i; j++)
			if (cmp(arr[j], arr[j + 1]) > 0)
				swap(arr + j, arr + j + 1);

}
