/*
** EPITECH PROJECT, 2020
** calloc (Workspace)
** File description:
** calloc
*/

#include "alloc.h"

void *calloc(size_t nmemb, size_t size)
{
    unsigned long long res = nmemb * size;
    void *ptr = NULL;

    (void)limit;
    (void)used;
    if (res == 0)
        return (NULL);
    if (res <= MAX_SIZE_T) {
        ptr = malloc(nmemb * size);
        return (memset(ptr, 0, nmemb * size));
    } else {
        return (NULL);
    }
}