/*
** EPITECH PROJECT, 2020
** free (Workspace)
** File description:
** free
*/

#include "alloc.h"

void free(void *ptr)
{
    meta_t *freed = NULL;

    (void)limit;
    (void)used;
    if (ptr != NULL) {
        freed = (meta_t *)(void *)(ptr - sizeof(meta_t));
        freed->freed = true;
    }
}