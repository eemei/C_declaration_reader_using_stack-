#include "stackPush.h"
#include "addTwoToken.h"
#include "Token.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


Stack *stackCreate(){
  Stack *stack = malloc (sizeof(Stack));
  stack->head = NULL;
  stack->length = 0;
  return stack;
}

StackElement *stackelementCreate(void *item/*, void (*cpy)(void *), int (*match)(void *first, void *second), char *(*dpy)(void *)*/){
  StackElement *elem= malloc(sizeof(StackElement));
  // elem->cpy = cpy;
  // elem->dpy = dpy;
  // elem ->match = match;
  elem->next = NULL;
  elem->item = item;
  return elem;
}

StackElement *elementDestory(StackElement *elem){
  free(elem);
}

StackElement *stackRemove(Stack *stack){
	StackElement *tempPtr, *popElem = malloc (sizeof(StackElement));

  if (stack->head == NULL){
    puts("nothing inside!!!!!!!!");
   return NULL;
  }
  else {
    printf ("[haed value %d]\n", stack->head);
	tempPtr = stack->head;
	popElem->item = tempPtr->item;
	popElem->next = NULL;
	//popElem->data = stack->head->data;
    stack->head = stack->head->next;
    free (tempPtr);
    stack->length -=1;
	//printf ("[pop value %d]\n", popValue);
	printf("stack length:%d\n", stack->length);
	printf("remove111 :%d\n",popElem->item);

   return popElem; 
  }
}

/*
** Define a functions for handling a specific data type 
*
*		void *(*cpy)(void *) = make a deep copy of the data
*		int (*match)(void *first, void *second) = match against a token type value
* 		char *(*dpy)(void *) = format the data for display as a string
*/

// /* void stackAdd (Stack *stack, StackElement *elem /*, void *item, void (*cpy)(void *), int (*match)(void *first, TokenType Token), char *(*dpy)(void *)*/){ */
   //elem = stack ->head;
 void stackAdd (Stack *stack, StackElement *elem){
  if (elem == 0){
     puts ("full storage\n");
  }
  
  if (stack->head == NULL){
    stack->tail = elem;
    stack->head = elem;
    printf ("[@%d] -> ", elem->item);
	stack->length=1;
  }
  
  else {
	  elem->next = stack->head;
	  stack->head = elem;
    printf ("[2@%d] -> ", elem->item);
   // printf ("[token_type:%d]\n", Tk->type);
	  stack->length +=1;
  }
}

int match (void *first, TokenType Token){
  if ((*(int *)(first)) == (Token)){
	return 0;
}
else 
	return -1;
}

void *cpy(void *data, StackElement *elem){
	//StackElement *elem;
	printf("string:%s", elem->item);
return 	strcpy (elem->item,((char*)(data)) );	
}

char *dpy(void *item){
	StackElement *elem;
	printf("string:%s\n", elem->item);
}