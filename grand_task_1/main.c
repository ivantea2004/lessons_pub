#include<stdio.h>
#include"rand.h"
#include"sort.h"
#include"generate.h"
#include"bubble_sort.h"
#include"shell_sort.h"

int main()
{

	init_rand();

	check_sort(shell_sort, gen_descending, less, 1000000);

	return 0;
}
