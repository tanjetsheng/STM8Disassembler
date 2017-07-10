#include <stdio.h>
#include <stdlib.h>
#include "exception.h"

Exception *createException(char *msg, int errorCode) {
  Exception *e = malloc(sizeof(Exception));
  e->msg = msg;
  e->errorCode = errorCode;
  return e;
}

void freeException(Exception *e) {
  free(e);
}

void dumpException(Exception *e) {
  printf("%s (err=%d)\n", e->msg, e->errorCode);
}
