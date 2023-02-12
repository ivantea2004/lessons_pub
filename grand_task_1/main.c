#include<stdio.h>
#include"config.h"
#include"rand.h"
#include"sort.h"
#include"generate.h"
#include"heap_sort.h"


int main()
{

	init_rand();

	test_sort(heap_sort, gen_rand, less, 10);

	return 0;
}
