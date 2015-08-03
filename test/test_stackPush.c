#include "unity.h"
#include "stackPush.h"
#include "Token.h"
#include "tree.h"
#include "stackPush.h"
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


void test_stackelement_Create_an_integer(void) {
	int value = 10;
	StackElement *elem = malloc(sizeof(StackElement));
	elem = stackelementCreate(&value);
	TEST_ASSERT_NOT_NULL(elem);
	TEST_ASSERT_NOT_NULL(elem->item);
	TEST_ASSERT_EQUAL(10, *(int *)elem->item);
}

void test_stackelement_Create_a_pointer(void) {
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
void test_display_tree(void) {
	Stack *stack = stackCreate ();
	Token *token;
	token = secondTree("int", "*", "[", "2", "app");
	PushTree(token, stack);

  TEST_ASSERT_EQUAL_STRING("int", ((IdentifierToken *)token)->name);
  TEST_ASSERT_EQUAL_STRING("*", ((OperatorToken *)((IdentifierToken*)token)->token)->symbol);
  TEST_ASSERT_EQUAL_STRING("[", ((OperatorToken *)((OperatorToken *)((IdentifierToken*)token)->token)->token[0])->symbol);
  //TEST_ASSERT_EQUAL(2, ((IntegerToken *)((OperatorToken *)((IdentifierToken*)token)->token)->token[1])->value);
  TEST_ASSERT_EQUAL_STRING("app", ((IdentifierToken *)((OperatorToken *)((OperatorToken *)((IdentifierToken*)token)->token)->token[0])->token[0])->name);
}