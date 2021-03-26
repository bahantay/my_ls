#include "my_ls.h"

int main(int ac, char** av)
{
    t_opt* opt = get_opt(ac, av);
    print_opt(opt, ac, av);
    free(opt);
    return 0;
}