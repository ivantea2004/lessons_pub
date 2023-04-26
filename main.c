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
"-formula <func>                                   formula of <func>\n" \
"-list                                             list all formulas\n" \
"-h                                                same as -help\n" \
"-i                                                same as -integral\n" \
"-r                                                same as -root\n" \
"-c                                                same as -compute\n"\
"-f                                                same as -formula\n"\
"-l                                                same as -list\n"

#define NOT_ENOUGH_ARGS "Not enough arguments.\n"
#define FUNC_INDEX_OUT_OF_RANGE "Function index out of range.\n"
#define INVALID_FORMAT "Invalid format of arguments.\n"
#define INVALID_FLAG "Invalid flag. Read help with -help flag.\n"
#define INVALID_RANGE "Invalid range: <a> is greater then <b>.\n"

int main(int argc, char**argv)
{

    if(argc <= 1) // run default
    {
        real_t eps1 = 0.00001, eps2 = 0.0001;
        real_t a12 = 1, b12 = 1.5; // range where x12 is located
        real_t a13 = -1.4, b13 = -1; // x13
        real_t a23 = 0.5, b23 = 1; // x23

        real_function_t 
            f1 = defined_functions[0],
            f1_der = defined_derivatives[0],
            f2 = defined_functions[1],
            f2_der = defined_derivatives[1],
            f3 = defined_functions[2],
            f3_der = defined_derivatives[2];

        real_t x12 = root(f1, f1_der, f2, f2_der, a12, b12, eps1, NULL);
        real_t x13 = root(f1, f1_der, f3, f3_der, a13, b13, eps1, NULL);
        real_t x23 = root(f2, f2_der, f3, f3_der, a23, b23, eps1, NULL);
        
        real_t y12 = f1(x12), y13 = f1(x13), y23 = f2(x23);

        real_t 
            I1 = integral(f1, x13, x12, eps2, NULL),
            I2 = integral(f2, x23, x12, eps2, NULL),
            I3 = integral(f3, x13, x23, eps2, NULL);

        real_t area = I1 - I2 - I3;

        printf(
            "Finding area of figure between curves:\n"
            "1: %s\n"
            "2: %s\n"
            "3: %s\n"
            "Found intersection x12 = "PRIreal", y12 = "PRIreal"\n"
            "Found intersection x13 = "PRIreal", y13 = "PRIreal"\n"
            "Found intersection x23 = "PRIreal", y23 = "PRIreal"\n"
            "Calcualted I1 = "PRIreal"\n"
            "Calculated I2 = "PRIreal"\n"
            "Calculated I3 = "PRIreal"\n"
            "Area = "PRIreal"\n",
            function_formulas[0],
            function_formulas[1],
            function_formulas[2],
            x12, y12,
            x13, y13,
            x23, y23,
            I1, I2, I3,
            area
        );

        return 0;
    }
    else if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0)
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
        real_t a, b, eps;
        if(!(sscanf(argv[2 + with_steps], "%d", &f) && 
        sscanf(argv[3 + with_steps], SCNreal, &a) && 
        sscanf(argv[4 + with_steps], SCNreal, &b) && 
        sscanf(argv[5 + with_steps], SCNreal, &eps)
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

        if(a > b)
        {
            printf(INVALID_RANGE);
            return 0;
        }

        int steps;

        real_t i = integral(defined_functions[f - 1], a, b, eps, &steps);

        if(steps < 0)
        {
            printf("Could not calculate integral.\n");
            return 0;
        }

        if(with_steps)
            printf("Calculated integral:\nsteps = %d\nI = "PRIreal"\n", steps, i);
        else
            printf("Calculated integral:\nI = "PRIreal"\n", i);

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
        real_t a, b, eps;
        if(!(
            sscanf(argv[2 + with_steps], "%d", &f1) && 
            sscanf(argv[3 + with_steps], "%d", &f2) && 
            sscanf(argv[4 + with_steps], SCNreal, &a) && 
            sscanf(argv[5 + with_steps], SCNreal, &b) && 
            sscanf(argv[6 + with_steps], SCNreal, &eps)
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

        if(a > b)
        {
            printf(INVALID_RANGE);
            return 0;
        }

        int steps;
        real_t r = root(defined_functions[f1 - 1], defined_derivatives[f1 - 1], defined_functions[f2 - 1], defined_derivatives[f2 - 1], a, b, eps, &steps);

        if(steps < 0)
        {
            printf("Could not find root.\n");
            return 0;
        }

        if(with_steps)
            printf("Found root:\nsteps = %d\nx = "PRIreal"\n", steps, r);
        else
            printf("Found root:\nx = "PRIreal"\n", r);
            
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
        real_t x;
        if(!(
            sscanf(argv[2], "%d", &f) &&
            sscanf(argv[3], SCNreal, &x)
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
        real_t y = defined_functions[f - 1](x);
        printf("f(x) = "PRIreal"\n", y);
    }
    else if(strcmp(argv[1], "-f") == 0 || strcmp(argv[1], "-formula") == 0)
    {
        if(argc < 3)
        {
            printf(NOT_ENOUGH_ARGS);
            return 0;
        }
        int f;
        if(!sscanf(argv[2], "%d", &f))
        {
            printf(INVALID_FORMAT);
            return 0;
        }

        if(f <= 0 || f > DEFINED_FUNCTIONS_COUNT)
        {
            printf(FUNC_INDEX_OUT_OF_RANGE);
            return 0;
        }
        printf("%d: %s\n", f, function_formulas[f - 1]);
        return 0;
    }
    else if(strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "-list") == 0)
    {
        for(int i = 0; i < DEFINED_FUNCTIONS_COUNT; i++)
            printf("%d: %s\n", i + 1, function_formulas[i]);
        return 0;
    }
    else
    {
        printf(INVALID_FLAG);
        return 0;
    }

    return 0;
}
