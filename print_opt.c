/*
**
*/
#include <stdlib.h>
#include "my_ls.h"

/*
**
*/
void* print_dir(struct s_file_info * str_array, char * str, t_opt* opt){
    printf("%s:\n", str);
    for (int i = 0; i<str_array->size; i++)
    {
        char* dir_name = str_array->array[i];
        if (opt->options & OPT_a){
            if (str_array->type[i] == 4){
                printf(BLU "%s  "   RESET, str_array->array[i]);
            }
            else {
                printf("%s  ",str_array->array[i]); 
            }
        }
        else {
            if (dir_name[0]!='.'){ // opt_a
                if (str_array->type[i] == 4){
                    printf(BLU "%s  "   RESET, str_array->array[i]);
                }
                else {
                    printf("%s  ",str_array->array[i]); 
                }
            } 
        }
    } 
    printf("\n\n");
    return 0;
}
//if t opt then sorting, each malloc should be freed
file_info* sorting(struct s_file_info* str_array, t_opt* opt){
    file_info* result;
    result = malloc (sizeof (file_info));
    result->array = (char**)malloc(str_array->size*sizeof(char**));
    result->type = (int*)malloc(str_array->size*sizeof(int*));
    result->size = str_array->size;
    result->mtime = malloc(str_array->size*sizeof(time_t*));
    result->mtime_nsec = malloc(str_array->size*sizeof(__syscall_slong_t*)); // updates
    int index[str_array->size];

    for(int i = 0; i<str_array->size; i++){
        index[i] = i;
    }
    int min;
    for (int i = 0; i < str_array->size; ++i) {
        min = i;
        for (int j = i + 1; j < str_array->size; ++j) {
            if (opt->options & OPT_t){  //opt_t
                if (compare_time(str_array->mtime[index[min]], str_array->mtime[index[j]], 
                    str_array->mtime_nsec[index[min]], str_array->mtime_nsec[index[j]]) == -1)
                {
                    min = j;   
                }
                else if (compare_time(str_array->mtime[index[min]], str_array->mtime[index[j]], 
                    str_array->mtime_nsec[index[min]], str_array->mtime_nsec[index[j]]) == 0) 
                {
                    if (my_strcmp(str_array->array[index[min]], str_array->array[index[j]]) > 0)
                    {
                        min = j;
                    }
                }
            }
            else {
                if (my_strcmp(str_array->array[index[min]], str_array->array[index[j]]) > 0) {
                    min = j;
                }

            }
        }
        if (min != i) 
        { 
            int temp = index[min]; 
            index[min] = index[i]; 
            index[i] = temp; 
        } 
    }
    for(int i = 0; i<str_array->size; i++){
        result->array[i] = str_array->array[index[i]];
        result->type[i] = str_array->type[index[i]];
        result->mtime[i] = str_array->mtime[index[i]];
        result->mtime_nsec[i] = str_array->mtime_nsec[index[i]];
    }

    result->size = str_array->size;
    free(str_array->array);
    free(str_array->type);
    free(str_array->mtime);
    free(str_array->mtime_nsec);
    free(str_array);
    return result;
}

void print_folder(char *str, t_opt* opt){
    DIR *folder = opendir(str);
    struct dirent *namelist;
    file_info *sorted_list;
    sorted_list = malloc (sizeof (file_info));
    sorted_list->array = malloc(20*sizeof(char**));
    sorted_list->type = malloc(20*sizeof(int*));
    sorted_list->mtime = malloc(20*sizeof(time_t*));
    sorted_list->mtime_nsec = malloc(20*sizeof(__syscall_slong_t*)); //update
    sorted_list->size = 0;

    int i = 0;
    if (!folder){
        free(sorted_list->array);
        free(sorted_list->type);
        free(sorted_list->mtime);
        free(sorted_list->mtime_nsec);
        free(sorted_list);
        return;
    }
    struct stat filestat;
    char path_1[100];
    my_strcpy(path_1, str);
    my_strcat(path_1, "/");
    while (   (  namelist = readdir(folder) )   != NULL    ) { 
        char path_1[100];
        my_strcpy(path_1, str);
        my_strcat(path_1, "/");
        sorted_list->array[i] = namelist->d_name;
        sorted_list->type[i] = namelist->d_type;
        my_strcat(path_1, sorted_list->array[i]);
        stat(path_1, &filestat);
        sorted_list->mtime[i] = filestat.st_mtime;
        sorted_list->mtime_nsec[i] = filestat.st_mtim.tv_nsec;
        i += 1;
        sorted_list->size += 1;
    }
    
    sorted_list = sorting(sorted_list, opt); 
    print_dir(sorted_list, str, opt);

    char path[1000];
    if (opt->options & OPT_R){  //opt_R
        for(int i = 0; i<sorted_list->size; i++){ 
            if (my_strcmp(sorted_list->array[i], ".") != 0 && my_strcmp(sorted_list->array[i], "..") != 0) {
                my_strcpy(path, str);
                my_strcat(path, "/");
                my_strcat(path, sorted_list->array[i]);
                print_folder(path, opt);
            }
            
        }
    }
    free(sorted_list->array);
    free(sorted_list->type);
    free(sorted_list->mtime);
    free(sorted_list->mtime_nsec);
    free(sorted_list);
    free(namelist);
    closedir(folder);
}

void print_opt(t_opt* opt, int ac, char** av){
    char path[100];
    if (ac==1) {
        my_strcpy(path, ".");
        print_folder(path, opt);
    }
    else {
        int index = 1;
        int counter = 0;
        while (index < ac)
        {
            if (is_option(av[index]) == 0)
            {
                my_strcpy(path, av[index]);
                counter += 1;
                DIR *folder = opendir(path);
                if (!folder){
                    printf("my_ls: cannot access '%s': No such file or directory\n", path);
                }
                closedir(folder);
            }
            print_folder(path, opt);
            index += 1;
        }
        if(counter == 0){
            my_strcpy(path, ".");
            print_folder(path, opt);;
        }
    }
}
