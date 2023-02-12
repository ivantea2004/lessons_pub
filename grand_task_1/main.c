#include<stdio.h>
#include"rand.h"
#include"sort.h"
#include"generate.h"
#include"bubble_sort.h"
#include"shell_sort.h"
#include"heap_sort.h"

int main()
{

	init_rand();

	check_sort(heap_sort, gen_rand, less, 1000000);

	return 0;
}
