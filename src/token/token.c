#include "include/token.h"

token * init_token(int category, char * text, int lineno, char * filename) {
  // For the '+ 1's below, it is for nul terminator ('\0')
  size_t text_len = strnlen(text, MAX_LEXEME_SIZE) + 1;
  size_t filename_len = strnlen(filename, MAX_LEXEME_SIZE) + 1;
  token * the_token = calloc(1, sizeof(struct TOKEN_T));
  the_token->text = calloc(text_len, sizeof(char));
  strncpy(the_token->text, text, text_len - 1);
  the_token->filename = calloc(filename_len, sizeof(char));
  strncpy(the_token->filename, filename, filename_len - 1);
  the_token->lineno = lineno;
  the_token->ival = 0;
  the_token->dval = 0.0;
  the_token->sval = NULL;
  the_token->category = category;
  if(IS_INT_CATEGORY(category))
    the_token->ival = atoi(text);
  else if(IS_REAL_CATEGORY(category))
    the_token->dval = atof(text);
  else if(IS_STRING_CATEGORY(category))
    the_token->sval = handle_string_expansion(text, text_len);
  return the_token;
}

char * handle_string_expansion(char * text, size_t text_len) {
  size_t sval_len = 1;
  char * sval = NULL;
  for(size_t i = 0; i < text_len; i++) {
    if(NOT_QUOTE(text[i])) {
      sval_len++;
      if(!sval)
        sval = calloc(sval_len, sizeof(char));
      else
        sval = realloc(sval, sval_len * sizeof(char));
      if(text[i] == '\\') {
        i++;
        switch(text[i]) {
          case 'n':  strncat(sval, "\n", 2); break;
          case 't':  strncat(sval, "\t", 2); break;
          case '\'': strncat(sval, "\'", 2); break;
          case '\"': strncat(sval, "\"", 2); break;
          case 'f':  strncat(sval, "\f", 2); break;
          case 'r':  strncat(sval, "\r", 2); break;
          default:
            fprintf(stderr, "Unrecognized Escape Char: %c\n", text[i]);
            break;
        }
      } else
        strncat(sval, text + i, 1);
    }
  }
  return sval;
}

void debug_token(token * the_token) {
  printf("category: %s  ", token_type_to_string(the_token->category));
  printf("text: `%s`  ", the_token->text);
  printf("lineno: %d  ", the_token->lineno);
  printf("filename: `%s`  ", the_token->filename);
  if(IS_INT_CATEGORY(the_token->category))
    printf("ival: %d", the_token->ival);
  else if(IS_REAL_CATEGORY(the_token->category))
    printf("dval: %f", the_token->dval);
  else if(IS_STRING_CATEGORY(the_token->category))
    printf("sval: `%s`", the_token->sval);
  printf("\n");
}

void free_token(token * the_token) {
  if(the_token) {
    if(the_token->text)
      free(the_token->text);
    if(the_token->filename)
      free(the_token->filename);
    if(the_token->sval)
      free(the_token->sval);
    free(the_token);
  }
}
