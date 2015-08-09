#include "stackPush.h"
#include "tree.h"
#include "Token.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

/*
* create a stack
* ---------- 
* | Head   |
*  ________
* | Tail  |
* ________
* |length|
* --------
*/
Stack *stackCreate() {
  Stack *stack = malloc (sizeof(Stack));
  stack->head = NULL;
  stack->length = 0;
  return stack;
}

/*  any pointer can be add into the stack */
StackElement *stackelementCreate(void *item){
  StackElement *elem= malloc(sizeof(StackElement));
  elem->next = NULL;
  elem->item = item;
  return elem;
}

StackElement *elementDestory(StackElement *elem) {
  free(elem);
}

/* 
* push element :
*   ->push the item into the stack
*   ->keep on adding on the top of the first item
*   ->the last adding item at the top 
*   ->the first adding item at the bottom 
*/
void push(Stack *stack, void *item) {
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

/* 
* pop element :
*   -> pop the first element at the top (which the head pointer there) 
*   -> until the head pointer empty 
*/
StackElement *pop(Stack *stack) {
  StackElement *tempPtr, *popElem = malloc (sizeof(StackElement));

  if (stack->head == NULL) {
  puts("nothing inside!!!!!!!!");
  return NULL;
  }
  else {
  //printf ("[ head address: %d ]\n", stack->head);
  tempPtr = stack->head;
  popElem->item = tempPtr->item;
  popElem->next = NULL;
  stack->head = stack->head->next;
  free (tempPtr);
  stack->length -=1;
  //printf("< stack length: %d >\n", stack->length);
  printf("< remove: %s>\n",popElem->item);

  return popElem; 
  }
}

/* 	
* "PushTree" use the recursive concept to get each token inside a tree  
*   -> after get the token (item) then pull into "push"   
*   -> go along left hand side until meet the NULL 
*/
void PushTree(Token *token, Stack *stack) {
  if(token != NULL) {
    if(token->type == TOKEN_IDENTIFIER_TYPE) {
      //printf("token name = %s \n", ((IdentifierToken *)token)->name);
      push(stack, ((IdentifierToken *)token)->name);
      PushTree(((IdentifierToken *)token)->token, stack);
    }
    else if(token->type == TOKEN_OPERATOR_TYPE) {
      if (!strcmp(((OperatorToken *)token)->symbol, "[")) {
        //printf("token int = %d \n",  ((IntegerToken *)(((OperatorToken *)token)->token[1]))->value);
        //printf("token symbol = %s \n", ((OperatorToken *)token)->symbol);
        push(stack, token);
        PushTree(((OperatorToken *)token)->token[0], stack);
      }
      else {
        //printf("token symbol = %s \n", ((OperatorToken *)token)->symbol);
        push(stack, token);
        PushTree(((OperatorToken *)token)->token[0], stack);
        }
    }		
  }
}

/*
* "removeToken" also use recursive concept to read the token inside the "pop"
*   -> once the token (item) pop out then read the token 
*/
void removeToken(Token *token, Stack *stack) {
  if (token != NULL) {
    if (token->type == TOKEN_IDENTIFIER_TYPE) {
      pop(stack);
      removeToken(((IdentifierToken *)token)->token, stack);
      if (!strcmp(((IdentifierToken *)token)->name, "double")) {
        printf(" %s.\n", ((IdentifierToken *)token)->name);
      }
      else if (!strcmp(((IdentifierToken *)token)->name, "float")) {
        printf(" %s.\n", ((IdentifierToken *)token)->name);
      }
      else if (!strcmp(((IdentifierToken *)token)->name, "char")) {
        printf(" %s.\n", ((IdentifierToken *)token)->name);
      }
      else if (!strcmp(((IdentifierToken *)token)->name, "int")) {
        printf(" %s.\n", ((IdentifierToken *)token)->name);
      }
      else if (!strcmp(((IdentifierToken *)token)->name, "void")) {
        printf(" %s.\n", ((IdentifierToken *)token)->name);
      }
      else if (!strcmp(((IdentifierToken *)token)->name, "unsigned int")) {
        printf(" %s.\n", ((IdentifierToken *)token)->name);
      }
      else if (!strcmp(((IdentifierToken *)token)->name, "unsigned char")) {
        printf(" %s.\n", ((IdentifierToken *)token)->name);
      }
      else if (!strcmp(((IdentifierToken *)token)->name, "short")) {
        printf(" %s.\n", ((IdentifierToken *)token)->name);
      }
      else if (!strcmp(((IdentifierToken *)token)->name, "unsigned short")) {
        printf(" %s.\n", ((IdentifierToken *)token)->name);
      }
      else if (!strcmp(((IdentifierToken *)token)->name, "long")) {
        printf(" %s.\n", ((IdentifierToken *)token)->name);
      }
      else if (!strcmp(((IdentifierToken *)token)->name, "unsigned long")) {
        printf(" %s.\n", ((IdentifierToken *)token)->name);
      }
      else if (!strcmp(((IdentifierToken *)token)->name, "long double")) {
        printf(" %s.\n", ((IdentifierToken *)token)->name);
      }
      else {
        printf(" %s is", ((IdentifierToken *)token)->name);
      }
    }
    else if (token->type == TOKEN_OPERATOR_TYPE) {
      pop(stack);
      removeToken(((OperatorToken *)token)->token[0], stack);
        if (!strcmp(((OperatorToken *)token)->symbol, "*")) {
          printf(" pointer to");
        }
        else if (!strcmp(((OperatorToken *)token)->symbol, "[")) {
          printf(" array %d of",  ((IntegerToken *)(((OperatorToken *)token)->token[1]))->value);
        }
        else if (!strcmp(((OperatorToken *)token)->symbol, "(")) {
          printf(" function taking %s returning", ((IdentifierToken *)(((OperatorToken *)token)->token[1]))->name);
        }
    }
  }
}