#include "my.h"

int r_simple(char *direc)
{
    int nbr = count_files(direc);
    char **stock = malloc(sizeof(char *) * nbr);

    stock = fill_stock_r(stock, direc, nbr);
    for (int i = -1, u = nbr - 1; u != i; u--) {
        if (u == i)
            break;
        my_putstr(stock[u]);
        my_putchar('\n');
    }
    free(stock);
    return (0);
}

int r_multiple(int ac, char **av)
{
    int len = 0;

    for (int i = 2; i != ac; i++) {
        len = my_strlen(av[i]);
        if (len == 2 && av[i][0] == '.' && av[i][1] == '/') {
            my_putstr("./:\n");
            r_simple("./");
            i++;
            if (i != ac)
                my_putchar('\n');
            else
                return (0);
        }
        my_putstr(av[i]);
        my_putstr(":\n");
        t_simple(av[i]);
        if (i != ac - 1)
            my_putchar('\n');
    }
    return (0);
}
