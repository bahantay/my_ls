#include <stdlib.h>
#include <stdio.h>

typedef struct t_opt
{
    int a;
    int t;
    int R;
} t_opt;

t_opt* get_opt(int ac, char** av);
void print_opt(t_opt* opt);