#include "unity.h"
#include "tree.h"
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
*
*		int x[2];
*			x is array 2 of int.
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
	TEST_ASSERT_EQUAL_PTR(idenTk->token, opeTk ); 
	TEST_ASSERT_EQUAL_PTR(opeTk->token[0], leftTk);
	TEST_ASSERT_EQUAL_PTR(opeTk->token[1], rightTk);
}
/*
*		this function to test the ERROR CODE  
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
	TEST_ASSERT_EQUAL_PTR(idenTk->token[0], opeTk); 
	TEST_ASSERT_EQUAL(idenTk->token[1], NULL);
	TEST_ASSERT_EQUAL(opeTk->token[1] , NULL);
	TEST_ASSERT_EQUAL(leftTk->token, NULL);
	TEST_ASSERT_EQUAL_PTR(opeTk->token[0], leftTk);	
}
/* 
*			float
*				|
*				+	
*			/  \
*		fp		NULL
*		|
*		NULL
*
*		float +fp;         
*/
test_create_eeror_symbol_with_a_plus(void) {
	OperatorToken *opeTk;
	IdentifierToken *leftTk, *idenTk, *root;
	
	idenTk = (IdentifierToken *)createOperatorToken("float", 0, 5);
	opeTk = (OperatorToken *)createOperatorToken("+", 0, 1);
	leftTk = (IdentifierToken *)createIdentifierToken("fb", 0, 2);	
	idenTk->token = (Token *)opeTk;
	opeTk->token[0] = (Token *)leftTk;
	opeTk->token[1] = NULL;
	leftTk->token = NULL;
	
	root = (IdentifierToken *)errorSymbolTree("float", "+", "fb"); 

	
	TEST_ASSERT_EQUAL_STRING(idenTk->name, root->name);
	TEST_ASSERT_EQUAL_STRING(root->name, "float");
	TEST_ASSERT_EQUAL_STRING(opeTk->symbol, "+");
	TEST_ASSERT_EQUAL_STRING(leftTk->name, "fb");
	TEST_ASSERT_EQUAL_PTR(idenTk->token, opeTk); 
	TEST_ASSERT_EQUAL_PTR(opeTk->token[0], leftTk);
	TEST_ASSERT_EQUAL(opeTk->token[1] , NULL);
	TEST_ASSERT_EQUAL(leftTk->token, NULL);	
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
	TEST_ASSERT_EQUAL_STRING(root->name, "int");
	TEST_ASSERT_EQUAL_STRING(firstopeTk->symbol, "*");
	TEST_ASSERT_EQUAL_STRING(firstleftTk->symbol, "[");
	TEST_ASSERT_EQUAL_STRING(secondleftTk->name, "app");
	TEST_ASSERT_EQUAL(secondrightTk->value, 2);
	TEST_ASSERT_EQUAL_PTR(idenTk->token, firstopeTk); 
	TEST_ASSERT_EQUAL_PTR(firstopeTk->token[0], firstleftTk);
	TEST_ASSERT_EQUAL(firstopeTk->token[1], NULL);
	TEST_ASSERT_EQUAL_PTR(firstleftTk->token[0], secondleftTk);
	TEST_ASSERT_EQUAL_PTR(firstleftTk->token[1], secondrightTk);
	TEST_ASSERT_EQUAL(secondleftTk->token, NULL);
}
/* 
*				double 
*					|
*					y
*					|
*				NULL
*
*		double y;
*			y is double
*/ 
test_create_y_is_double(void) {
	IdentifierToken *idenTk, *Tk, *root; 
	
	idenTk = (IdentifierToken *)createIdentifierToken("double", 0, 6);
	Tk = (IdentifierToken *)createIdentifierToken("y", 0, 1);
	idenTk->token = (Token *)Tk;
	Tk->token = NULL;
	
	root = (IdentifierToken *)YisDouble("double", "y");
	
	TEST_ASSERT_EQUAL_STRING(idenTk->name, root->name);
	TEST_ASSERT_EQUAL_STRING(root->name, "double" );
	TEST_ASSERT_EQUAL_STRING(Tk->name, "y");
	TEST_ASSERT_EQUAL_PTR(idenTk->token, Tk); 	
	TEST_ASSERT_EQUAL(Tk->token, NULL);
}
/* 
*							float
*							|
*							*
*						/ \						
*					*		NULL
*				/  \
*			y		NULL
*
*		float **y;
*			y is pointer to pointer to float.	
*/
test_create_a_tree_y_is_pointer_to_pointer_to_float(void) {
	OperatorToken *firstopeTk, *secondopeTk;
	IdentifierToken *idenTk, *leftTk, *root;
	
	idenTk = (IdentifierToken *)createIdentifierToken("float", 0, 5);
	firstopeTk = (OperatorToken *)createOperatorToken("*", 0, 1);
	secondopeTk = (OperatorToken *)createOperatorToken("*", 0, 1);
	leftTk = (IdentifierToken *)createIdentifierToken("y", 0, 1);
	idenTk->token = (Token *)firstopeTk;
	firstopeTk->token[0] = (Token *)secondopeTk;
	firstopeTk->token[1] = NULL;
	secondopeTk->token[0] = (Token *)leftTk;
	secondopeTk->token[1] = NULL;
	leftTk->token = NULL;
	
	root = (IdentifierToken *)yisPointertoPointer("float", "*", "*", "y");
	
	TEST_ASSERT_EQUAL_STRING(idenTk->name, root->name);
	TEST_ASSERT_EQUAL_STRING(root->name, "float");
	TEST_ASSERT_EQUAL_STRING(firstopeTk->symbol, "*");
	TEST_ASSERT_EQUAL_STRING(secondopeTk->symbol, "*");
	TEST_ASSERT_EQUAL_STRING(leftTk->name, "y"); 	
	TEST_ASSERT_EQUAL_PTR(idenTk->token, firstopeTk);
	TEST_ASSERT_EQUAL_PTR(firstopeTk->token[0], secondopeTk);
	TEST_ASSERT_EQUAL(firstopeTk->token[1], NULL);
	TEST_ASSERT_EQUAL_PTR(secondopeTk->token[0], leftTk);
	TEST_ASSERT_EQUAL(secondopeTk->token[1], NULL);
	TEST_ASSERT_EQUAL(leftTk->token, NULL);
	}
