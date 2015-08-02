#include "switchCase.h"
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
void declaration(Token *token) {
	if (token != NULL) {
		if (token->type == TOKEN_IDENTIFIER_TYPE) {
			declaration(((IdentifierToken *)token)->token);
			if (!strcmp(((IdentifierToken *)token)->name, "double")) {
				printf(" %s.\n", ((IdentifierToken *)token)->name);
			}
			else if (!strcmp(((IdentifierToken *)token)->name, "float")) {
				printf(" %s.\n", ((IdentifierToken *)token)->name);
			}
			else if (!strcmp(((IdentifierToken *)token)->name, "char")) {
				printf(" %s.\n", ((IdentifierToken *)token)->name);
			}
			else if (!strcmp(((IdentifierToken *)token)->name, "int")) {
				printf(" %s.\n", ((IdentifierToken *)token)->name);
			}
			else if (!strcmp(((IdentifierToken *)token)->name, "void")) {
				printf(" %s.\n", ((IdentifierToken *)token)->name);
			}
			else if (!strcmp(((IdentifierToken *)token)->name, "unsigned int")) {
				printf(" %s.\n", ((IdentifierToken *)token)->name);
			}
			else if (!strcmp(((IdentifierToken *)token)->name, "unsigned char")) {
				printf(" %s.\n", ((IdentifierToken *)token)->name);
			}
			else if (!strcmp(((IdentifierToken *)token)->name, "short")) {
				printf(" %s.\n", ((IdentifierToken *)token)->name);
			}
			else if (!strcmp(((IdentifierToken *)token)->name, "unsigned short")) {
				printf(" %s.\n", ((IdentifierToken *)token)->name);
			}
			else if (!strcmp(((IdentifierToken *)token)->name, "long")) {
				printf(" %s.\n", ((IdentifierToken *)token)->name);
			}
			else if (!strcmp(((IdentifierToken *)token)->name, "unsigned long")) {
				printf(" %s.\n", ((IdentifierToken *)token)->name);
			}
			else if (!strcmp(((IdentifierToken *)token)->name, "long double")) {
				printf(" %s.\n", ((IdentifierToken *)token)->name);
			}
			else {
				printf(" %s is", ((IdentifierToken *)token)->name);
			}
		}

		else if (token->type == TOKEN_OPERATOR_TYPE) {
			declaration(((OperatorToken *)token)->token[0]);
				if (!strcmp(((OperatorToken *)token)->symbol, "*")) {
					printf(" pointer to");
				}
				else if (!strcmp(((OperatorToken *)token)->symbol, "[")) {
					printf(" array %d of", ((IntegerToken *)(((OperatorToken *)token)->token[1]))->value);
				}
				else if (!strcmp(((OperatorToken *)token)->symbol, "(")) {
					printf(" function taking %s returning", ((IdentifierToken *)(((OperatorToken *)token)->token[1]))->name);
				}
		}
	}
}