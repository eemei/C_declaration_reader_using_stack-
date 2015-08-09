#ifndef ERR_MALFORMED_DECLARATION_H
#define ERR_MALFORMED_DECLARATION_H

typedef enum {
  ERR_NO_IDENTIFIER_DECLARATION,
  ERR_OPERATOR_SYMBOL,
  ERR_NO_INTEGER_DECLARATION,
} ErrorCode;

typedef struct {
  char *errorMsg;
  ErrorCode errorCode;
} ErrorObject;
  

void throwError(char *message, ErrorCode errCode);
void freeError(ErrorObject *errObj);

#endif // ERR_MALFORMED_DECLARATION_H
