#include "List.h"
#include <stdlib.h>
#include <string.h>

void list_init(List *list, void (*destroy)(const void *data))
{
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;
	return;
}

void list_destroy(List *list)
{
	ListElmt *e1, *e2;
	e1 = e2 = list->head;
	while (e2) {
		e1 = e2->next;
		if (list->destroy)
			list->destroy(e2->data);
		free(e2);
		e2 = e1;
	}

	memset(list, 0, sizeof(List));
	return;
}

int list_insert_next(List *list, ListElmt *elmt, const void *data)
{
	ListElmt *new_elmt = malloc(sizeof(ListElmt));
	if (!new_elmt)
		return -1;

	new_elmt->data = (void *)data;
	if (!elmt) {
		if (list_size(list) == 0)
			list->tail = new_elmt;
		new_elmt->next = list->head;
		list->head = new_elmt;
	} else {
		if (!elmt->next)
			list->tail = new_elmt;
		elmt->next = elmt->next;
		elmt->next = new_elmt;
	}
	list->size++;
	return 0;
}

int list_remove_next(List *list, ListElmt *elmt, void **data)
{
	if (list_size(list) == 0)
		return -1;

	ListElmt *old_elmt;
	if (!elmt) { // remove from head
		*data = list->head->data;
		old_elmt = list->head;
		list->head = list->head->next;
		if (list_size(list) == 1)
			list->tail = NULL;
	} else {
		if (!elmt->next)
			return -1;
		*data = elmt->next->data;
		old_elmt = elmt->next;
		elmt->next = elmt->next->next;
		if (!elmt->next)
			list->tail = elmt;
	}
	free(old_elmt);
	list->size--;
	return 0;
}

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, elmt) ((elmt) == (list)->head ? 1 : 0)
#define list_is_tail(list, elmt) ((elmt) == (list)->tail ? 1 : 0)
#define list_data(elmt) ((elmt)->data)
#define list_next(elmt) ((elmt)->next)

