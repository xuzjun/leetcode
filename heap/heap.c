#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

#define heap_ppos(pos)  ((int)((pos - 1) / 2))
#define heap_lcpos(pos) ((int)(2 * pos + 1))
#define heap_rcpos(pos) ((int)(2 * pos + 2))

void heap_init(heap_t *h, int (*compare)(const void *key1, const void *key2), void (*destroy)(void *data))
{
	h->size = 0;
	h->compare = compare;
	h->destroy = destroy;
	h->tree = NULL;
	return;
}

void heap_destroy(heap_t *h)
{
	int i;
	if (h->destroy)
		for (i = 0; i < heap_size(h); ++i)
			h->destroy(h->tree[i]);

	free(h->tree);
	memset(h, 0, sizeof(heap_t));
	return;
}

int heap_insert(heap_t *h, const void *data)
{
	void *tmp = (void **)realloc(h->tree, (heap_size(h) + 1) * sizeof(void *));

	if (tmp == NULL)
		return -1;

	h->tree = tmp;
	h->tree[heap_size(h)] = (void *)data;
	int ipos = heap_size(h);
	int ppos = heap_ppos(ipos);
	while (ipos > 0 && h->compare(h->tree[ipos], h->tree[ppos]) > 0) {
		tmp = h->tree[ipos];
		h->tree[ipos] = h->tree[ppos];
		h->tree[ppos] = tmp;
		ipos = ppos;
		ppos = heap_ppos(ipos);
	}

	h->size++;
	return 0;
}

int heap_extract(heap_t *h, void **data)
{
	if (heap_size(h) == 0)
		return -1;

	*data = h->tree[0];
	void *tmp;
	if (heap_size(h) - 1 > 0) {
		void *save = h->tree[heap_size(h)];
		tmp = realloc(h->tree, (heap_size(h) - 1) * sizeof(void *));
		h->tree = tmp;
		h->tree[0] = save;
		h->size--;
	} else {
		free(h->tree);
		h->tree = NULL;
		h->size--;
		return 0;
	}

	int ipos = 0;
	int lcpos = heap_lcpos(ipos);
	int rcpos = heap_rcpos(ipos);
	while (1) {
		if ((lcpos > heap_size(h) - 1) && (h->compare(h->tree[ipos], h->tree[lcpos]) < 0)) {
			tmp = h->tree[ipos];
			h->tree[ipos] = h->tree[lcpos];
			h->tree[lcpos] = tmp;
			ipos = lcpos;
			lcpos = heap_lcpos(ipos);
			rcpos = heap_rcpos(ipos);
		} else if ((rcpos > heap_size(h) - 1) && (h->compare(h->tree[ipos], h->tree[rcpos]) > 0)) {
			tmp = h->tree[ipos];
			h->tree[ipos] = h->tree[rcpos];
			h->tree[rcpos] = tmp;
			ipos = rcpos;
			lcpos = heap_lcpos(ipos);
			rcpos = heap_rcpos(ipos);
		} else {
			break;
		}
	}

	return 0;
}
