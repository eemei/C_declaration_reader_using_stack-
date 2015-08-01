#include "unity.h"
#include "addTwoToken.h"
#include "Token.h"
#include <malloc.h>
#include <stdio.h>

void setUp(void) {}
void tearDown(void) {}

/*  
*						operatorToken					example
*					_________________	  						 [
*				|  symbol "["	   |								/ \
*				-----------------			    		   x  2
*				|   Token[0]	 	|
*				-----------------
*				|   Token[1]		|
*				_________________
*			/									\
*	___idenTOKEN__			_integerTOKEN_
*	|	  type	  |				| 	type  	|
*	--------------		----------------
*	| 	name	 |				|  value		|
*	_____________			_______________
*/
  
/*
*				int 
*				|
*				[
*			/		\
*			x		2
*			|
*		NULL
*/
void test_create_a_tree_x_is_array_two_of_int(void) {
	IdentifierToken *root;
	OperatorToken *opeTk;
	IdentifierToken *idenTk, *leftTk;
	IntegerToken *rightTk;
	
	idenTk = (IdentifierToken *)createIdentifierToken("int", 0, 3);
	opeTk = (OperatorToken *)createOperatorToken("[", 0, 1);
	leftTk = (IdentifierToken *)createIdentifierToken("x", 0, 1);
	rightTk = (IntegerToken *)createIntegerToken("2", 0, 1);
	idenTk->token = (Token *)opeTk;
	opeTk->token[0] = (Token *)leftTk;
	opeTk->token[1] = (Token *)rightTk;
	leftTk->token = NULL;
	
	root = (IdentifierToken *)tree("int", "[", "x", "2"); 

	TEST_ASSERT_EQUAL_STRING(idenTk->name, root->name);
	TEST_ASSERT_EQUAL_STRING(root->name, "int" );
	TEST_ASSERT_EQUAL_STRING(opeTk->symbol, "[");
	TEST_ASSERT_EQUAL_STRING(leftTk->name, "x");
	TEST_ASSERT_EQUAL(rightTk->value, 2);
	TEST_ASSERT_EQUAL_PTR(idenTk->token,opeTk ); 
	TEST_ASSERT_EQUAL_PTR(opeTk->token[0], leftTk);
	TEST_ASSERT_EQUAL_PTR(opeTk->token[1], rightTk);
}
/**		this function to test the error code  
*					 @# -->operatorTokenType
*					/	\
*				*		NULL
*			/  \
*	 	x   NULL
*		|
*		NULL
*/

test_the_errorTree(void) {
	OperatorToken *root;
	OperatorToken *opeTk, *idenTk;
	IdentifierToken *leftTk;
	
	idenTk = (OperatorToken *)createOperatorToken("@#", 0, 2);
	opeTk = (OperatorToken *)createOperatorToken("*", 0, 1);
	leftTk = (IdentifierToken *)createIdentifierToken("x", 0, 1);
	idenTk->token[0] = (Token *)opeTk;
	idenTk->token[1] = NULL;
	opeTk->token[0] = (Token *)leftTk;
	opeTk->token[1] = NULL;
	leftTk->token = NULL;
	
	root = (OperatorToken *)errorTree("@#", "*", "x"); 

	TEST_ASSERT_EQUAL_STRING(idenTk->symbol, root->symbol);
	TEST_ASSERT_EQUAL_STRING(root->symbol, "@#");
	TEST_ASSERT_EQUAL_STRING(opeTk->symbol, "*");
	TEST_ASSERT_EQUAL_STRING(leftTk->name, "x");
	TEST_ASSERT_EQUAL_PTR(idenTk->token[0],opeTk); 
	TEST_ASSERT_EQUAL(idenTk->token[1], NULL);
	TEST_ASSERT_EQUAL(opeTk->token[1] , NULL);
	TEST_ASSERT_EQUAL(leftTk->token, NULL);
	TEST_ASSERT_EQUAL_PTR(opeTk->token[0], leftTk);	
}

/* 
*				  		int 
*					 		 |
*					 		*
*					 		|	\
*			 				[		null
*						/  \
*					app   2
*				
*		int *app[2];
*			app is array 2 of pointer to int. 
*/
void test_create_app_is_array_4_of_array_2_of_pointer_to_int(void) {
	IdentifierToken *root;
	OperatorToken *firstopeTk, *firstleftTk;
	IdentifierToken *idenTk, *secondleftTk;
	IntegerToken *secondrightTk;
	
	idenTk = (IdentifierToken *)createIdentifierToken("int", 0, 3);
	firstopeTk = (OperatorToken *)createOperatorToken("*", 0, 1);
	firstleftTk = (OperatorToken *)createOperatorToken("[", 0, 1);
	secondleftTk = (IdentifierToken *)createIdentifierToken("app", 0, 3);
	secondrightTk = (IntegerToken *)createIntegerToken("2", 0, 1);
	idenTk->token = (Token *)firstopeTk;
	firstopeTk->token[0] = (Token *)firstleftTk;
	firstopeTk->token[1] = NULL;
	firstleftTk->token[0] = (Token *)secondleftTk;
	firstleftTk->token[1] = (Token *)secondrightTk;
	secondleftTk->token = NULL;
	
	root = (IdentifierToken *)secondTree("int", "*", "[", "2", "app"); 

	TEST_ASSERT_EQUAL_STRING(idenTk->name, root->name);
	TEST_ASSERT_EQUAL_STRING(root->name, "int" );
	TEST_ASSERT_EQUAL_STRING(firstopeTk->symbol, "*");
	TEST_ASSERT_EQUAL_STRING(firstleftTk->symbol, "[");
	TEST_ASSERT_EQUAL_STRING(secondleftTk->name, "app");
	TEST_ASSERT_EQUAL(secondrightTk->value, 2);
	TEST_ASSERT_EQUAL_PTR(idenTk->token,firstopeTk); 
	TEST_ASSERT_EQUAL_PTR(firstopeTk->token[0], firstleftTk);
	TEST_ASSERT_EQUAL(firstopeTk->token[1], NULL);
	TEST_ASSERT_EQUAL_PTR(firstleftTk->token[0], secondleftTk);
	TEST_ASSERT_EQUAL_PTR(firstleftTk->token[1], secondrightTk);
	TEST_ASSERT_EQUAL(secondleftTk->token, NULL);
} 