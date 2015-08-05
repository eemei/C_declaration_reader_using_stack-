#include "tree.h"
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
/* 								int							[								x									2 */
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
*
*	@# *x;
*		x is pointer to @#.
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
*			float
*				|
*				+	
*			/  \
*		fp		NULL
*		|
*		NULL
*
*	float +fp;         
*/
/* 													float					+					fp */
Token *errorSymbolTree(char *iden, char *symbol, char *leftTkIden) {
	int start = 0;
	OperatorToken *opeTk;
	IdentifierToken *leftTk, *idenTk;
	
	idenTk = (IdentifierToken *)createOperatorToken(iden, start, 5);
	opeTk = (OperatorToken *)createOperatorToken(symbol, start, 1);
	leftTk = (IdentifierToken *)createIdentifierToken(leftTkIden, start, 2);	
	idenTk->token = (Token *)opeTk;
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
/* 
*				double 
*					|
*					y
*					|
*				NULL
*
*		double y;
*		y is double
* 
*/
/* 									double					y */
Token *YisDouble(char *iden, char *token) {
	int start = 0;
	IdentifierToken *idenTk, *Tk;
	
	idenTk = (IdentifierToken *)createIdentifierToken(iden, start, 6);
	Tk = (IdentifierToken *)createIdentifierToken(token, start, 1);
	idenTk->token = (Token *)Tk;
	Tk->token = NULL;
	
	return (Token *)idenTk;
}
/* 
*							float
*							|
*							*
*						/ \						
*					*		NULL
*				/  \
*			y		NULL
*
*		float **y;
*			y is pointer to pointer to float.	
*/
/* 															float        *										*									y */
Token *yisPointertoPointer(char *iden, char *firstsymbol, char *secondsymbol, char *leftTkIden) {
	int start = 0;
	OperatorToken *firstopeTk, *secondopeTk;
	IdentifierToken *idenTk, *leftTk;
	
	idenTk = (IdentifierToken *)createIdentifierToken(iden, start, 5);
	firstopeTk = (OperatorToken *)createOperatorToken(firstsymbol, start, 1);
	secondopeTk = (OperatorToken *)createOperatorToken(secondsymbol, start, 1);
	leftTk = (IdentifierToken *)createIdentifierToken(leftTkIden, start, 1);
	idenTk->token = (Token *)firstopeTk;
	firstopeTk->token[0] = (Token *)secondopeTk;
	firstopeTk->token[1] = NULL;
	secondopeTk->token[0] = (Token *)leftTk;
	secondopeTk->token[1] = NULL;
	leftTk->token = NULL;
	
	return (Token *)idenTk;
	}
/* 
*					char
*					|
*					(
*				/ 	\
*			foo		int 
*
*		char foo(int );
*			foo is function taking int returning char.
* */
/* 										char					(								foo							int */
Token *fooisFunc(char *iden, char *symbol, char *leftTkIden, char *rightTkIden) {
	int start = 0;
	OperatorToken *opeTk;
	IdentifierToken *idenTk, *rightTk, *leftTk;
	
	idenTk = (IdentifierToken *)createIdentifierToken(iden, start, 4);
	opeTk = (OperatorToken *)createOperatorToken(symbol, start, 1);
	rightTk = (IdentifierToken *)createIdentifierToken(rightTkIden, start, 3);
	leftTk = (IdentifierToken *)createIdentifierToken(leftTkIden, start, 3);
	idenTk->token = (Token *)opeTk;
	opeTk->token[0] = (Token *)leftTk;
	opeTk->token[1] = (Token *)rightTk;
	leftTk->token = NULL;
	
	return (Token *)idenTk;
}
/* 
*					long
*					|
*					(
*				/ 	\
*			foo		 NULL
*
*		long foo( );
*			foo is function taking nothing returning long.
*/
/* 													long					(								foo		 							NULL*/
Token *fooisFuncreturnNoth(char *iden, char *symbol, char *leftTkIden, char *rightTkIden) {
	int start = 0;
	OperatorToken *opeTk;
	IdentifierToken *idenTk, *leftTk, *rightTk;
	
	idenTk = (IdentifierToken *)createIdentifierToken(iden, start, 4);
	opeTk = (OperatorToken *)createOperatorToken(symbol, start, 1);
	leftTk = (IdentifierToken *)createIdentifierToken(leftTkIden, start, 3);
	rightTk = (IdentifierToken *)createIdentifierToken(rightTkIden, start, 4);
	idenTk->token = (Token *)opeTk;
	opeTk->token[0] = (Token *)leftTk;
	opeTk->token[1] = (Token *)rightTk;
	leftTk->token = NULL;
	
	return (Token *)idenTk;
}
/*	 			int 
*					|
*					[
*				/  \
*	 		[		 2
*		/	 \
*	dog		4
*
*		int dog[4][2];
*			dog is array 4 of array 2 of int.
*/
/*                            [                       [          int          dog                 2             4 */
Token *dogarrayarray(char *firstsymbol, char *secondsymbol, char *iden, char *leftTkIden, char *firstInt, char *second) {
  int start = 0;
  OperatorToken *firstopeTk, *secondopeTk;
  IntegerToken *firstIntTk, *secondIntTk;
  IdentifierToken *idenTk, *leftTk;
  
  idenTk = (IdentifierToken *)createIdentifierToken(iden, start, 3);
  firstopeTk = (OperatorToken *)createOperatorToken(firstsymbol, start, 1);
  secondopeTk = (OperatorToken *)createOperatorToken(secondsymbol, start, 1);
  firstIntTk = (IntegerToken *)createIntegerToken(firstInt, start, 1);
  secondIntTk = (IntegerToken *)createIntegerToken(second, start, 1);
  leftTk = (IdentifierToken *)createIdentifierToken(leftTkIden, start, 3);
  idenTk->token = (Token *)firstopeTk;
	firstopeTk->token[0] = (Token *)secondopeTk;
	firstopeTk->token[1] = (Token *)firstIntTk;
  secondopeTk->token[0] = (Token *)leftTk;
	secondopeTk->token[1] = (Token *)secondIntTk;
	leftTk->token = NULL;
  
  return (Token *)idenTk;
}

*									float
*										|
*										*
*									/  \
*								[  NULL
*							/  \	
*						*		 4
*					/  \
*				[			NULL
*			/  \
*			y   2
*			|
*			NULL
*
*		float *(*y[2])[4];
*			y is array 2 of pointer to array 4 of pointer to float.	

		//	float		*		[		*		4		[		2		y
Token *yArrayPointer(char *iden, char *firope, char *secope, char *thirdope, \
											char *intTk, char *forope, char *secintTk, char *leftTkIden) {
	int start = 0;
	IdentifierToken *idenTk, *leftTk;
	OperatorToken *firleftTk, *secleftTk, *thileftTk, *forleftTk;
	IntegerToken *firrightTk, *secrightTk;
	
	idenTk = (IdentifierToken *)createIdentifierToken(iden, start, 5);
	firleftTk = (OperatorToken *)createOperatorToken(firope, start, 1);
	secleftTk = (OperatorToken *)createOperatorToken(secope, start, 1);
	thileftTk = (OperatorToken *)createOperatorToken(thirdope, start, 1);
	forleftTk = (OperatorToken *)createOperatorToken(forope, start, 1);
	leftTk = (IdentifierToken *)createIdentifierToken(leftTkIden, start, 1);
	firrightTk = (IntegerToken *)createIntegerToken(intTk, start, 1);
	secrightTk = (IntegerToken *)createIntegerToken(secintTk, start, 1);
	idenTk->token = (Token *)firleftTk;
	firleftTk->token[0] = (Token *)secleftTk;
	firleftTk->token[1] = NULL;
	secleftTk->token[0] = (Token *)thileftTk;
	secleftTk->token[1] = (Token *)firrightTk;
	thileftTk->token[0] = (Token *)forleftTk;
	thileftTk->token[1] = NULL;
	forleftTk->token[0] = (Token *)idenTk;
	forleftTk->token[1] = (Token *)secrightTk;
	idenTk->token = NULL;
	
	return (Token *)idenTk;
	}