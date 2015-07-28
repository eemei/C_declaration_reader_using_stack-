#include "switchCase.h"
#include <string.h>
#include <stdio.h>
#include "Token.h"

void declaration(Token *token){	
	if (token == NULL) {
		printf("token is empty\n");
		return;
	}
	switch (token->type) {
		case TOKEN_IDENTIFIER_TYPE:
			printf("%s is", ((IdentifierToken *)token)->name);
			break;
		case TOKEN_INTEGER_TYPE: 
			printf("%d", ((IntegerToken *)token)->value);
			break;
	}
//canonical solution in C
	if (strcmp(((OperatorToken *)token)->symbol, "*") == 0) {
		printf(" a pointer to");
	} 
	else if (strcmp(((OperatorToken *)token)->symbol, "[") == 0) {
		printf(" an array of");
	}
	else if (strcmp(((OperatorToken *)token)->symbol, "(") == 0) {
		printf(" a function returning ");
	}
	/* default: */
	else {
		printf("Error: unknown operator symbol!\n");
	}
}