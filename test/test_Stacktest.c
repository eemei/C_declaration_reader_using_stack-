#include "unity.h"
#include "Stacktest.h"


void setUp(void){}

void tearDown(void){}

/*
*   headptr-->NULL
*   tailptr-->NULL
*   tempptr-->NULL
*/

void test_stackCreate_should_return_non_NULL_Stack_with_all_field(){
  Stack *stack = stackCreate ();
  TEST_ASSERT_NOT_NULL (stack);
  TEST_ASSERT_EQUAL (NULL, stack->tail);
  TEST_ASSERT_EQUAL (NULL, stack->head);
  TEST_ASSERT_EQUAL (0, stack->length);
}

/*
*         -----
*  head-->| 4 |---->NULL
*  tail-->|   |
*         ----
*/

void test_stackelem_should_return_int(){
  struct StackElement *stackelem = malloc (sizeof (StackElement));
  stackelem = StackElementCreate (4);
  TEST_ASSERT_EQUAL  (4, stackelem->data); 
}

/*
*         -----    ----   ----
* head-->| 4  |-->| 3 |-->| 2 |-->NULL
*         ----    ----    ----
*
*/

void test_stackadd(){
  Stack *stack = stackCreate ();
  struct StackElement *stackelem = malloc (sizeof (StackElement));
  StackElement *stackelem1 = StackElementCreate (2);
  StackElement *stackelem2 = StackElementCreate (3);
  StackElement *stackelem3 = StackElementCreate (4);
  stackAdd (stack, stackelem1);
  stackAdd (stack, stackelem2);
  stackAdd (stack, stackelem3);
  TEST_ASSERT_NOT_NULL (stackelem1);
  TEST_ASSERT_NOT_NULL (stackelem2);
  TEST_ASSERT_NOT_NULL (stackelem3);
  TEST_ASSERT_EQUAL (3, stack->length);
  TEST_ASSERT_EQUAL (stackelem3, stack->head);
  TEST_ASSERT_EQUAL (stackelem1, stack->tail);
  
}

/*
*   free --------
*               |
*  headPTR -->| 4|--> | 3|--> | 2|-->NULL
*                 	   |       |
* headnextPTR-----------       |
*                          	   |
*                 tailPTR-------
*/


void test_removestack(){
  Stack *stack = stackCreate ();
  struct StackElement *stackelem = malloc (sizeof (StackElement));
  StackElement *stackelem1 = StackElementCreate (2);
  StackElement *stackelem2 = StackElementCreate (3);
  StackElement *stackelem3 = StackElementCreate (4);
  stackAdd (stack, stackelem1);
  stackAdd (stack, stackelem2);
  stackAdd (stack, stackelem3);

  struct StackElement *remove = malloc (sizeof (StackElement));
  remove = stackRemove (stack);
  TEST_ASSERT_EQUAL (2, stack->length);
  }
  
  /*
*   free ---------------
*               |      |
*  headPTR -->| 4|--> | 3|--> | 2|-->NULL
*                 	   |      ||
* headnextPTR-----------------||
*                          	   |
*                 tailPTR-------
*/


void test_removestack2(){
  Stack *stack = stackCreate ();
  struct StackElement *stackelem = malloc (sizeof (StackElement));
  StackElement *stackelem1 = StackElementCreate (2);
  StackElement *stackelem2 = StackElementCreate (3);
  StackElement *stackelem3 = StackElementCreate (4);
  stackAdd (stack, stackelem1);
  stackAdd (stack, stackelem2);
  stackAdd (stack, stackelem3);

  struct StackElement *remove = malloc (sizeof (StackElement));
  remove = stackRemove (stack);
  remove = stackRemove (stack);
  TEST_ASSERT_EQUAL (1, stack->length);
  }

/*
 *  free ------>(Nothing inside!!)
 *   headPTR--->| NULL |
 *				   |
 *	tailPTR-------|
 *
 */ 
  void test_stackRemove_given_empty_stack_then_do_nothing_should_return_NULL(){
  Stack *stack = stackCreate ();
  stackRemove (stack);
  
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_NULL(stack->head);
  TEST_ASSERT_NULL(stack->tail);
  TEST_ASSERT_EQUAL(0, stack->length);
}