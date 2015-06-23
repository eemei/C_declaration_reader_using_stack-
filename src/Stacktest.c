#include "Stacktest.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>


struct Stack *stackCreate(){
  Stack *stack = malloc (sizeof (Stack));
  //stack = (struct stack *) malloc(sizeof(stack));
  assert (stack !=NULL);
  stack->tail =NULL;
  stack->head = NULL;
  stack->length = 0;
  return stack;
}

struct stackElement *StackElementCreate (int data){
  struct StackElement *stackelem = malloc (sizeof (StackElement));
  stackelem->data =data;
  printf("value of data:%d\n", stackelem->data);
  stackelem->next = NULL;
  return stackelem;
  }
  
  
 void stackAdd (struct Stack *stack, struct StackElement *elem){
   
  if (elem == 0){
     puts ("full storage\n");
  }
  
  if (stack->head == NULL){
    stack->tail = elem;
    stack->head = elem;
    printf ("[%d] -> ", elem->data);
	////stack->length=1;
  }
  
  else {
   // stack->tail = stack->head;
   stack->head = elem;
	////elem->next = stack->head;
	////stack->head = elem;
   while (stack->head != NULL ){
	  printf("head address[%d]\n", stack->head);
	  printf("tail address[%d]\n", stack->tail);
      printf("[%d]-->\n", elem->data);
      stack->head = stack->head->next;
    }
  stack->head = elem;
  }
  stack->head->next = elem;
  stack->length +=1; 
 }
 
 

 
struct StackElement *stackRemove (struct Stack *stack){
	struct StackElement *tempPtr;
	int popValue;
// struct StackElement *pop, *popElem = malloc (sizeof(StackElement));
  if (stack->head == NULL){
    puts("nothing inside!!!!!!!!");
   return 0;
  }
  else {
    printf ("[remove value %d]\n", stack->head->data);
	tempPtr = stack->head;
	popValue = stack->head->data;
    stack->head = stack->head->next;
    free (tempPtr);
    stack->length -=1;
	//printf ("[pop value %d]\n", popValue);
    return popValue;
  }
}