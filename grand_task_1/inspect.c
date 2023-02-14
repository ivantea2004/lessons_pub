#include"inspect.h"
#include"array_io.h"

static int enabled = 0;
static Type* arr;
static size_t size;

void inspect_init(Type* a, size_t s)
{
    arr = a;
    size = s;
}

void inspect_set_enabled(int e)
{
    enabled = e;
}

int inspect_is_enabled()
{
    return enabled;
}

void inspect_log()
{
    if(inspect_is_enabled())
    {
        write_arr(arr, size);
        printf("\n");
    }
}
