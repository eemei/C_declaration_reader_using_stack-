#include "mainERR.h"
#include "ERR_MALFORMED_DECLARATION.h"
#include "CException.h"
#include "Token.h"

/*  "RULES" CHECK THE DECLARATION IS CORRECT OR NOT:--
*     -the first token must be identifier_type.
*     -the next token can be identifier or operator :-
*       if (operator) : only("*","(") 
*       other is wrong.
*       exp (legal):
*         int *fool ;
*       exp (illegal):
*         int &foo;
*/
void	illegalTokenizers(Token *token) {
  OperatorToken *OpTk = (OperatorToken *)(((IdentifierToken *)token)->token);
  if (token->type != TOKEN_IDENTIFIER_TYPE) {
    throwError("first declaration must be identifier type, please check out\n", ERR_NO_IDENTIFIER_DECLARATION);
  }

  else {
    if (((IdentifierToken*)token)->token->type ==  TOKEN_OPERATOR_TYPE) {
      if ( OpTk->symbol != "*") {
        throwError("here must be pointer, please check out\n", ERR_OPERATOR_SYMBOL);
      }
    }
  }
}