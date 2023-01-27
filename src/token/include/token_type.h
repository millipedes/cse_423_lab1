/**
 * @file   token_type.h
 * @brief  This file contains the token_type enum and the function defintions
 * for token_type.c
 * @author Matthew C. Lindeman
 * @date   January 27, 2023
 * @bug    None known
 * @todo   Nothing
 */
#ifndef TOKT_H
#define TOKT_H

#include <stdlib.h>

typedef enum {
  NAME = 257,
  ENDMARKER,
  INT,
  REAL,
  STRING,          // TODO
  NEWLINE,
  INDENT,
  DEDENT,
  NODENT,
  LPAR,
  RPAR,
  LSQB,
  RSQB,
  COLON,
  COMMA,
  SEMI,
  PLUS,
  MINUS,
  STAR,
  SLASH,
  VBAR,
  AMPER,
  LESS,
  GREATER,
  EQUAL,
  DOT,
  PERCENT,
  LBRACE,
  RBRACE,
  EQEQUAL,
  NOTEQUAL,
  LESSEQUAL,
  GREATEREQUAL,
  TILDE,
  CIRCUMFLEX,
  LEFTSHIFT,
  RIGHTSHIFT,
  DOUBLESTAR,
  PLUSEQUAL,
  MINEQUAL,
  STAREQUAL,
  SLASHEQUAL,
  PERCENTEQUAL,
  AMPEREQUAL,
  VBAREQUAL,
  CIRCUMFLEXEQUAL,
  LEFTSHIFTEQUAL,
  RIGHTSHIFTEQUAL,
  DOUBLESTAREQUAL,
  DOUBLESLASH,
  DOUBLESLASHEQUAL,
  AT,
  ATEQUAL,
  RARROW,
  ELLIPSIS,
  COLONEQUAL,
  OP,              // TODO
  AWAIT,           // TODO
  ASYNC,           // TODO
  TYPE_IGNORE,     // TODO
  TYPE_COMMENT,    // TODO
  ERRORTOKEN,      // TODO
  COMMENT,
  NL,              // TODO
  ENCODING,        // TODO
  FALSE,
  NONE,
  TRUE,
  AND,
  AS,
  ASSERT,
  BREAK,
  CLASS,
  CONTINUE,
  DEF,
  DEL,
  ELIF,
  ELSE,
  EXCEPT,
  FINALLY,
  FOR,
  FROM,
  IF,
  IMPORT,
  IN,
  IS,
  IS_NOT,
  LAMBDA,
  NONLOCAL,
  NOT,
  NOT_IN,
  OR,
  GLOBAL,
  RAISE,
  RETURN,
  TRY,
  WHILE,
  WITH,
  YIELD,
  PASS,
} token_type;

const char * token_type_to_string(token_type type);

#endif
