#ifndef FT_STDLIB_H

# define FT_STDLIB_H

#include <stdlib.h>

void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);

#endif