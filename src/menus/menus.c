#include "include/menus.h"


void print_not_puny_supported_reserved_word(token_type rw) {
  fprintf(stderr, "[LEXER]: Error, reserved word: `");
  fprintf(stderr, ERROR_COLOR);
  fprintf(stderr, BOLD_COLOR);
  fprintf(stderr, "%s", token_type_to_string(rw));
  fprintf(stderr, END_COLOR);
  fprintf(stderr, "` not supported by puny!\nExiting\n");
  exit(1);
}
