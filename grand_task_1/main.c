#include<stdio.h>
#include"config.h"
#include"rand.h"

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

int main()
{

	init_rand();

	size_t n;
	scanf("%"SCNuPTR, &n);

	Type arr[100];

	read_arr(arr, n);
	write_arr(arr, n);
	

	return 0;
}
