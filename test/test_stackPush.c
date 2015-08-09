#include "unity.h"
#include "stackPush.h"
#include "Token.h"
#include "tree.h"
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
  TEST_ASSERT_EQUAL_STRING("Hello, I am fine.", (char *)(elem->item));
  TEST_ASSERT_NOT_NULL(elem);
  TEST_ASSERT_NOT_NULL(elem->item);
}
/* 
*             int 
*             |
*             *
*           /   \
*           [ null
*           /   \
*          app   2
*				
*   int *app[2];
*     app is array 2 of pointer to int. 
*/
void test_declaration_app_is_array_of_pointer_to_int(void) {
  Stack *stack = stackCreate ();
  Token *token;
  token = secondTree("int", "*", "[", "2", "app");
  PushTree(token, stack);
  // pop (stack);
  // pop (stack);
  // pop (stack);
  // pop (stack);
  removeToken(token, stack);
 // pop (stack);
 // removeToken(token, stack);
  TEST_ASSERT_EQUAL_STRING("int", ((IdentifierToken *)token)->name);
  TEST_ASSERT_EQUAL_STRING("*", ((OperatorToken *)((IdentifierToken*)token)->token)->symbol);
  TEST_ASSERT_EQUAL_STRING("[", ((OperatorToken *)((OperatorToken *)((IdentifierToken*)token)->token)->token[0])->symbol);
  TEST_ASSERT_EQUAL_STRING("app", ((IdentifierToken *)((OperatorToken *)((OperatorToken *)((IdentifierToken*)token)->token)->token[0])->token[0])->name);
}
/*        long
*          |
*         (
*       /   \
*     foo   NULL 
*
*   long foo( );
*     foo is function taking nothing returning long.
*/
void test_declaration_foo_is_function_taking_nothing_returning_long(void) {
  Stack *stack = stackCreate ();
  Token *token;
  token = fooisFuncreturnNoth("long", "(", "foo", "NULL");
  PushTree(token, stack);
  removeToken(token, stack);
  
  TEST_ASSERT_EQUAL_STRING("long", ((IdentifierToken *)token)->name);
  TEST_ASSERT_EQUAL_STRING("(", ((OperatorToken *)((IdentifierToken*)token)->token)->symbol);
  TEST_ASSERT_EQUAL_STRING("foo", ((IdentifierToken *)((OperatorToken *)((IdentifierToken*)token)->token)->token[0])->name);
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
*		int x[2];
*			x is array 2 of int.
*/
void test_declaration_x_is_array_2_of_int(void) {
  Stack *stack = stackCreate ();
  Token *token;
  token = tree("int", "[", "x", "2");
  PushTree(token, stack);
  removeToken(token, stack);
  
  TEST_ASSERT_EQUAL_STRING("int", ((IdentifierToken *)token)->name);
  TEST_ASSERT_EQUAL_STRING("[", ((OperatorToken *)((IdentifierToken*)token)->token)->symbol);
  TEST_ASSERT_EQUAL_STRING("x", ((IdentifierToken *)((OperatorToken *)((IdentifierToken*)token)->token)->token[0])->name);
}
/* 
*        double 
*           |					
*           y
*           |
*          NULL
*
*   double y;
*     y is double
*/ 
void test_declaration_y_is_double(void) {
  Stack *stack = stackCreate ();
  Token *token;
  token = YisDouble("double", "y");
  PushTree(token, stack);
  removeToken(token, stack);
  
  TEST_ASSERT_EQUAL_STRING("double", ((IdentifierToken *)token)->name);
  TEST_ASSERT_EQUAL_STRING("y", ((IdentifierToken *)((IdentifierToken*)token)->token)->name);
}
/* 
*							float
*							|
*							*
*						/ \						
*					*		NULL
*				/  \
*       y		NULL
*
*		float **y;
*     y is pointer to pointer to float.	
*/
void test_declaration_y_is_pointer_to_pointer_to_float(void) {
  Stack *stack = stackCreate ();
  Token *token;
  token = yisPointertoPointer("float", "*", "*", "y");
  PushTree(token, stack);
  removeToken(token, stack);
  
  TEST_ASSERT_EQUAL_STRING("float", ((IdentifierToken *)token)->name);
  TEST_ASSERT_EQUAL_STRING("*", ((OperatorToken *)((IdentifierToken*)token)->token)->symbol);
  TEST_ASSERT_EQUAL_STRING("*", ((OperatorToken *)((OperatorToken *)((IdentifierToken*)token)->token)->token[0])->symbol);
  TEST_ASSERT_EQUAL_STRING("y", ((IdentifierToken *)((OperatorToken *)((OperatorToken *)((IdentifierToken*)token)->token)->token[0])->token[0])->name);
}
/* 
*       char
*         |
*         (
*       /   \
*     foo   int 
*
*   char foo(int );
*     foo is function taking int returning char.
*/
void test_declaration_foo_is_function_taking_int_returning_char(void) {
  Stack *stack = stackCreate ();
  Token *token;
  token = fooisFunc("char", "(", "foo", "int");
  PushTree(token, stack);
  removeToken(token, stack);
  
  TEST_ASSERT_EQUAL_STRING("char", ((IdentifierToken *)token)->name);
  TEST_ASSERT_EQUAL_STRING("(", ((OperatorToken *)((IdentifierToken*)token)->token)->symbol);
  TEST_ASSERT_EQUAL_STRING("foo", ((IdentifierToken *)((OperatorToken *)((IdentifierToken*)token)->token)->token[0])->name);
}
/*        int 
*         |
*         [
*      /   \
*     [     2
*   /   \
* dog   4
*
*   int dog[4][2];
*     dog is array 4 of array 2 of int.
*/
void test_declaration_dog_is_array_4_of_array_2_of_int(void) {
  Stack *stack = stackCreate ();
  Token *token;
  token = dogarrayarray("[", "[", "int", "dog", "2", "4");
  PushTree(token, stack);
  removeToken(token, stack);  
  
  TEST_ASSERT_EQUAL_STRING("int", ((IdentifierToken *)token)->name);
  TEST_ASSERT_EQUAL_STRING("[", ((OperatorToken *)((IdentifierToken*)token)->token)->symbol);
  TEST_ASSERT_EQUAL_STRING("[", ((OperatorToken *)((OperatorToken *)((IdentifierToken*)token)->token)->token[0])->symbol);
  TEST_ASSERT_EQUAL_STRING("dog", ((IdentifierToken *)((OperatorToken *)((OperatorToken *)((IdentifierToken*)token)->token)->token[0])->token[0])->name);
}
/* 
*									float
*										|
*										*
*									/  \
*								[  NULL
*							/  \	
*						*		 4
*					/  \
*				[			NULL
*			/  \
*			y   2
*			|
*			NULL
*
*		float *(*y[2])[4];
*			y is array 2 of pointer to array 4 of pointer to float.	
*/
void test_declaration_y_is_array_2_of_pointer_to_array_4_of_pointer_to_float(void) {
  Stack *stack = stackCreate ();
  Token *token;
  token = yArrayPointer("float", "*", "[", "*", "4", "[", "2", "y");
  PushTree(token, stack);
  removeToken(token, stack);  
}