#include "unity.h"
#include "mainERR.h"
#include "ERR_MALFORMED_DECLARATION.h"
#include "tree.h"
#include "CException.h"
#include "Token.h"
void setUp(void) {}
void tearDown(void) {}

void test_second_declaration_symbol_is_amphersand(void){
	Token *token;
	ErrorObject *err;	
	Token *root;
	root = tree("int", "&", "x", "2"); 
	Try {
		illegalTokenizers(root);
		TEST_FAIL_MESSAGE("expert ERR_OPERATOR_SYMBOL TO BE THROWN. but none thrown");
  }Catch(err) {                  // throw go to catch 
		TEST_ASSERT_EQUAL_STRING("here must be pointer, please check out\n",err->errorMsg);
		TEST_ASSERT_EQUAL (ERR_OPERATOR_SYMBOL, err->errorCode);
		freeError(err);               
  }
}

void test_first_declaration_is_operator_type(void){
	Token *token;
	ErrorObject *err;	
	Token *root;
	root = errorTree("@#", "*", "x"); 
	Try {
		illegalTokenizers(root);
		TEST_FAIL_MESSAGE("expert ERR_NO_IDENTIFIER_DECLARATION TO BE THROWN. but none thrown");
  }Catch(err) {                  // throw go to catch 
		TEST_ASSERT_EQUAL_STRING("first declaration must be identifier type, please check out\n",err->errorMsg);
		TEST_ASSERT_EQUAL (ERR_NO_IDENTIFIER_DECLARATION, err->errorCode);
		freeError(err);               
  }
}