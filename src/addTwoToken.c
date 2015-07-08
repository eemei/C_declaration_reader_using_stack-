#include "addTwoToken.h"
#include "Token.h"
#include <stdio.h>
#include <malloc.h>



/* Add2Tokens generated a "small tree" connecting with "TWO TOKEN"  
*					operatorToken					example
*				_________________						   [
*				|symbol "["		|						    / \
*				-----------------					   x  2
*				|Token[0]		|
*				-----------------
*				|Token[1]		|
*				_________________
*			/					        \
*	idenTOKEN(leftSide)	   integerTOKEN(rightSide)
*	|	type	 |		        	|	type	|
*	--------------			-------------
*	|	name	|			        | value		|
*	_____________			    _____________
*/

Token *addTwoToken(char *name, char *operatorSymbol, int rightValue){

	OperatorToken *opeToken = malloc(sizeof(OperatorToken )+(sizeof(Token *)) * 2);
	IdentifierToken *leftToken = malloc (sizeof(IdentifierToken));
	IntegerToken* rightToken = malloc(sizeof(IntegerToken));

	leftToken = createIdentifierToken(name); 
	rightToken = createIntegerToken (rightValue);
	opeToken = createOperatorToken(operatorSymbol);
  
	opeToken -> token[0] = (Token *)leftToken;
	opeToken -> token[1] = (Token *)rightToken;
	
 
  return (Token *)opeToken;
}


/* AddToken "attract the identifierToken to the operatorToken "
*
*       identifierToken         	example
*     |     name    |               int 
*     _______________                |
*     |   token     |                [
*     _______________
*           |
*					operatorToken				
*/

Token *addToken (char *name, char *symbol){
  IdentifierToken *iden = malloc(sizeof(IdentifierToken )+(sizeof(Token *)));
  OperatorToken *opeToken = malloc(sizeof(OperatorToken )+(sizeof(Token *)) * 2);
  
  opeToken = createOperatorToken(symbol);
  iden = createIdentifierToken (name);
  
  iden->token = (Token *)opeToken;
  return (Token *)iden;
}
































/* Add2Tokens generated a "small tree" connecting with "TWO TOKEN"  
*					operatorToken					example  char foo[3][2]
*				_________________						   [
*				|symbol "["		|						    / \
*				-----------------					   [  2
*				|Token[0]		|               /\
*				-----------------        foo  3
*				|Token[1]		|
*				_________________
*			/					\
*	operTOKEN(leftSide)	   integerTOKEN(rightSide)
*	|	symbol |			|	type	|
*	--------------			-------------
*	|	token[0/1]	|			| value		|
*	_____________			_____________
*/

// Token *addTwoTokenOpe(char *TkOpe, char *operatorSymbol, int rightValue){
  // //char *symbol= NULL;
	// OperatorToken *opeToken = malloc(sizeof(OperatorToken )+(sizeof(Token *)) * 2);
  	// //IntegerToken* leftVal = malloc(sizeof(IntegerToken ));
	// IdentifierToken *leftToken = malloc (sizeof(IdentifierToken));
	// IntegerToken* rightToken = malloc(sizeof(IntegerToken));
	// //leftVal = createIntegerToken (leftValue);
	// leftToken = createIdentifierToken(name); 
	// rightToken = createIntegerToken (rightValue);
	// opeToken = createOperatorToken(operatorSymbol);
	// opeToken -> token[0] = (Token *)leftToken;
	// opeToken -> token[1] = (Token *)rightToken;

  // return (Token *)opeToken;
// }



