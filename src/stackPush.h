#ifndef stackPush_H
#define stackPush_H
#include "Token.h"
#include <string.h>

typedef struct StackElement_t StackElement;
struct StackElement_t{
  StackElement *next;
  int type;
  void *item; 	/*let pointer point to do anything but u don't know wat type*/
  void (*cpy)(void *);
  int (*match)(void *first, void *second);
  char *(*dpy)(void *);
};

typedef struct{
  StackElement *head;
  StackElement *tail;
  int length;
} Stack;

Stack *stackCreate();
StackElement *stackelementCreate(void *item);
StackElement *elementDestory(StackElement *elem);
void stackAdd (Stack *stack, StackElement *elem);
int match (void *first, TokenType Token);
void *cpy(void *data, StackElement *elem);   //cpy is pointer to void return void.
char *dpy(void *item);
StackElement *stackRemove(Stack *stack);
#endif // stackPush_H
