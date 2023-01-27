#include "include/token_list.h"

token_list * init_token_list(void) {
  token_list * the_list = calloc(1, sizeof(struct TOKEN_LIST_T));
  the_list->value = NULL;
  the_list->next = NULL;
  return the_list;
}

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
    if(indent_stack) {
      if(INT_CAST(indent_stack->value) == 0 && value == NEWLINE) {
        the_list = add_token(the_list, init_token(DEDENT, "", yylineno,
              file_name));
      }
    }
    value = yylex();
  }
  debug_stack(indent_stack);
  while(INT_CAST(indent_stack->value)) indent_stack = pop(indent_stack);
  free_current_stack(indent_stack);
  fclose(yyin);
  yylex_destroy();
  return the_list;
}

void debug_token_list(token_list * the_list) {
  if(the_list->value)
    debug_token(the_list->value);
  if(the_list->next)
    debug_token_list(the_list->next);
}

void free_token_list(token_list * the_list) {
  if(the_list) {
    if(the_list->value)
      free_token(the_list->value);
    if(the_list->next)
      free_token_list(the_list->next);
    free(the_list);
  }
}
