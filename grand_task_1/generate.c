#include"generate.h"
#include"rand.h"

void gen_ascending(Type* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] = i;
}

void gen_descending(Type* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		arr[size - i - 1] = i;
}

void gen_rand(Type* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] = rand_Type();
}
