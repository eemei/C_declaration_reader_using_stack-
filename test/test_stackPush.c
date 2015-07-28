#include "unity.h"
#include "stackPush.h"
#include "Token.h"
#include "addTwoToken.h"
#include <string.h>
#include <malloc.h>
#include <stdio.h>
void setUp(void) {}
void tearDown(void) {}

void test_stack_create(void) {
  Stack *stack = malloc (sizeof(Stack));
  stack = stackCreate();
  TEST_ASSERT_EQUAL(NULL, stack->head);
  TEST_ASSERT_EQUAL(0, stack->length);
}


void test_stackelement_Create(void) {
	int value = 10;
	StackElement *elem = malloc(sizeof(StackElement));
	elem = stackelementCreate(&value);
	TEST_ASSERT_NOT_NULL(elem);
	TEST_ASSERT_NOT_NULL(elem->item);
	TEST_ASSERT_EQUAL(10, *(int *)elem->item);
}

void test_stackelement_CreateStr(void) {
	char *str = "Hello, I am fine.";
	StackElement *elem = malloc(sizeof(StackElement));
	elem = stackelementCreate(str);
	TEST_ASSERT_NOT_NULL(elem);
	TEST_ASSERT_NOT_NULL(elem->item);
	TEST_ASSERT_EQUAL_STRING("Hello, I am fine.", (char *)(elem->item));
}

/*
*				int 
*				|
*				[
*			/		\
*			x		2
*			|
*		NULL
*
*/

void test_pushfunction_and_removefunction_with_implement_a_tree(void) {
	Stack *stack = stackCreate ();
  StackElement *stackelem = malloc (sizeof (StackElement));
	OperatorToken *opeTk;
	IdentifierToken *idenTk, *leftTk;
	IntegerToken *rightTk;
	//Token *tree(char *iden, char *symbol, char *leftTkIden, char *rightTkInt);
	idenTk = (IdentifierToken *)createIdentifierToken("int", 0, 3);
	opeTk = (OperatorToken *)createOperatorToken("[", 0, 1);
	leftTk = (IdentifierToken *)createIdentifierToken("x", 0, 1);
	rightTk = (IntegerToken *)createIntegerToken("2", 0, 1);
	stackAdd (stack, idenTk->name);
	stackAdd (stack, opeTk);
	stackAdd (stack, leftTk->name);
	StackElement *popElem = malloc(sizeof (StackElement));
	popElem = stackRemove (stack);
	popElem = stackRemove (stack);
	popElem = stackRemove (stack);
	
}



















