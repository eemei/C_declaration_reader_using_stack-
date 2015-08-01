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

/**		this function to test the error code  
*					 @# -->operatorTokenType
*					/	\
*				*		NULL
*			/  \
*	 	x   NULL
*		|
*		NULL
*/

void test_pushfunction_and_removefunction_with_implement_a_tree(void) {
	Token *token;
	//token = tree("int", "[", "x", "2"); 
	//token = errorTree("@#", "*", "x");
	token = secondTree("int", "*", "[", "2", "app"); 
	moveInsideTree(token);


}