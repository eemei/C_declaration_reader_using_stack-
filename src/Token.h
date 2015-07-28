#ifndef Token_H
#define Token_H
#include <stdint.h>


typedef enum {
	TOKEN_UNKNOWN_TYPE,
	TOKEN_INTEGER_TYPE,
	TOKEN_OPERATOR_TYPE,
	TOKEN_FLOAT_TYPE,
	TOKEN_STRING_TYPE,
	TOKEN_IDENTIFIER_TYPE,
	TOKEN_END_OF_STRING
} TokenType;

typedef enum {
	PREFIX, //-2
	INFIX,	//2*2
	POSTFIX	//x++
} Arity;

typedef enum {
	NONE,
	LEFT_TO_RIGHT,
	RIGHT_TO_LEFT,
} Associativity;                                                                                                                                           

typedef struct {
	TokenType type;
	uint32_t startColumn;
	uint32_t length;
	char *str;
} Token;

typedef struct {
	TokenType type;
	uint32_t startColumn;
	uint32_t length;
	int value;
	char *str;
} IntegerToken;

typedef struct {
	TokenType type;
	uint32_t startColumn;
	uint32_t length;
	double value;
	char *str;
} FloatToken;

typedef struct {
	TokenType type;
	uint32_t startColumn;
	uint32_t length;
	char *name;
	char *str;
	Token *token; //  attract 
} IdentifierToken, StringToken;

typedef struct {
	TokenType type;
	uint32_t startColumn;
	uint32_t length;
	char *str;
	char *symbol;
	Arity arity;
	Token *token[0];
} OperatorToken;



char *createSubString(char *str, int start , int len);
Token *createOperatorToken(char *str, int start, int length);
Token *createFloatToken(char *str, int start, int length);
Token *createIntegerToken(char *str,int start,int length);
Token *createIdentifierToken(char *str,int start, int length);
Token *createStringToken(char *str,int start, int length);
Token *createEndStrToken(char *symbol);

#endif // Token_H