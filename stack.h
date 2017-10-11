#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include "list.h"
// structs
typedef List Stack;

// APIs
#define stack_init list_init
#define stack_destroy list_destroy
void stack_push(Stack *stack, const void *data);
void stack_pop(Stack *stack, void **data);
#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data) 
#define stack_size list_size
#endif
