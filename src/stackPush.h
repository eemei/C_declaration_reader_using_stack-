#ifndef stackPush_H
#define stackPush_H
#include "Token.h"
#include "addTwoToken.h"
#include <string.h>

typedef struct StackElement_t StackElement;
struct StackElement_t {
  StackElement *next;
  int type;
  void *item; 	/*let pointer point to do anything but u don't know wat type*/
};

typedef struct {
  StackElement *head;
  StackElement *tail;
  int length;
} Stack;

Stack *stackCreate();
StackElement *stackelementCreate(void *item);
StackElement *elementDestory(StackElement *elem);
void stackAdd (Stack *stack, void *item);
StackElement *stackRemove(Stack *stack);

#endif // stackPush_H