#ifndef __MY_H__
#define __MY_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
void my_put_nbr(int nb);
char *my_strcat(char *dest, char *src);

int error_handling(int ac, char **av);
int check_if_open(int ac, char **av);
int check_if_open_option(int ac, char **av);
int count_files(char *current);
void swap_elem(int index1, int index2, char **tab);

char **fill_tab(char **stock, char *direc, int nbr);
char **fill_name(char **display_stock, char **stock, int nbr);

int check_flag(int ac, char **av);

int simple_ls(int ac, char **av);
int flag_d(int ac, char **av);

int flag_t(int ac, char **av);
void time_check(char **stock, int nbr);
int t_simple(char *current);
int t_multiple(int ac, char **av);

int flag_r(int ac, char **av);
char **fill_stock_r(char **stock, char *direc, int nbr);
int r_simple(char *direc);
int r_multiple(int ac, char **av);

int flag_l(int ac, char **av);
int l_simple(char *direc);
int l_multiple(int ac, char **av);
void display_total(char *direc);
void display_rights(char *file);
void display_link(char *file);
void display_size(char *file);
void display_date_and_time(char *file);

int flag_br(int ac, char **av);

#endif
