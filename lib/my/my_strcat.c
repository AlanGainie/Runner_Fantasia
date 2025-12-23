/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** concat two str
*/

#include <stdlib.h>
#include <string.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len_src = strlen(src);
    int len_dest = strlen(dest);
    char *tmp = malloc(sizeof(char) * (len_src + len_dest + 1));

    for (; i < len_dest; i++)
    {
        tmp[i] = dest[i];
    }
    for (int n = 0; n < len_src; n++)
    {
        tmp[i] = src[n];
        i++;
    }
    tmp[i + 1] = '\0';
    return tmp;
}
