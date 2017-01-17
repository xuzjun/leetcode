#ifndef __HEAP_H__
#define __HEAP_H__

typedef struct heap_s {
	int size;
	int (*compare)(const void *key1, const void *key2);
	void (*destroy)(void *data);
	void **tree;
} heap_t;

void heap_init(heap_t *h, int (*compare)(const void *key1, const void *key2),
               void (*destroy)(void *data));
int heap_insert(heap_t *h, const void *data);
int heap_extract(heap_t *h, void **data);
void heap_destroy(heap_t *h);
#define heap_size(h) ((h)->size)

#endif
