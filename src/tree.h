#ifndef tree_H
#define tree_H
#include "Token.h"

Token *tree(char *iden, char *symbol, char *leftTkIden, char *rightTkInt);
Token *errorTree(char *iden, char *symbol, char *leftTkIden);
Token *errorSymbolTree(char *iden, char *symbol, char *leftTkIden);
Token *secondTree(char *iden, char *firsymbol, char *secsymbol, char *secrightTk, char *secleftTk);
Token *YisDouble(char *iden, char *token);
Token *yisPointertoPointer(char *iden, char *firstsymbol, char *secondsymbol, char *leftTkIden);
Token *fooisFunc(char *iden, char *symbol, char *leftTkIden, char *rightTkIden);
Token *fooisFuncreturnNoth(char *iden, char *symbol, char *leftTkIden, char *rightTkIden);
Token *dogarrayarray(char *firstsymbol, char *secondsymbol, char *iden, char *leftTkIden, char *firstInt, char *second);
Token *yArrayPointer(char *iden, char *firope, char *secope, char *thirdope,			 \
char *intTk, char *forope, char *secintTk, char *leftTkIden);
#endif // tree_H;