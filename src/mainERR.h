#ifndef mainERR_H
#define mainERR_H
#include "Token.h"

#include "ERR_MALFORMED_DECLARATION.h"
#include "CException.h"
#include <malloc.h>
						
void	illegalTokenizers(Token *root);
void illegalOperatorSymbol(Token *token);

#endif // mainERR_H
