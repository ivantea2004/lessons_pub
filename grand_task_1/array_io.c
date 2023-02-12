#include"array_io.h"

void read_arr(Type* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		scanf("%"SCNType, arr + i);
}

void write_arr(Type* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		printf("%"PRIType" ", arr[i]);
}
