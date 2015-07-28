#include "addTwoToken.h"
#include "Token.h"
#include <stdio.h>
#include <malloc.h>


/*
*				int 
*				|
*				[
*			/		\
*			x		2
*			|
*		NULL
*
*/

Token *tree(char *iden, char *symbol, char *leftTkIden, char *rightTkInt) {
	
	int start = 0;
	int length0 = 3;
	int length1 = 1;
	int length2 = 1;
	int length3 = 1;

	
	OperatorToken *opeTk;
	IdentifierToken *idenTk, *leftTk;
	IntegerToken *rightTk;
	
	idenTk = (IdentifierToken *)createIdentifierToken(iden, start, length0);
	opeTk = (OperatorToken *)createOperatorToken(symbol, start, length1);
	leftTk = (IdentifierToken *)createIdentifierToken(leftTkIden, start, length2);
	rightTk = (IntegerToken *)createIntegerToken(rightTkInt, start, length3);
	idenTk->token = (Token *)opeTk;
	opeTk->token[0] = (Token *)leftTk;
	opeTk->token[1] = (Token *)rightTk;
	leftTk->token = NULL;

	return (Token *)idenTk;
}

/* 
*				  		int 
*					 		 |
*					 		[
*					 	/  \
*			 			[	  2
*					/ \
*				*   4
*				|
*			app
*	
*		int *app[4][2];
* 
*/

Token *secondtree(char *iden, char *symbol, char *leftTkIden, char *rightTkInt) {
	
	int start = 0;
	int length0 = 3;
	int length1 = 1;
	int length2 = 1;
	int length3 = 1;

	
	OperatorToken *opeTk;
	IdentifierToken *idenTk, *leftTk;
	IntegerToken *rightTk;
	
	idenTk = (IdentifierToken *)createIdentifierToken(iden, start, length0);
	opeTk = (OperatorToken *)createOperatorToken(symbol, start, length1);
	leftTk = (IdentifierToken *)createIdentifierToken(leftTkIden, start, length2);
	rightTk = (IntegerToken *)createIntegerToken(rightTkInt, start, length3);
	idenTk->token = (Token *)opeTk;
	opeTk->token[0] = (Token *)leftTk;
	opeTk->token[1] = (Token *)rightTk;
	leftTk->token = NULL;

	return (Token *)idenTk;
}
