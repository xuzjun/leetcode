#ifndef __LIST_H__
#define __LIST_H__

typedef struct ListElmt_ {
	void *data;
	struct ListElmt_ *next;
} ListElmt;

typedef struct {
	int size;
	int (*match)(const void *i1, const void *i2);
	void (*destroy)(const void *i);
	ListElmt *head;
	ListElmt *tail;
} List;

void list_init(List *list, void (*destroy)(const void *data));
void list_destroy(List *list);
int list_insert_next(List *list, ListElmt *elmt, const void *data);
int list_remove_next(List *list, ListElmt *elmt, void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, elmt) ((elmt) == (list)->head ? 1 : 0)
#define list_is_tail(list, elmt) ((elmt) == (list)->tail ? 1 : 0)
#define list_data(elmt) ((elmt)->data)
#define list_next(elmt) ((elmt)->next)

#endif
