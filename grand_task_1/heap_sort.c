#include"heap_sort.h"
#include"swap.h"

size_t parent(size_t at)
{
	return (at - 1) / 2;
}

size_t left(size_t at)
{
	return 2 * at + 1;
}

size_t right(size_t at)
{
	return 2 * at + 2;
}

void max_heapify(Type* arr, size_t at, size_t heap_size, comparator_t cmp)
{
	size_t l = left(at), r = right(at);
	size_t largest = 0;
	if (l < heap_size && cmp(arr[l], arr[at]) > 0)
		largest = l;
	else
		largest = at;
	if (r < heap_size && cmp(arr[r], arr[largest]) > 0)
		largest = r;
	if (at != largest)
	{
		swap(arr + at, arr + largest);
		max_heapify(arr, largest, heap_size, cmp);
	}
}

void build_max_heap(Type* arr, size_t size, comparator_t cmp)
{
	for (int64_t i = size / 2; i >= 0; i--)
		max_heapify(arr, i, size, cmp);

}

void heap_sort(Type* arr, size_t size, comparator_t cmp)
{
	size_t heap_size = size;
	build_max_heap(arr, size, cmp);
	for (size_t i = size - 1; i >= 1; i--)
	{
		swap(arr, arr + i);
		heap_size--;
		max_heapify(arr, 0, heap_size, cmp);
	}
}
