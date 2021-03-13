#include "my.h"

void display_grp_usr_name(char *file)
{
    struct stat st;

    stat(file, &st);
    my_putstr(getpwuid(st.st_uid) -> pw_name);
    my_putchar(' ');
    my_putstr(getgrgid(st.st_gid) -> gr_name);
    my_putchar(' ');
}

void free_all(char **stock, char **display_stock, int nbr)
{
    for (int i = 0; i != nbr; i++) {
        free(stock[i]);
        free(display_stock[i]);
    }
    free(stock);
    free(display_stock);
}

int l_simple(char *direc)
{
    int nbr = count_files(direc);
    char **stock = malloc(sizeof(char *) * nbr);
    char **display_stock = malloc(sizeof(char *) * nbr);

    display_total(direc);
    stock = fill_tab(stock, direc, nbr);
    display_stock = fill_name(display_stock, stock, nbr);
    for (int i = 0; i != nbr; i++) {
        display_rights(stock[i]);
        display_link(stock[i]);
        display_grp_usr_name(stock[i]);
        display_size(stock[i]);
        display_date_and_time(stock[i]);
        my_putstr(display_stock[i]);
        my_putchar('\n');
    }
    free_all(stock, display_stock, nbr);
    return (0);
}

int l_multiple(int ac, char **av)
{
    int len = 0;

    for (int i = 2; i != ac; i++) {
        len = my_strlen(av[i]);
        if (len == 2 && av[i][0] == '.' && av[i][1] == '/') {
            my_putstr("./:\n");
            l_simple("./");
            i++;
            if (i != ac)
                my_putchar('\n');
            else
                return (0);
        }
        my_putstr(av[i]);
        my_putstr(":\n");
        l_simple(av[i]);
        if (i != ac - 1)
            my_putchar('\n');
    }
    return (0);
}
