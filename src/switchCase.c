#include "switchCase.h"
#include "addTwoToken.h"
#include <string.h>
#include <stdio.h>
#include "Token.h"
#include <malloc.h>

/* 
*		if given int *fool
*			print out :
*								fool is a pointer to int
*		if given void fool (int arg)
*			print out :
*								fool is a function returning int arg void. 
* */

void declaration(Token *token){	
	if (token == NULL) {
		printf("token is empty\n");
	}
	switch (token->type) {
		case TOKEN_IDENTIFIER_TYPE:	
			printf("%s is ", ((IdentifierToken *)token)->name);
			break;
		case TOKEN_INTEGER_TYPE: 
			printf("%d of ", ((IntegerToken *)token)->value);
			break;
		case TOKEN_OPERATOR_TYPE:	
			if (!strcmp(((OperatorToken *)token)->symbol, "*")) {
				printf("pointer to ");
			}
			else if (!strcmp(((OperatorToken *)token)->symbol, "[")) {
				printf("array ");
			}
			else if (!strcmp(((OperatorToken *)token)->symbol, "(")) {
				printf("a function returning ");
			}
			/* default: */
			else {
			printf("Error: unknown operator symbol!\n");
			}
		break;
		default : printf("Error: unknown type token!\n");
	}
}