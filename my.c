/*
**
*/
#include "my.h"
/*
**
*/
//sorting by the time
int compare_time(time_t a_sec, time_t b_sec, long a_nsec, long b_nsec){
    time_t sec_diff = a_sec - b_sec;
    long nanosec_diff = a_nsec - b_nsec;

    if (sec_diff >0)
    {
        return 1;
    }
    else if (sec_diff < 0) {
        return -1;
    }
    else {
        if (nanosec_diff>0) {
            return 1;
        }
        else if (nanosec_diff<0) {
            return -1;
        }
        else {
            return 0;
        }
    }
    return 0;
}
//for flags
int is_option(char* str)
{
    if (str[0] == '-')
    {
        return 1;
    }
    return 0;
}
//set to zero
void my_memset(char* buff, char c, int size)
{
    int index = 0;

    while(index < size)
    {
        buff[index] = c;
        index += 1;
    }
}

void my_bzero(char* buff, int size)
{
    my_memset(buff, 0, size);
}

char* my_init(int size)
{
    char* buff = (char*)malloc(size);
    my_bzero(buff, size);

    return buff;
}

void* my_memcpy(void* dest, const void* src, size_t len)
{
    char* d = dest;
    const char* s = src;
    while (len--)
    {
        *d++ = *s++;
    }
    return dest;
}

size_t my_strlen(const char* s)
{
    int i;
    for (i=0; s[i]!='\0'; ++i);
    return i;
}

int my_strcmp(const char* s1, const char* s2)
{
    for(; *s1 == *s2; ++s1, ++s2)
        if(*s1 == 0)
            return 0;
    return *(unsigned char* )s1 < *(unsigned char *)s2 ? -1 : 1;
}

char* my_strcpy(char* dest, const char* src)
{
  return my_memcpy(dest, src, my_strlen (src) + 1);
}

char* my_strcat(char* dest, const char* src)
{
    my_strcpy(dest + my_strlen (dest), src);
    return dest;
}