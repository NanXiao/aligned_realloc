#ifdef __APPLE__
#include <malloc/malloc.h>
#elif defined(__linux__)
#include <malloc.h>
#endif
#include <stdalign.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "aligned_realloc.h"

void *aligned_realloc(void *ptr, size_t align, size_t size)
{
	if ((size == 0) || (align <= alignof(max_align_t)))
	{
		return realloc(ptr, size);
	}
	
	size_t new_size = (size + (align - 1)) & (~(align - 1));
	void *new_ptr = aligned_alloc(align, new_size);
	if (new_ptr != NULL)
	{
		size_t old_usable_size = new_size;
	#ifdef __APPLE__
		old_usable_size = malloc_size(ptr);
	#elif defined(__linux__)
		old_usable_size = malloc_usable_size(ptr);
	#endif
		size_t copy_size = new_size < old_usable_size ? new_size : old_usable_size;
		if (ptr != NULL)
		{
			memcpy(new_ptr, ptr, copy_size);
			free(ptr);
		}
	}
	
	return new_ptr;
}

