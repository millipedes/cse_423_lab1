/**
 * @file   token_list.h
 * @brief  This file contains the function definitions and macros for
 * token_list.c
 * @author Matthew C. Lindeman
 * @date   January 27, 2023
 * @bug    None known
 * @todo   Nothing
 */
#ifndef TOKL_H
#define TOKL_H

#include "token.h"
#include "../../lexer/include/punylex.h"
#include "../../stack/include/stack.h"
#include "../../menus/include/menus.h"

// If t is a type that has no corresponding token generated.
#define NO_TOK(t)    ((t == COMMENT) \
                       || (t == NODENT)) ? 1 : 0

extern FILE * yyin;
extern char * yytext;
extern int yylineno;
extern stack * indent_stack;
extern int update_stack(size_t value);
extern int dedent_qty;

typedef struct TOKEN_LIST_T {
  token * value;
  struct TOKEN_LIST_T * next;
} token_list;

token_list * init_token_list(void);
token_list * add_token(token_list * the_list, token * the_token);
token_list * generate_token_list(char * file_name);
void debug_token_list(token_list * the_list);
void free_token_list(token_list * the_list);

#endif
