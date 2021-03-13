#include "my.h"

int check_if_open_option(int ac, char **av)
{
    DIR *dir;
    int error = 0;

    for (int i = 2; i != ac; i++) {
        if ((dir = opendir(av[i])) == NULL)
            error++;
        closedir(dir);
    }
    return (error);
}

int check_if_open(int ac, char **av)
{
    DIR *dir;
    int error = 0;

    for (int i = 1; i != ac; i++) {
        if ((dir = opendir(av[i])) == NULL)
            error++;
        closedir(dir);
    }
    return (error);
}
