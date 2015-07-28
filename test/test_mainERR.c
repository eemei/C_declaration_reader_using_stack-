#include "unity.h"
#include "mainERR.h"
#include "ERR_MALFORMED_DECLARATION.h"
#include "CException.h"
#include "Token.h"


void setUp(void) {}
void tearDown(void) {}


void test_first_declaration_is_token_operator_type(void){
	Token *token;
	ErrorObject *err;
	token->type == TOKEN_OPERATOR_TYPE;
	
	Try {
		illegalTokenizers(token);
		TEST_FAIL_MESSAGE("expert ERR_OPERATOR_SYMBOL TO BE THROWN. but none thrown");
  }Catch(err) {                  // throw go to catch 
		TEST_ASSERT_EQUAL_STRING("first declaration must be identifier type, please check out\n",err->errorMsg);
		TEST_ASSERT_EQUAL (ERR_NO_IDENTIFIER_DECLARATION, err->errorCode);
		freeError(err);               
  }
}

void test_operatorToken_is_plusSymbol(void){
	Token *token;
	ErrorObject *err;
	((OperatorToken *)token)->symbol == "*";

	Try {
		illegalOperatorSymbol(token);
		TEST_FAIL_MESSAGE("expert ERR_OPERATOR_SYMBOL TO BE THROWN. but none thrown");
  }Catch(err) {                  // throw go to catch 
		TEST_ASSERT_EQUAL_STRING("here must be pointer, please check out\n",err->errorMsg);
		TEST_ASSERT_EQUAL (ERR_OPERATOR_SYMBOL, err->errorCode);
		freeError(err);               
  }
}


void test_piop(void){}
