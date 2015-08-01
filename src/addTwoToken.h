#ifndef addTwoToken_H
#define addTwoToken_H
#include "Token.h"

Token *tree(char *iden, char *symbol, char *leftTkIden, char *rightTkInt);
Token *errorTree(char *iden, char *symbol, char *leftTkIden);
Token *secondTree(char *iden, char *firsymbol, char *secsymbol, char *secrightTk, char *secleftTk);
#endif // addTwoToken_H;