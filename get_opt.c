#include "my_ls.h"

int is_option(char* str)
{
    if (str[0] == '-')
    {
        return 1;
    }
    return 0;
}

t_opt* init_opt()
{
    t_opt* opt = (t_opt*)malloc(sizeof(t_opt));

    opt->a = 0;
    opt->t = 0;
    opt->R = 0;

    return opt;
}

void set_opt(t_opt* opt, char* str)
{
    int index = 0;

    while (str[index] != '\0')
    {
        if (str[index] == 'a')
        {
            opt->a = 1;
        }
        if (str[index] == 't')
        {
            opt->t = 1;
        }
        if (str[index] == 'R')
        {
            opt->R = 1;
        }
        index += 1;
    }
}

t_opt* get_opt(int ac, char** av)
{
    t_opt* opt = init_opt();
    int index = 0;

    while (index < ac)
    {
        if (is_option(av[index]) == 1)
        {
            set_opt(opt, av[index] + 1);
        }
        index += 1;
    }
    return opt;
}