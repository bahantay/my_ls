#include "my.h"

int count_files(char *current)
{
    DIR *dir = opendir(current);
    struct dirent *read;
    int nbr = 0;

    while ((read = readdir(dir)) != 0)
        if (read->d_name[0] != '.')
            nbr++;
    closedir(dir);
    return (nbr);
}
