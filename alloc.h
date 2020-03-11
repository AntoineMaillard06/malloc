/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** alloc
*/

#ifndef ALLOC_H_
#define ALLOC_H_

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

static size_t limit = 0;
static size_t used = 0;

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

typedef struct meta_s {
    bool freed;
    size_t size;
} meta_t;

#define MAX_SIZE_T 4294967295

#endif /* !ALLOC_H_ */