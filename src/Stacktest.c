#include "Stacktest.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>


Stack *stackCreate(){
  Stack *stack = malloc (sizeof (Stack));
  //stack = (struct stack *) malloc(sizeof(stack));
  assert (stack !=NULL);
  stack->tail =NULL;
  stack->head = NULL;
  stack->length = 0;
  return stack;
}

StackElement *stackElementCreate(int data){
  StackElement *stackelem = malloc (sizeof (StackElement));
  stackelem->data =data;
  printf("value of data:%d\n", stackelem->data);
  stackelem->next = NULL;
  return stackelem;
  }
  
  
 void stackAdd (Stack *stack, StackElement *elem){
   
  if (elem == 0){
     puts ("full storage\n");
  }
  
  if (stack->head == NULL){
    stack->tail = elem;
    stack->head = elem;
    printf ("[%d] -> ", elem->data);
	stack->length=1;
  }
  else {
	  elem->next = stack->head;
	  stack->head = elem;
	  stack->length +=1;
  }
 }
 
 

 
StackElement *stackRemove(Stack *stack){
	StackElement *tempPtr, *popElem = malloc (sizeof(StackElement));
	//int popValue;
	//StackElement *pop, *popElem = malloc (sizeof(StackElement));
  if (stack->head == NULL){
    puts("nothing inside!!!!!!!!");
   return NULL;
  }
  else {
    printf ("[haed value %d]\n", stack->head);
	tempPtr = stack->head;
	popElem->data = tempPtr->data;
	popElem->next = NULL;
	//popElem->data = stack->head->data;
    stack->head = stack->head->next;
    free (tempPtr);
    stack->length -=1;
	//printf ("[pop value %d]\n", popValue);
	printf("stack length:%d\n", stack->length);
	printf("remove111 :%d\n",popElem->data);

   return popElem; 
  }
 // return popElem;
}


