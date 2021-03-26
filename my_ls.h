#include <stdlib.h>
#include <stdio.h>
/*
**
*/
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#define BLU   "\x1B[34m"
#define RESET "\x1B[0m"
#include "my.h"
/*
**
*/
typedef struct t_opt
{
    int options;
#define OPT_a 1<<0   //0000 0001
#define OPT_t 1<<1   //0000 0010
#define OPT_R 1<<2   //0000 0100
} t_opt;  //from Kwame's video

//list for setting zero 
typedef struct s_opt_list
{
    char opt_char;
    int opt_int;
} t_opt_list;

//list for dir and file
#ifndef STRUCT_FILE_INFO
#define STRUCT_FILE_INFO
typedef struct s_file_info
{
    int* type;
    int size;
    char** array;
    time_t* mtime;
    long long* mtime_nsec;
    
} file_info;
#endif


t_opt* get_opt(int ac, char** av);
void print_opt(t_opt* opt, int ac, char** av);