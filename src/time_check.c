#include "my.h"

void time_check(char **stock, int nbr)
{
    struct stat st;
    int i = 0;
    int tps = 0;

    while (i != nbr) {
        stat(stock[i], &st);
        tps = st.st_mtime;
        stat(stock[i + 1], &st);
        if (tps < st.st_mtime) {
            swap_elem(i, i + 1, stock);
            i--;
        } else
            i++;
    }
}