/* 
*					char
*					|
*					(
*				/ 	\
*			foo		int 
*
*		char foo(int );
*			foo is function taking int returning char.
* */
test_create_foo_is_function_taking_int_returning_char(void) {
	OperatorToken *opeTk;
	IdentifierToken *idenTk, *rightTk, *leftTk, *root;
	
	idenTk = (IdentifierToken *)createIdentifierToken("char", 0, 4);
	opeTk = (OperatorToken *)createOperatorToken("(", 0, 1);
	rightTk = (IdentifierToken *)createIdentifierToken("int", 0, 3);
	leftTk = (IdentifierToken *)createIdentifierToken("foo", 0, 3);
	idenTk->token = (Token *)opeTk;
	opeTk->token[0] = (Token *)leftTk;
	opeTk->token[1] = (Token *)rightTk;
	leftTk->token = NULL;
	
	root = (IdentifierToken *)fooisFunc("char", "(", "foo", "int");
	
	TEST_ASSERT_EQUAL_STRING(idenTk->name, root->name);
	TEST_ASSERT_EQUAL_STRING(root->name, "char");
	TEST_ASSERT_EQUAL_STRING(opeTk->symbol, "(");
	TEST_ASSERT_EQUAL_STRING(rightTk->name, "int");
	TEST_ASSERT_EQUAL_STRING(leftTk->name, "foo");
	TEST_ASSERT_EQUAL_PTR(idenTk->token, opeTk);
	TEST_ASSERT_EQUAL_PTR(opeTk->token[0], leftTk);
	TEST_ASSERT_EQUAL_PTR(opeTk->token[1], rightTk);
	TEST_ASSERT_EQUAL(leftTk->token, NULL);		
}
/* 
*					long
*					|
*					(
*				/ 	\
*			foo		NULL 
*
*		long foo( );
*			foo is function taking nothing returning long.
*/
void test_create_long_is_function_takig_nothing_returning_long(void) {
	OperatorToken *opeTk;
	IdentifierToken *idenTk, *leftTk, *rightTk, *root;
	
	idenTk = (IdentifierToken *)createIdentifierToken("long", 0, 4);
	opeTk = (OperatorToken *)createOperatorToken("(", 0, 1);
	leftTk = (IdentifierToken *)createIdentifierToken("foo", 0, 3);
	rightTk = (IdentifierToken *)createIdentifierToken("NULL", 0, 4);
	idenTk->token = (Token *)opeTk;
	opeTk->token[0] = (Token *)leftTk;
	opeTk->token[1] = (Token *)rightTk;
	leftTk->token = NULL;	
	
	root = (IdentifierToken *)fooisFuncreturnNoth("long", "(", "foo", "NULL");
	
	TEST_ASSERT_EQUAL_STRING(idenTk->name, root->name);
	TEST_ASSERT_EQUAL_STRING(root->name, "long");
	TEST_ASSERT_EQUAL_STRING(opeTk->symbol, "(");
	TEST_ASSERT_EQUAL_STRING(leftTk->name, "foo");
	TEST_ASSERT_EQUAL_PTR(idenTk->token, opeTk);
	TEST_ASSERT_EQUAL_PTR(opeTk->token[0], leftTk);
	TEST_ASSERT_EQUAL_PTR(opeTk->token[1], rightTk);
	TEST_ASSERT_EQUAL(leftTk->token, NULL);
}

