#include "my.h"

char *my_strcat(char *dest, char *src)
{
    char *result = malloc(my_strlen(dest) + my_strlen(src) + 1);
    int i = 0;
    int j = 0;
    int len = my_strlen(dest);
    int add = 0;

    while (dest[i] != '\0') {
        result[i] = dest[i];
        i++;
    }
    if (dest[len] != '/') {
        result[len] = '/';
        add++;
    }
    while (src[j] != '\0') {
        result[i + j + add] = src[j];
        j++;
    }
    result[i + j + add] = '\0';
    return (result);
}
