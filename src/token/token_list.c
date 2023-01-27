/**
 * @file   token_list.c
 * @brief  This file contains the functions that are required to maintain the
 * token_list data structure.
 * @author Matthew C. Lindeman
 * @date   January 27, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "include/token_list.h"

/**
 * This function initializes a token_list data structure will null members.
 * @param       N/a
 * @return the_list - The initialized token_list.
 */
token_list * init_token_list(void) {
  token_list * the_list = calloc(1, sizeof(struct TOKEN_LIST_T));
  the_list->value = NULL;
  the_list->next = NULL;
  return the_list;
}

/**
 * This function adds the_token to the_list token_list.
 * @paramn  the_list - The token_list that will have the token added to it.
 * @paramn the_token - The token that will be added to the list.
 * @return  the_list - The token_list with the token added.
 */
token_list * add_token(token_list * the_list, token * the_token) {
  if(!the_list->value) {
    the_list->value = the_token;
    return the_list;
  }
  token_list * tmp = the_list;
  while(tmp->next) tmp = tmp->next;
  tmp->next = init_token_list();
  tmp->next->value = the_token;
  return the_list;
}

/**
 * This function generates the token_list for a given file_name.
 * @param file_name - The file_name of the file which is being lexed.
 * @return the_list - The token_list of all tokens in the file.
 */
token_list * generate_token_list(char * file_name) {
  token_list * the_list = init_token_list();
  yyin = fopen(file_name, "r");
  int value = yylex();
  while(value != ENDMARKER) {
    if(RESERVED_WORD_NOT_SUPPORTED(value))
      print_not_puny_supported_reserved_word(value);
    if(!NO_TOK(value)) {
      if(dedent_qty) {
        while(dedent_qty) {
          the_list = add_token(the_list, init_token(value, yytext, yylineno,
                file_name));
          dedent_qty--;
        }
      } else {
        the_list = add_token(the_list, init_token(value, yytext, yylineno,
              file_name));
      }
    }
    value = yylex();
  }
  while(INT_CAST(indent_stack->value)) indent_stack = pop(indent_stack);
  free_current_stack(indent_stack);
  fclose(yyin);
  yylex_destroy();
  return the_list;
}

/**
 * This function debugs the tokens in the token_list.
 * @param the_list - The token_list to be debugged.
 * @return     N/a
 */
void debug_token_list(token_list * the_list) {
  if(the_list->value)
    debug_token(the_list->value);
  if(the_list->next)
    debug_token_list(the_list->next);
}

/**
 * This function frees a token_list.
 * @param the_list - The token list to be freed.
 * @return     N/a
 */
void free_token_list(token_list * the_list) {
  if(the_list) {
    if(the_list->value)
      free_token(the_list->value);
    if(the_list->next)
      free_token_list(the_list->next);
    free(the_list);
  }
}
