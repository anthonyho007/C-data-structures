#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>


typedef _CListElmt {
  void *data;
  struct _CListElmt *next;
} CListElmt;

typedef _CList {
  int size;
  CList_Elmt *head;
  void (*destroy)(void * data);
  int (*match)(const void *key1, const void *key2);
} CList;

// API list for Circular List
void clist_init(CList *list, void(*destroy)(void *data));
void clist_destroy(CList *list);
void clist_ins_next(CList *list, CListElmt *element, void * data);
void clist_rem_next(CList *list, CListElmt *element, void ** data);

//int clist_size(CList *list);
//int clist_head(const CList *list);
//void *clist_data(const CListElmt *element);
//CListElmt *clist_next(const CListElmt *element);

// prepro. functions 
#define clist_size(list) ((list)->size)
#define clist_head(list) ((list)->head)
#define clist_data(element) ((element)->data)
#define clist_next(element) ((element)->next)

#endif
