/*
** EPITECH PROJECT, 2020
** malloc (Workspace)
** File description:
** malloc
*/

#include "alloc.h"

void *best_fit(size_t size)
{
    void *small_addr = NULL;
    size_t small_size = MAX_SIZE_T;
    meta_t *info = NULL;

    for (void *i = (void *)limit; i < (void *)(limit + used);)
        if (sbrk(0) > (void *)(i + sizeof(meta_t))) {
            info = (meta_t *)i;
            if (info->freed && info->size < small_size
            && info->size >= size) {
                small_size = info->size;
                small_addr = info;
            }
            i += sizeof(meta_t) + info->size;
        } else
            break;
    if (small_addr != NULL) {
        ((meta_t *)small_addr)->freed = false;
        return ((void *)((void *)small_addr + sizeof(meta_t)));
    }
    return (NULL);
}

void *get_new_mem(size_t size)
{
    void *best_fit_result = NULL;
    meta_t new_meta = {false, size};
    void *last_break = (void *)(limit + used);

    if ((best_fit_result = best_fit(size)) != NULL)
        return (best_fit_result);
    used += sizeof(meta_t) + new_meta.size;
    *(meta_t *)last_break = new_meta;
    return ((void *)(last_break + sizeof(meta_t)));
}

void *malloc(size_t size)
{
    limit == 0 ? limit = (unsigned long)sbrk(0) : 0;
    if (size == 0)
        return (NULL);
    if (size % 2 != 0)
        size += 1;
    if ((void *)(limit + used + sizeof(meta_t) + size) >= sbrk(0))
        if (sbrk(((int)((sizeof(meta_t) + size) / getpagesize()) * 2 + 10) *
        getpagesize()) == (void *)-1)
            return (NULL);
    return (get_new_mem(size));
}