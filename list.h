#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct _listElement {
	void                  *data;
	struct _listElement 	*next;
} ListElmt;

// (*destroy)(void *data)
// an pointer to a custom function to free allocated data

typedef struct _list {
  int                   size;
  int                   (*match)(const void *elm1, const void *elm2);
  void                  (*destroy)(void *data);
  ListElement           *head;
  ListElement           *tail;
} List;

// LINKED LIST API

void list_init(List *list, void(*destroy)(void *data));
void list_destroy(List *list);
int  list_insert_next(List *list, ListElmt *element, const void *data);
int  list_remove_next(List *list, ListElmt *element, const void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)

#endif
