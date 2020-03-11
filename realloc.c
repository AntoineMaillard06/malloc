/*
** EPITECH PROJECT, 2020
** realloc (Workspace)
** File description:
** realloc
*/

#include "alloc.h"

void *realloc(void *ptr, size_t size)
{
    void *new_ptr = NULL;

    (void)limit;
    (void)used;
    if (ptr == NULL) {
        return (malloc(size));
    } else if (((meta_t *)(ptr - sizeof(meta_t)))->size != size) {
        new_ptr = malloc(size);
        if (new_ptr == NULL || size == 0)
            return (NULL);
        free(ptr);
        if (size > ((meta_t *)(ptr - sizeof(meta_t)))->size)
            memcpy(new_ptr, ptr, ((meta_t *)(ptr - sizeof(meta_t)))->size);
        else
            memcpy(new_ptr, ptr, size);
        return (new_ptr);
    } else {
        return (ptr);
    }
}