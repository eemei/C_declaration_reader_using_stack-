#include "unity.h"
#include "addTwoToken.h"
#include "Token.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
void setUp(void) {}
void tearDown(void) {}

/*  
*					operatorToken					example
*				_________________							 [
*				| symbol "["	|								/ \
*				-----------------					   x  2
*				|  Token[0]		|
*				-----------------
*				| Token[1]		|
*				_________________
*			/					\
*	___idenTOKEN__			_integerTOKEN_
*	|	type	 |			|	type	|
*	--------------			-------------
*	|	name	|			| value		|
*	_____________			_____________
*/
  
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
	
void test_create_a_tree(void) {
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

/* 
*				  		int 
*					 		 |
*					 		[
*					 	/  \
*			 			[	  2
*					/ \
*				*   4
*				|
*			app
*	
*		int *app[4][2];
* 
*/


