#include "addTwoToken.h"
#include "Token.h"
#include <stdio.h>
#include <malloc.h>



/* Add2Tokens generated a "small tree" connecting with "TWO TOKEN"  
*					operatorToken					example
*				_________________						 [
*				|symbol "["		|						/ \
*				-----------------					   x  2
*				|Token[0]		|
*				-----------------
*				|Token[1]		|
*				_________________
*			/					\
*	idenTOKEN(leftSide)	   integerTOKEN(rightSide)
*	|	type	 |			|	type	|
*	--------------			-------------
*	|	name	|			| value		|
*	_____________			_____________
*/

Token *addTwoToken(char *name, char *operatorSymbol, int rightValue){
  //char *symbol= NULL;
	OperatorToken *opeToken = malloc(sizeof(OperatorToken )+(sizeof(Token *)) * 2);
  	//IntegerToken* leftVal = malloc(sizeof(IntegerToken ));
	IdentifierToken *leftToken = malloc (sizeof(IdentifierToken));
	IntegerToken* rightToken = malloc(sizeof(IntegerToken));
	//leftVal = createIntegerToken (leftValue);
	leftToken = createIdentifierToken(name); 
	rightToken = createIntegerToken (rightValue);
	opeToken = createOperatorToken(operatorSymbol);
	opeToken -> token[0] = (Token *)leftToken;
	opeToken -> token[1] = (Token *)rightToken;
	
  //IntegerToken *rightSide = malloc (sizeof (IntegerToken));
 // IdentifierToken *leftSide = malloc (sizeof(IdentifierToken));
  
  // rightSide = createIntegerToken(rightToken);
  // leftSide = createIdentifierToken(leftToken);
  // opeToken = createOperatorToken(operatorSymbol);
  // opeToken-> token [0] = (Token *)leftSide;
  // opeToken-> token [1] = (Token *)rightSide;
  // //opeToken->symbol = symbol;
  // //opeToken->type = TOKEN_OPERATOR_TYPE;
  return (Token *)opeToken;
}