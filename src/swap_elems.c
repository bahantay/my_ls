#include "my.h"

void swap_elem(int index1, int index2, char **tab)
{
    int len = my_strlen(tab[index1]);
    char *temp = malloc(sizeof(char) * len + 1);

    temp = tab[index1];
    len = my_strlen(tab[index2]);
    tab[index1] = malloc(sizeof(char) * len);
    tab[index1] = tab[index2];
    len = my_strlen(tab[index1]);
    tab[index2] = malloc(sizeof(char) * len);
    tab[index2] = temp;
}
