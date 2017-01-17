#include <stdio.h>
#include "heap.h"

int cmp(const void *a, const void *b)
{
	return *(int *)a > *(int *)b;
}

int main()
{
	heap_t h;

	heap_init(&h, cmp, NULL);

	int a = 5;
	heap_insert(&h, &a);
	void *b;
	heap_extract(&h, &b);

	printf("b [%d]\n", *(int *)b);
	return 0;
}
