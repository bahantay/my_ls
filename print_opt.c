#include "my_ls.h"

void print_opt(t_opt* opt)
{
    if (opt->a == 1)
    {
        printf("options a\n");
    }
    if (opt->t == 1)
    {
        printf("options t\n");
    }
    if (opt->R == 1)
    {
        printf("options R\n");
    }
}