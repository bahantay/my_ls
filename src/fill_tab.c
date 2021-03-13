#include "my.h"

char **fill_name(char **display_stock, char **stock, int nbr)
{
    int len = 0;
    int i = 0;
    int j = 0;

    while (i != nbr) {
        len = my_strlen(stock[i]);
        display_stock[i] = malloc(sizeof(char) * len + 1);
        while (stock[i][j] != '/')
            j++;
        j++;
        for (int u = 0; stock[i][j] != '\0'; u++, j++) {
            display_stock[i][u] = stock[i][j];
            if (stock[i][j + 1] == '\0')
                display_stock[i][u + 1] = '\0';
        }
        j = 0;
        i++;
    }
    return (display_stock);
}

char **fill_stock_r(char **stock, char *direc, int nbr)
{
    DIR *dir = opendir(direc);
    struct dirent *read;
    int len = 0;
    int i = 0;

    while ((read = readdir(dir)) != 0 || i != nbr)
        if (read->d_name[0] != '.') {
            len = my_strlen(read->d_name);
            stock[i] = malloc(sizeof(char) * len + 1);
            stock[i] = read->d_name;
            stock[i][len] = '\0';
            i++;
        }
    closedir(dir);
    return (stock);
}

char **fill_tab(char **stock, char *direc, int nbr)
{
    int var[4] = {0, 0, my_strlen(direc), 0};
    DIR *dir = opendir(direc);
    struct dirent *read;

    while ((read = readdir(dir)) != 0 || var[1] != nbr)
        if (read->d_name[0] != '.') {
            var[0] = my_strlen(read->d_name);
            stock[var[1]] = malloc(sizeof(char) * (var[0] + var[2] + 1));
            for (int j = 0; direc[j] != '\0'; j++)
                stock[var[1]][j] = direc[j];
            if (direc[var[2] - 1] != '/') {
                stock[var[1]][var[2]] = '/';
                var[3]++;
            }
            for (int z = var[2] + var[3], u = 0;
                 read->d_name[u] != '\0'; z++, u++)
                stock[var[1]][z] = read->d_name[u];
            var[1]++;
            var[3] = 0;
        }
    closedir(dir);
    return (stock);
}
