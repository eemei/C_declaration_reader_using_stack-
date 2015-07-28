#include "stackPush.h"
#include "addTwoToken.h"
#include "Token.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

Stack *stackCreate() {
  Stack *stack = malloc (sizeof(Stack));
  stack->head = NULL;
  stack->length = 0;
  return stack;
}

StackElement *stackelementCreate(void *item){
  StackElement *elem= malloc(sizeof(StackElement));
  elem->next = NULL;
  elem->item = item;
  return elem;
}

StackElement *elementDestory(StackElement *elem) {
  free(elem);
}

StackElement *stackRemove(Stack *stack) {
	StackElement *tempPtr, *popElem = malloc (sizeof(StackElement));

  if (stack->head == NULL) {
    puts("nothing inside!!!!!!!!");
   return NULL;
  }
  else {
  printf ("[head value %d]\n", stack->head);
	tempPtr = stack->head;
	popElem->item = tempPtr->item;
	popElem->next = NULL;
	//popElem->data = stack->head->data;
  stack->head = stack->head->next;
  free (tempPtr);
  stack->length -=1;
	//printf ("[pop value %s]\n", popValue);
	printf("stack length:%d\n", stack->length);
	printf("remove111 :%s\n",popElem->item);

   return popElem; 
  }
}

// /* void stackAdd (Stack *stack, StackElement *elem /*, void *item, void (*cpy)(void *), int (*match)(void *first, TokenType Token), char *(*dpy)(void *)*/){ */
   //elem = stack ->head;
void stackAdd (Stack *stack, void *item){
	StackElement *elem = stackelementCreate(item);
  if (elem == 0){
    puts ("full storage\n");
  }
  
  if (stack->head == NULL){
    stack->tail = elem;
    stack->head = elem;
    printf ("[@%s] -> ", (char *)elem->item);
		stack->length=1;
  }
  
  else {
		elem->next = stack->head;
		stack->head = elem;
		printf ("[2@%s] -> ", (char *)elem->item);
   // printf ("[token_type:%d]\n", Tk->type);
	  stack->length +=1;
  }
}
