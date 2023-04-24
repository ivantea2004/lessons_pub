#include<stdio.h>
#include<string.h>
#include"defined_functions.h"
#include"integral.h"
#include"root.h"

#define HELP_MSG \
"-help                                             print this text\n" \
"-integral [-steps | -s] <func> <a> <b> <eps>      calculate integral of <func> from <a> to <b> with precision <eps>\n" \
"-root [-steps | -s] <func1> <func2> <a> <b> <eps> find root of (<func1> - <func2> = 0) on [a, b] with precision <eps>\n" \
"-compute <func> <x>                               compute <func> value at <x>\n" \
"-h                                                same as -help\n" \
"-i                                                same as -integral\n" \
"-r                                                same as -root\n" \
"-c                                                same as -compute\n"

#define NOT_ENOUGH_ARGS "Not enough arguments.\n"
#define FUNC_INDEX_OUT_OF_RANGE "Function index out of range.\n"
#define INVALID_FORMAT "Invalid format of arguments.\n"
#define INVALID_FLAG "Invalid flag. Read help with -help flag.\n"

int main(int argc, char**argv)
{

    if(argc <= 1)
    {
        // run default
        printf("Default behaviour is not emplimented.\n");
        return 0;
    }
    else if(strcmp(argv[1], "-help") == 0 || strcmp(argv[1], "-h") == 0)
    {
        printf(HELP_MSG);
        return 0;
    }
    else if(strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "-integral") == 0)
    {

        if(argc < 3)
        {
            printf(NOT_ENOUGH_ARGS);
            return 0;
        }

        int with_steps = 0;

        if(strcmp(argv[2], "-steps") == 0 || strcmp(argv[2], "-s") == 0)
            with_steps++;

        if(argc - with_steps < 6)
        {
            printf(NOT_ENOUGH_ARGS);
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

        if(f > DEFINED_FUNCTIONS_COUNT || f <= 0)
        {
            printf(FUNC_INDEX_OUT_OF_RANGE);
            return 0;            
        }

        int steps;

        float i = integral(defined_functions[f - 1], a, b, eps, &steps);

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
            printf(NOT_ENOUGH_ARGS);
            return 0;
        }
        int with_steps = 0;
        if(strcmp(argv[2], "-steps") == 0 || strcmp(argv[2], "-s") == 0)
            with_steps = 1;
        if(argc - with_steps < 7)
        {
            printf(NOT_ENOUGH_ARGS);
            return 0;
        }
        int f1, f2;
        float a, b, eps;
        if(!(
            sscanf(argv[2 + with_steps], "%d", &f1) && 
            sscanf(argv[3 + with_steps], "%d", &f2) && 
            sscanf(argv[4 + with_steps], "%f", &a) && 
            sscanf(argv[5 + with_steps], "%f", &b) && 
            sscanf(argv[6 + with_steps], "%f", &eps)
        ))
        {
            printf(INVALID_FORMAT);
            return 0;
        }
        if(f1 < 0 || f2 < 0 || f1 > DEFINED_FUNCTIONS_COUNT || f2 > DEFINED_FUNCTIONS_COUNT)
        {
            printf(FUNC_INDEX_OUT_OF_RANGE);
            return 0;
        }
        int steps;
        float r = root(defined_functions[f1 - 1], defined_functions[f2 - 1], a, b, eps, &steps);

        if(!with_steps)
            printf("%f\n", r);
        else
            printf("steps=%d\nvalue=%f\n", steps, r);
        return 0;
    }
    else if(strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "-compute") == 0)
    {
        if(argc < 4)
        {
            printf(NOT_ENOUGH_ARGS);
            return 0;
        }
        int f;
        float x;
        if(!(
            sscanf(argv[2], "%d", &f) &&
            sscanf(argv[3], "%f", &x)
        ))
        {
            printf(INVALID_FORMAT);
            return 0;
        }

        if(f <= 0 || f > DEFINED_FUNCTIONS_COUNT)
        {
            printf(FUNC_INDEX_OUT_OF_RANGE);
            return 0;
        }
        float y = defined_functions[f - 1].function(x);
        printf("%f\n", y);
    }
    else
    {
        printf(INVALID_FLAG);
        return 0;
    }

    return 0;
}
