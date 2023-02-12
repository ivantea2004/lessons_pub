#include"config.h"

typedef int(*comparator_t)(Type, Type);

size_t get_comparations();
size_t clear_comparations();

extern comparator_t greater;
