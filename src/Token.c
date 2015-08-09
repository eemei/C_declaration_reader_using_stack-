#include "Token.h"
#include <malloc.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *  This Token function is collect the data and convert to a token that will differential data
 *  to form different type of token.
 *  Eg.
 *  
 *  Integer Token : 123 ,Ox1234 ,01234...
 *  Operator Token : "+","-"...
 *  Function:
 *    Token *createOperatorToken(char *symbol, Arity AR);
 *    Token *createIntegerToken(int value);
 
 *  Input:
 *    createOperatorToken:
 *    symbol - the symbol that type by user
 *     AR     - that is type of arity such as INFIX, PREFIX and POSTFIX
 *
 *  createIntegerToken：
 *    value - the value that type by user
 *
 *  Return:
 *    that are return a tree that data type is Token
 */

char *createSubString(char *str, int start , int len) {
  char *newStr = malloc(sizeof(char)*(len+1));
  int i = 0;
  int j = start;
  
  while (j < (len+start)) {
	newStr[i] = str[j];
  i++;
  j++;
}
  newStr[i] = 0;
  return newStr;
}

Token *createOperatorToken(char *str, int start, int length) {
  OperatorToken *OpTk = malloc(sizeof(OperatorToken)+(sizeof(Token*)*2));
  OpTk->type = TOKEN_OPERATOR_TYPE;
  OpTk->symbol = createSubString(str,start,length);
  OpTk->startColumn = start;
  OpTk->length = length;
  OpTk->str = str;	
  return (Token*)OpTk;
}

Token *createFloatToken(char *str, int start, int length) {
  FloatToken *FlTk = malloc(sizeof(FloatToken));
  FlTk->type = TOKEN_FLOAT_TYPE;
  FlTk->value = strtod(createSubString(str,start,length),NULL);
  FlTk->startColumn = start;
  FlTk->length = length;
  FlTk->str = str;	
  return (Token*)FlTk;
}

Token *createIntegerToken(char *str,int start,int length) {
  IntegerToken *InTk = malloc(sizeof(IntegerToken));
  InTk->type = TOKEN_INTEGER_TYPE;
  InTk->value = atoi( createSubString(str,start,length));
  InTk->startColumn = start;
  InTk->length = length;
  InTk->str = str;
  return (Token*)InTk;
}

Token *createIdentifierToken(char *str,int start, int length) {
  IdentifierToken *IdTk = malloc(sizeof(IdentifierToken)+(sizeof(Token*)*1));
  IdTk->type = TOKEN_IDENTIFIER_TYPE;
  IdTk->name = createSubString(str,start,length);
  IdTk->startColumn = start;
  IdTk->length = length;
  IdTk->str = str;
  return (Token*)IdTk;
}

Token *createStringToken(char *str,int start, int length) {
  StringToken *StTk = malloc(sizeof(StringToken)+(sizeof(Token*)*1));
  StTk->type = TOKEN_STRING_TYPE;
  StTk->name = createSubString(str,start,length);
  StTk->startColumn = start;
  StTk->length = length;
  StTk->str = str;
  return (Token*)StTk;
}

Token *createEndStrToken(char *symbol) {
  OperatorToken *EndTk = malloc(sizeof(OperatorToken));
  EndTk->type = TOKEN_OPERATOR_TYPE;
  EndTk->symbol = symbol;
  return (Token*)EndTk;
}