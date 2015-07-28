#include "mainERR.h"
#include "ERR_MALFORMED_DECLARATION.h"
#include "CException.h"
#include "Token.h"

/* "RULES" CHECK THE PROTOTYPE IS CORRECT OR NOT:--
*			-the first token must be identifier_type.
*			-the second token can be identifier or operator :-
																						only("*","(","[") 
																						other is wrong.
*/

void	illegalTokenizers(Token *token) {
		if (token->type != TOKEN_IDENTIFIER_TYPE) {
		throwError("first declaration must be identifier type, please check out\n", ERR_NO_IDENTIFIER_DECLARATION);
	}
}

void illegalOperatorSymbol(Token *token) {
	if (((OperatorToken *)token)->symbol != "*") {
		throwError("here must be pointer, please check out\n", ERR_OPERATOR_SYMBOL);
	}
}

	
	


