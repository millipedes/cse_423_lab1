#ifndef TOK_H
#define TOK_H

#include <stdio.h>
#include <string.h>

#include "token_type.h"
#include "../../main/include/constants_macros.h"

#define NOT_QUOTE(c) ((c != '\'') && (c != '\"')) ? 1 : 0
#define NOT_NL(c) (c != '\n') ? 1 : 0

#define IS_INT_CATEGORY(x)    (x == INT)  ? 1 : 0
#define IS_REAL_CATEGORY(x)   (x == REAL) ? 1 : 0

#define IS_NAME_CATEGORY(x)   (x == NAME)   ? 1 : 0
#define IS_STRING_CATEGORY(x) (x == STRING) ? 1 : 0
#define IS_INDENT_CATEGORY(x) (x == INDENT) ? 1 : 0
#define IS_DEDENT_CATEGORY(x) (x == DEDENT) ? 1 : 0

typedef struct TOKEN_T {
  int category;
  char * text;
  int lineno;
  char * filename;
  int ival;
  double dval;
  char * sval;
} token;

token * init_token(int category, char * text, int lineno, char * filename);
char * handle_string_expansion(char * text, size_t text_len);
void debug_token(token * the_token);
void free_token(token * the_token);

#endif
