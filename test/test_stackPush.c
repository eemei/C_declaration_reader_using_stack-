#include "unity.h"
#include "stackPush.h"
#include "mock_Token.h"
#include "addTwoToken.h"
#include <string.h>
#include "unity.h"
#include <malloc.h>
#include <stdio.h>
void setUp(void) {}

void tearDown(void) {}



void test_stack_create(void){
  Stack *stack = malloc (sizeof(Stack));
  stack = stackCreate();
  TEST_ASSERT_EQUAL(NULL, stack->head);
  TEST_ASSERT_EQUAL(0, stack->length);
}


void test_stackelement_Create(void){
	int value = 10;
	StackElement *elem= malloc(sizeof(StackElement));
	elem = stackelementCreate(&value);
	TEST_ASSERT_NOT_NULL(elem);
	TEST_ASSERT_NOT_NULL(elem->item);
	TEST_ASSERT_EQUAL(10, *(int *)elem->item);
}

void test_stackelement_CreateStr(void){
	char *str = "Hello, I am fine.";
	StackElement *elem= malloc(sizeof(StackElement));
	elem = stackelementCreate(str);
	TEST_ASSERT_NOT_NULL(elem);
	TEST_ASSERT_NOT_NULL(elem->item);
	TEST_ASSERT_EQUAL_STRING("Hello, I am fine.", (char *)(elem->item));
}

void test_Match(void){
	int tokentype = 0;
	TokenType Token = 0;
	TEST_ASSERT_EQUAL (0,match(&tokentype, Token));
}

void test_cpy(void){
	StackElement *elem;
	char *str = "foo";
	//cpy (str, (char*)elem->item);
	//TEST_ASSERT_EQUAL_STRING(cpy(str,(char *)elem->item));   *****dun know how to test !!!!
}

void test_stackadd(void){
  //fake a tree
  //   int
  //    |
  //    [
  //  /  \
  //  x   2

  
  
  // StackElement *stackelem1 = stackelementCreate (&datatype);
  // StackElement *stackelem2 = stackelementCreate (&symbol);
  // StackElement *stackelem3 = stackelementCreate (&name);
  // stackAdd (stack, stackelem1);
  // stackAdd (stack, stackelem2);
  // stackAdd (stack, stackelem3);
  // TEST_ASSERT_NOT_NULL (stackelem1);
  // TEST_ASSERT_NOT_NULL (stackelem2);
  // TEST_ASSERT_NOT_NULL (stackelem3);
  // TEST_ASSERT_EQUAL (3, stack->length);
  // TEST_ASSERT_EQUAL (stackelem3, stack->head);
  // TEST_ASSERT_EQUAL (stackelem1, stack->tail); 
}