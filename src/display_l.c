#include "my.h"

void display_date_and_time(char *file)
{
    struct stat st;
    char *time;
    char *result = malloc(sizeof(char) * 12);
    int j = 0;

    stat(file, &st);
    time = ctime(&st.st_mtime);
    for (int i = 4; i != 16; i++, j++)
        result[j] = time[i];
    my_putstr(result);
    my_putchar(' ');
    free(result);
}

void display_size(char *file)
{
    struct stat st;

    stat(file, &st);
    my_put_nbr(st.st_size);
    my_putchar(' ');
}

void display_total(char *direc)
{
    DIR *dir = opendir(direc);
    struct dirent *read;
    struct stat st;
    char *file;
    int tot = 0;

    while ((read = readdir(dir)) != 0) {
        file = my_strcat(direc, read->d_name);
        if ((lstat(file, &st)) == 0)
            (read->d_name[0] != '.') ? tot += st.st_blocks : 0;
    }
    closedir(dir);
    my_putstr("total ");
    my_put_nbr(tot / 2);
    my_putchar('\n');
}

void display_rights(char *file)
{
    struct stat st;

    stat(file, &st);
    if (S_ISREG(st.st_mode)) my_putchar('-');
    if (S_ISDIR(st.st_mode)) my_putchar('d');
    my_putchar((S_IRUSR & st.st_mode ? 'r' : '-'));
    my_putchar((S_IWUSR & st.st_mode ? 'w' : '-'));
    my_putchar((S_IXUSR & st.st_mode ? 'x' : '-'));
    my_putchar((S_IRGRP & st.st_mode ? 'r' : '-'));
    my_putchar((S_IWGRP & st.st_mode ? 'w' : '-'));
    my_putchar((S_IXGRP & st.st_mode ? 'x' : '-'));
    my_putchar((S_IROTH & st.st_mode ? 'r' : '-'));
    my_putchar((S_IWOTH & st.st_mode ? 'w' : '-'));
    my_putchar((S_IXOTH & st.st_mode ? 'x' : '-'));
    my_putstr(". ");
}

void display_link(char *file)
{
    struct stat st;

    stat(file, &st);
    my_put_nbr(st.st_nlink);
    my_putchar(' ');
}
