#include "my.h"

static void multi_free(char **stock, char **display_stock, int nbr)
{
    for (int j = 0; j != nbr; j++) {
        free(stock[j]);
        free(display_stock[j]);
    }
    free(stock);
    free(display_stock);
}

int t_simple(char *current)
{
    int nbr = count_files(current);
    char **stock = malloc(sizeof(char *) * nbr);
    char **display_stock = malloc(sizeof(char *) * nbr);

    stock = fill_tab(stock, current, nbr);
    if (nbr == 1) {
        display_stock = fill_name(display_stock, stock, nbr);
        my_putstr(display_stock[0]);
        my_putchar('\n');
        return (0);
    }
    time_check(stock, nbr);
    display_stock = fill_name(display_stock, stock, nbr);
    for (int j = 0; j != nbr; j++) {
        my_putstr(display_stock[j]);
        my_putchar('\n');
    }
    multi_free(stock, display_stock, nbr);
    return (0);
}

int t_multiple(int ac, char **av)
{
    int len = 0;

    for (int i = 2; i != ac; i++) {
        len = my_strlen(av[i]);
        if (len == 2 && av[i][0] == '.' && av[i][1] == '/') {
            my_putstr("./:\n");
            t_simple("./");
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
