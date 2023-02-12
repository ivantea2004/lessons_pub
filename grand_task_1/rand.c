#include"rand.h"
#include<stdlib.h>
#include<time.h>

void init_rand()
{
	srand(time(NULL));
}
