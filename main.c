#include <assert.h>
#include <stdlib.h>
#include "aligned_realloc.h"

int main()
{
	void *p = aligned_realloc(NULL, 0, 1);
	size_t align = 1;
	p = aligned_realloc(p, align, 10);
	assert((p != NULL) && (((size_t)p & (align - 1)) == 0));

	align = 2;
	p = aligned_realloc(p, align, 100);
	assert((p != NULL) && (((size_t)p & (align - 1)) == 0));

	align = 4;
	p = aligned_realloc(p, align, 1000);
	assert((p != NULL) && (((size_t)p & (align - 1)) == 0));

	align = 8;
	p = aligned_realloc(p, align, 10000);
	assert((p != NULL) && (((size_t)p & (align - 1)) == 0));
	
	align = 16;
	p = aligned_realloc(p, align, 100000);
	assert((p != NULL) && (((size_t)p & (align - 1)) == 0));

	align = 32;
	p = aligned_realloc(p, align, 1000000);
	assert((p != NULL) && (((size_t)p & (align - 1)) == 0));

	align = 64;
	p = aligned_realloc(p, align, 10000000);
	assert((p != NULL) && (((size_t)p & (align - 1)) == 0));

	align = 32;
	p = aligned_realloc(p, align, 1000000);
	assert((p != NULL) && (((size_t)p & (align - 1)) == 0));

	align = 16;
	p = aligned_realloc(p, align, 100000);
	assert((p != NULL) && (((size_t)p & (align - 1)) == 0));

	align = 8;
	p = aligned_realloc(p, align, 10000);
	assert((p != NULL) && (((size_t)p & (align - 1)) == 0));

	align = 4;
	p = aligned_realloc(p, align, 1000);
	assert((p != NULL) && (((size_t)p & (align - 1)) == 0));

	align = 2;
	p = aligned_realloc(p, align, 100);
	assert((p != NULL) && (((size_t)p & (align - 1)) == 0));

	align = 1;
	p = aligned_realloc(p, align, 10);
	assert((p != NULL) && (((size_t)p & (align - 1)) == 0));
	
	free(p);
}
