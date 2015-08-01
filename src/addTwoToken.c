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
	OperatorToken *opeTk;
	IdentifierToken *idenTk, *leftTk;
	IntegerToken *rightTk;
	
	idenTk = (IdentifierToken *)createIdentifierToken(iden, start, 3);
	opeTk = (OperatorToken *)createOperatorToken(symbol, start, 1);
	leftTk = (IdentifierToken *)createIdentifierToken(leftTkIden, start, 1);
	rightTk = (IntegerToken *)createIntegerToken(rightTkInt, start, 1);
	idenTk->token = (Token *)opeTk;
	opeTk->token[0] = (Token *)leftTk;
	opeTk->token[1] = (Token *)rightTk;
	leftTk->token = NULL;

	return (Token *)idenTk;
}

/**		this function to test the error code  
*					 @# -->operatorTokenType
*					/	\
*				*		NULL
*			/  \
*	 	x   NULL
*/
/* 											@# 					*								x	*/
Token *errorTree(char *iden, char *symbol, char *leftTkIden) {
	int start = 0;
	OperatorToken *opeTk, *idenTk;
	IdentifierToken *leftTk;
	
	idenTk = (OperatorToken *)createOperatorToken(iden, start, 2);
	opeTk = (OperatorToken *)createOperatorToken(symbol, start, 1);
	leftTk = (IdentifierToken *)createIdentifierToken(leftTkIden, start, 1);
	idenTk->token[0] = (Token *)opeTk;
	idenTk->token[1] = NULL;
	opeTk->token[0] = (Token *)leftTk;
	opeTk->token[1] = NULL;
	leftTk->token = NULL;

	return (Token *)idenTk;
}

/* 
*				  		int 
*					 		 |
*					 		*
*					 		|	\
*			 				[		null
*						/  \
*					app   2
*				
*			
*		int *app[2];
*			app is array 2 of pointer to int. 
* 
*/
/* 											int					*								[										2							app */
Token *secondTree(char *iden, char *firsymbol, char *secsymbol, char *secrightTk, char *secleftTk) {
	int start = 0;
	OperatorToken *firstopeTk, *firstleftTk;
	IdentifierToken *idenTk, *secondleftTk;
	IntegerToken *secondrightTk;
	
	idenTk = (IdentifierToken *)createIdentifierToken(iden, start, 3);
	firstopeTk = (OperatorToken *)createOperatorToken(firsymbol, start, 1);
	firstleftTk = (OperatorToken *)createOperatorToken(secsymbol, start, 1);
	secondleftTk = (IdentifierToken *)createIdentifierToken(secleftTk, start, 3);
	secondrightTk = (IntegerToken *)createIntegerToken(secrightTk, start, 1);
	idenTk->token = (Token *)firstopeTk;
	firstopeTk->token[0] = (Token *)firstleftTk;
	firstopeTk->token[1] = NULL;
	firstleftTk->token[0] = (Token *)secondleftTk;
	firstleftTk->token[1] = (Token *)secondrightTk;
	secondleftTk->token = NULL;

	return (Token *)idenTk;
} 