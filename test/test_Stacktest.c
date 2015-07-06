#include "unity.h"
#include "Stacktest.h"


void setUp(void){}

void tearDown(void){}

/*
*   headptr-->NULL
*   tailptr-->NULL
*   tempptr-->NULL
*/

void xtest_stackCreate_should_return_non_NULL_Stack_with_all_field(){
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

void xtest_stackelem_should_return_int(){

  StackElement *stackelem = malloc (sizeof (StackElement));
  stackelem = stackElementCreate (4);
  TEST_ASSERT_EQUAL  (4, stackelem->data); 
}

// /*
// *         -----    ----   ----
// * head-->| 4  |-->| 3 |-->| 2 |-->NULL
// *         ----    ----    ----
// *
// */

void test_stackadd(){
  Stack *stack = stackCreate ();
  StackElement *stackelem = malloc (sizeof (StackElement));
  StackElement *stackelem1 = stackElementCreate (2);
  StackElement *stackelem2 = stackElementCreate (3);
  StackElement *stackelem3 = stackElementCreate (4);
  stackAdd (stack, stackelem1);
  stackAdd (stack, stackelem2);
  stackAdd (stack, stackelem3);
  TEST_ASSERT_NOT_NULL (stackelem1);
  TEST_ASSERT_NOT_NULL (stackelem2);
  TEST_ASSERT_NOT_NULL (stackelem3);
  TEST_ASSERT_EQUAL (3, stack->length);
  TEST_ASSERT_EQUAL (stackelem3, stack->head);
  TEST_ASSERT_EQUAL (stackelem1, stack->tail);
  /////TEST_ASSERT_NULL(stack->tail->next);

}

// /*
// *   free --------
// *               |
// *  headPTR -->| 4|--> | 3|--> | 2|-->NULL
// *                 	   |       |
// * headnextPTR-----------        |
// *                          	  |
// *                 tailPTR-------
// */


void xtest_removestack(){
  Stack *stack = stackCreate ();
  StackElement *stackelem = malloc (sizeof (StackElement));
  StackElement *popElem= malloc (sizeof (StackElement));
  StackElement *stackelem1 = stackElementCreate (2);
  StackElement *stackelem2 = stackElementCreate (3);
  StackElement *stackelem3 = stackElementCreate (4);
  stackAdd (stack, stackelem1);
  stackAdd (stack, stackelem2);
  stackAdd (stack, stackelem3);

  popElem = stackRemove (stack);
  TEST_ASSERT_NOT_NULL (stack->head);
  TEST_ASSERT_NOT_NULL (stack->tail);
  TEST_ASSERT_EQUAL (2, stack->length);
  TEST_ASSERT_EQUAL (4, popElem->data);
  //!!!!!!!!!//TEST_ASSERT_EQUAL (NULL, stack->tail->next);
  }
  
  // /*
// *   free ---------------
// *               |      |
// *  headPTR -->| 4|--> | 3|--> | 2|-->NULL
// *                 	   |      ||
// * headnextPTR-----------------||
// *                          	   |
// *                 tailPTR-------
// */


void xtest_removestack2(){
  // Stack *stack = stackCreate ();
  // StackElement *stackelem = malloc (sizeof (StackElement));
  // StackElement *stackelem1 = stackElementCreate (2);
  // StackElement *stackelem2 = stackElementCreate (3);
  // StackElement *stackelem3 = stackElementCreate (4);
  // stackAdd (stack, stackelem1);
  // stackAdd (stack, stackelem2);
  // stackAdd (stack, stackelem3);

  // StackElement *popElem= malloc (sizeof (StackElement));
  // popElem = stackRemove (stack);
  // popElem = stackRemove (stack);
  // TEST_ASSERT_EQUAL (1, stack->length);
  // TEST_ASSERT_EQUAL (stackelem3->data, popElem->data);
  // TEST_ASSERT_EQUAL (stackelem1->data, stack->tail->data);
 // ///bad memory access TEST_ASSERT_EQUAL (2, stack->head->data);

  // //!!!!!!!TEST_ASSERT_EQUAL (stackelem2, popElem->data);
   int value1 = 1,
      value2 = 2,
      value3 = 3;
  Stack *stack = malloc (sizeof(Stack));
  stack = stackCreate();
  StackElement *element = malloc(sizeof(StackElement));
  element = stackElementCreate(value1);
  stackAdd(stack, element);
  element = stackElementCreate(value2);
  stackAdd(stack, element);
  element = stackElementCreate(value3);
  stackAdd(stack, element);

  StackElement *elemRemove1 = stackRemove(stack);
  StackElement *elemRemove2 = stackRemove(stack);
  
  TEST_ASSERT_NOT_NULL(elemRemove1);
  TEST_ASSERT_NOT_NULL(elemRemove2);
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_EQUAL(value3, elemRemove1->data);
  //TEST_ASSERT_EQUAL(value2, elemRemove2->data);
  //TEST_ASSERT_EQUAL(value1, stack->head->data);
  TEST_ASSERT_EQUAL(value1, stack->tail->data);
  TEST_ASSERT_EQUAL(1, stack->length);
  //TEST_ASSERT_NULL(stack->tail->next);
  }

/*
 *  free ------>(Nothing inside!!)
 *   headPTR--->| NULL |
 *				   |
 *	tailPTR-------|
 *
 */ 
  void xtest_stackRemove_given_empty_stack_then_do_nothing_should_return_NULL(){
  Stack *stack = stackCreate ();
  stackRemove (stack);
  
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_NULL(stack->head);
  TEST_ASSERT_NULL(stack->tail);
  TEST_ASSERT_EQUAL(0, stack->length);
}