// /* 
// *									float
// *										|
// *										*
// *									/  \
// *								[  NULL
// *							/  \	
// *						*		 4
// *					/  \
// *				[			NULL
// *			/  \
// *			y   2
// *			|
// *			NULL
// *
// *		float *(*y[2])[4];
// *			y is array 2 of pointer to array 4 of pointer to float.	
// */
// void test_create_y_array_pointer_array_point_float(void) {
	// IdentifierToken *idenTk, *leftTk, *root;
	// OperatorToken *firleftTk, *secleftTk, *thileftTk, *forleftTk;
	// IntegerToken *firrightTk, *secrightTk;
	
	// idenTk = (IdentifierToken *)createIdentifierToken("float", 0, 5);
	// firleftTk = (OperatorToken *)createOperatorToken("*", 0, 1);
	// secleftTk = (OperatorToken *)createOperatorToken("[", 0, 1);
	// thileftTk = (OperatorToken *)createOperatorToken("*", 0, 1);
	// forleftTk = (OperatorToken *)createOperatorToken("[", 0, 1);
	// leftTk = (IdentifierToken *)createIdentifierToken("y", 0, 1);
	// firrightTk = (IntegerToken *)createIntegerToken("4", 0, 1);
	// secrightTk = (IntegerToken *)createIntegerToken("2", 0, 1);
	// idenTk->token = (Token *)firleftTk;
	// firleftTk->token[0] = (Token *)secleftTk;
	// firleftTk->token[1] = NULL;
	// secleftTk->token[0] = (Token *)thileftTk;
	// secleftTk->token[1] = (Token *)firrightTk;
	// thileftTk->token[0] = (Token *)forleftTk;
	// thileftTk->token[1] = NULL;
	// forleftTk->token[0] = (Token *)idenTk;
	// forleftTk->token[1] = (Token *)secrightTk;
	// idenTk->token = NULL;
	
	// root = (IdentifierToken *)yArrayPointer("float", "*", "[", "*", "4", "[", "2", "y");
	
	// TEST_ASSERT_EQUAL_STRING(idenTk->name, root->name);
	// TEST_ASSERT_EQUAL_STRING(root->name, "float");
	// TEST_ASSERT_EQUAL_STRING(firleftTk->symbol, "*");
	// TEST_ASSERT_EQUAL_STRING(secleftTk->symbol, "[");
	// TEST_ASSERT_EQUAL_STRING(thileftTk->symbol, "*");
	// TEST_ASSERT_EQUAL_STRING(forleftTk->symbol, "[");
	// TEST_ASSERT_EQUAL_STRING(leftTk->name, "y");
	// TEST_ASSERT_EQUAL(firrightTk->value, 4);
	// TEST_ASSERT_EQUAL(secrightTk->value, 2);
	// TEST_ASSERT_EQUAL_PTR(idenTk->token, firleftTk); 
	// TEST_ASSERT_EQUAL_PTR(firleftTk->token[0], secleftTk);
	// TEST_ASSERT_EQUAL(firleftTk->token[1], NULL);
	// TEST_ASSERT_EQUAL_PTR(secleftTk->token[0], thileftTk);
	// TEST_ASSERT_EQUAL_PTR(secleftTk->token[1], firrightTk);
	// TEST_ASSERT_EQUAL_PTR(thileftTk->token[0], forleftTk);
	// TEST_ASSERT_EQUAL(thileftTk->token[1], NULL);
	// TEST_ASSERT_EQUAL_PTR(forleftTk->token[0], idenTk);
	// TEST_ASSERT_EQUAL_PTR(forleftTk->token[1], secrightTk);
	// TEST_ASSERT_EQUAL(idenTk->token, NULL);
// }
