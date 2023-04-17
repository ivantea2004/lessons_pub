#include<stdio.h>
#include<string.h>
#include"funcs.h"
#include"integral.h"
#include"root.h"

#define HELP_MSG \
"-help                                        print this text\n" \
"-integral [-steps | -s] <func> <a> <b> <eps> calculate integral of <func> from <a> to <b> with precision <eps>\n" \
"-root [-steps | -s] <func1> <func2> <eps>    find root of (<func1> - <func2> = 0) with precision <eps>\n" \
"-i                                           same as -integral\n" \
"-r                                           same as -root\n"

#define NOT_ENUF_ARGS "Not enuf arguments.\n"
#define FUNC_INDEX_OUT_OF_RANGE "Function index out of range.\n"
#define INVALID_FORMAT "Invalid format of arguments.\n"

#define FUNCS_COUNT 3

func_t funcs[FUNCS_COUNT] = {f1, f2, f3};

int main(int argc, char**argv)
{

    if(argc <= 1)
    {
        // run default
        return 0;
    }
    else if(strcmp(argv[1], "-help") == 0)
    {
        printf(HELP_MSG);
        return 0;
    }
    else if(strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "-integral") == 0)
    {

        if(argc < 3)
        {
            printf(NOT_ENUF_ARGS);
            return 0;
        }

        int with_steps = 0;

        if(strcmp(argv[2], "-steps") == 0 || strcmp(argv[2], "-s") == 0)
            with_steps++;

        if(argc - with_steps < 6)
        {
            printf(NOT_ENUF_ARGS);
            return 0;
        }
        
        int f;
        float a, b, eps;
        if(!(sscanf(argv[2 + with_steps], "%d", &f) && 
        sscanf(argv[3 + with_steps], "%f", &a) && 
        sscanf(argv[4 + with_steps], "%f", &b) && 
        sscanf(argv[5 + with_steps], "%f", &eps)
        )) 
        {
            printf(INVALID_FORMAT);
            return 0;
        }

        if(f > FUNCS_COUNT || f <= 0)
        {
            printf(FUNC_INDEX_OUT_OF_RANGE);
            return 0;            
        }

        int steps;

        float i = integral(funcs[f - 1], a, b, eps, &steps);

        if(!with_steps)
            printf("%f\n", i);
        else
            printf("steps=%d\nvalue=%f\n", steps, i);

        return 0;
        
    }
    else if(strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "-root") == 0)
    {
        if(argc < 3)
        {
            printf(NOT_ENUF_ARGS);
            return 0;
        }
        int with_steps = 0;
        if(strcmp(argv[2], "-steps") == 0 || strcmp(argv[2], "-s") == 0)
            with_steps = 1;
        if(argc - with_steps < 5)
        {
            printf(NOT_ENUF_ARGS);
            return 0;
        }
        int f1, f2;
        float eps;
        if(!(
            sscanf(argv[2 + with_steps], "%d", &f1) && 
            sscanf(argv[3 + with_steps], "%d", &f2) && 
            sscanf(argv[4 + with_steps], "%f", &eps)
        ))
        {
            printf(INVALID_FORMAT);
        }
        if(f1 < 0 || f2 < 0 || f1 > FUNCS_COUNT || f2 > FUNCS_COUNT)
        {
            printf(FUNC_INDEX_OUT_OF_RANGE);
            return 0;
        }
        int steps;
        float r = root(funcs[f1 - 1], funcs[f2 - 2], eps, &steps);

        if(!with_steps)
            printf("%f\n", r);
        else
            printf("steps=%d\nvalue=%f\n", steps, r);
        return 0;
    }


    return 0;
}
