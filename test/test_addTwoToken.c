#include "unity.h"
#include "addTwoToken.h"
#include "mock_Token.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
void setUp(void) {}

void tearDown(void) {}

  // void test_create_integerToken(void){
    // IntegerToken *intToken = malloc (sizeof(IntegerToken));
    // int value = 7;
    // intToken = (IntegerToken *)createIntegerToken(value);
    // TEST_ASSERT_EQUAL (7,intToken->value);
    // TEST_ASSERT_EQUAL (1,intToken->type);
    
  // }
  
  // void test_create_identifierToken(void){
    // IdentifierToken *idenToken = malloc (sizeof(IdentifierToken));
    // char *name = "char";
    // idenToken = (IdentifierToken *)createIdentifierToken(name);
    // TEST_ASSERT_EQUAL_STRING ("char", idenToken->name);
  // }

  // void test_create_operatorToken(void){
	  // char *symbol = "[";
      // OperatorToken *opeToken = malloc(sizeof(OperatorToken) + (sizeof(Token *) * 2));
	  // opeToken->type = TOKEN_OPERATOR_TYPE;
	  // opeToken->symbol= symbol;
	  // opeToken = (OperatorToken *)createOperatorToken (symbol);
	  // TEST_ASSERT_EQUAL ("[", opeToken->symbol);
  // }
  
  /* Add2Tokens generated a "small tree" connecting with "TWO TOKEN"  
*					operatorToken					example
*				_________________						 [
*				| symbol "["	|						/ \
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

  void test_add_two_tokens_and_connecting_with_operatorToken(void){
	OperatorToken *root;
	IdentifierToken *iden = malloc(sizeof(IdentifierToken));
	OperatorToken *opeToken = malloc(sizeof(OperatorToken )+(sizeof(Token *)) * 2);
	//IntegerToken int1 = {type:TOKEN_INTEGER_TYPE, value:2};
	IntegerToken *int1 = malloc(sizeof(IntegerToken));
	opeToken->type = TOKEN_OPERATOR_TYPE;
	iden->type = TOKEN_IDENTIFIER_TYPE;
	opeToken->symbol = "[";

	createIdentifierToken_ExpectAndReturn("x", iden);
	createIntegerToken_ExpectAndReturn (2, int1);
	createOperatorToken_ExpectAndReturn("[", opeToken);
	
	root = (OperatorToken *)addTwoToken("x","[",2);
	
	TEST_ASSERT_EQUAL_PTR(opeToken, root);
	TEST_ASSERT_EQUAL_PTR(int1, root->token [1]);
	TEST_ASSERT_EQUAL_PTR(iden, root->token [0]);
	TEST_ASSERT_EQUAL_PTR (opeToken->type, root->type);
	TEST_ASSERT_EQUAL_PTR(opeToken->symbol, root->symbol);
  }