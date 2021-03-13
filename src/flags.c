#include "my.h"

int flag_br(int ac, char **av)
{
    return (0);
}

int flag_l(int ac, char **av)
{
    int error = 0;

    if (ac == 2 || ac == 3) {
        if (ac == 2)
            l_simple("./");
        else {
            error = check_if_open_option(ac, av);
            if (error == 1)
                return (84);
            l_simple(av[2]);
        }
        return (0);
    }
    error = check_if_open_option(ac, av);
    if (error >= 1)
        return (84);
    l_multiple(ac, av);
    return (0);
}

int flag_r(int ac, char **av)
{
    int error = 0;

    if (ac == 2 || ac == 3) {
        if (ac == 2)
            r_simple("./");
        else {
            error = check_if_open_option(ac, av);
            if (error == 1)
                return (84);
            r_simple(av[2]);
        }
        return (0);
    }
    error = check_if_open_option(ac, av);
    if (error >= 1)
        return (84);
    r_multiple(ac, av);
    return (0);
}

int flag_t(int ac, char **av)
{
    int error = 0;

    if (ac == 2 || ac == 3) {
        if (ac == 2)
            t_simple("./");
        else {
            error = check_if_open_option(ac, av);
            if (error == 1)
                return (84);
            t_simple(av[2]);
        }
        return (0);
    }
    error = check_if_open_option(ac, av);
    if (error >= 1)
        return (84);
    t_multiple(ac, av);
    return (0);
}

int flag_d(int ac, char **av)
{
    DIR *dir;
    int error = 0;

    if (ac == 2)
        my_putstr(".\n");
    if (ac > 2) {
        for (int i = 2; i != ac; i++) {
            if ((dir = opendir(av[i])) == NULL)
                error++;
            closedir(dir);
        }
        if (error >= 1)
            return (84);
        else
            for (int i = 2; i != ac; i++) {
                my_putstr(av[i]);
                my_putchar('\n');
            }
    }
    return (0);
}
