#ifndef Stacktest_H
#define Stacktest_H
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef struct StackElement StackElement;

struct StackElement
{
  StackElement *next;
  int data;
};

typedef struct
{
  StackElement *head;
  StackElement *tail;
  int length;
} Stack;

Stack *stackCreate();
StackElement *stackElementCreate(int data);
void stackAdd(Stack *stack, StackElement *elem);
StackElement *stackRemove(Stack *stack);

#endif // Stacktest_H
