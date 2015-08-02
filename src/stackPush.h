#ifndef stackPush_H
#define stackPush_H
#include "Token.h"
#include "tree.h"
#include "switchCase.h"
#include <string.h>

typedef struct StackElement_t StackElement;
struct StackElement_t {
  StackElement *next;
  int type;
  void *item; 	
};

typedef struct {
  StackElement *head;
  StackElement *tail;
  int length;
} Stack;

Stack *stackCreate();
StackElement *stackelementCreate(void *item);
StackElement *elementDestory(StackElement *elem);
void push(Stack *stack, void *item);
StackElement *pop(Stack *stack);
void displayToken(Token *token);
#endif // stackPush_H