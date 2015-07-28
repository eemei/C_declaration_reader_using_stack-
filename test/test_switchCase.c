#include "unity.h"
#include "switchCase.h"
#include "Token.h"
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void test_declaration(void){
	Token *token;
	((OperatorToken *)token)->symbol, "*";
	token->type = TOKEN_IDETIFIER_TYPE;
	
	
	//declaration(token);
}
