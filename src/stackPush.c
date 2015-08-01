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

StackElement *pop(Stack *stack) {
	StackElement *tempPtr, *popElem = malloc (sizeof(StackElement));

  if (stack->head == NULL) {
    puts("nothing inside!!!!!!!!");
   return NULL;
  }
  else {
  printf ("[ head address: %d ]\n", stack->head);
	tempPtr = stack->head;
	popElem->item = tempPtr->item;
	popElem->next = NULL;
	//popElem->data = stack->head->data;
  stack->head = stack->head->next;
  free (tempPtr);
  stack->length -=1;
	printf("< stack length: %d\n >", stack->length);
	printf("< remove: %s\n >",popElem->item);

   return popElem; 
  }
}

void push(Stack *stack, void *item){
	StackElement *elem = stackelementCreate(item);
  if (elem == 0){
    puts ("full storage\n");
  }
  
  if (stack->head == NULL){
    stack->tail = elem;
    stack->head = elem;
    printf ("[@  %s ] -> \n", (char *)elem->item);
		stack->length=1;
  }
  
  else {
		elem->next = stack->head;
		stack->head = elem;
		printf ("[2@  %s ] -> \n", (char *)elem->item);
	  stack->length +=1;
  }
}
/* 	1) push the token until the left hand side meet the NULL
*		2) pop the token and read 
**/
void moveInsideTree(Token *token) {
	Stack *stack = stackCreate ();
	if(token != NULL) {
		if(token->type == TOKEN_IDENTIFIER_TYPE) {
			moveInsideTree(((IdentifierToken *)token)->token);
			printf("token name = %s \n", ((IdentifierToken *)token)->name);
			push(stack, ((IdentifierToken *)token)->name);
		}
		else if(token->type == TOKEN_OPERATOR_TYPE) {
			moveInsideTree(((OperatorToken *)token)->token[0]);
			printf("token symbol = %s \n", ((OperatorToken *)token)->symbol);
			push(stack, ((OperatorToken *)token)->symbol);
		}		
	}
}