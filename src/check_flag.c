#include "my.h"

int check_flag2(int ac, char **av)
{
    switch (av[1][1]) {
    case 'd' : if (flag_d(ac, av) == 84)
            return (84);
        break;
    case 'r' : if (flag_r(ac, av) == 84)
            return (84);
        break;
    case 'R' : if (flag_br(ac, av) == 84)
            return (84);
        break;
    case 'l' : if (flag_l(ac, av) == 84)
            return (84);
        break;
    case 't' : if (flag_t(ac, av) == 84)
            return (84);
        break;
    }
    return (0);
}

int check_flag(int ac, char **av)
{
    int ret = 0;

    if (ac == 1) {
        simple_ls(ac, av);
        return (0);
    }
    if (av[1][0] == '-') {
        ret = check_flag2(ac, av);
        return (ret);
    }
    else
        if (simple_ls(ac, av) == 84)
            return (84);
    return (0);
}
