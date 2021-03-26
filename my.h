/*
**
*/
#include <stdlib.h>
/*
**
*/
char* my_strcat (char* dest, const char* src);
char* my_strcpy (char* dest, const char* src);
int my_strcmp (const char* s1, const char* s2);
size_t my_strlen(const char* s);
void* my_memcpy (void* dest, const void* src, size_t len);
int compare_time(time_t a_sec, time_t b_sec, long a_nsec, long b_nsec);
char* my_init(int size);
void my_bzero(char* buff, int size);
void my_memset(char* buff, char c, int size);
int is_option(char* str);

