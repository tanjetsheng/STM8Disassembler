#ifndef Exception_H
#define Exception_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

typedef struct Exception Exception;
typedef struct Exception* ExceptionPtr;
struct Exception {
  char *msg;
  int  errorCode;
  void *data;
};

Exception *createException(char *msg, int errorCode);
void freeException(Exception *e);
void dumpErrorMessage(Exception *e);

void throwException(int errorCode, void *data, char *message, ...);

#endif // Exception_H
