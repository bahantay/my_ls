#include "my.h"

int my_ls(int ac, char **av)
{
    if (ac >= 1) {
        if (check_flag(ac, av) == 84)
            return (84);
        return (0);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (my_ls(ac, av) == 84)
        return (84);
    return (0);
}
