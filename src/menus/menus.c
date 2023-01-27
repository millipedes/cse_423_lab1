/**
 * @file   menus.c
 * @brief  This file contains the user facing menus that are printed on error/warning.
 * @author Matthew C. Lindeman
 * @date   Junuary 27, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "include/menus.h"

/**
 * This function prints the error message for unsupported reserved words.
 * @param   rw - The reserved word which does not exist in puny.
 * @return N/a
 */
void print_not_puny_supported_reserved_word(token_type rw) {
  fprintf(stderr, "[LEXER]: Error, reserved word: `");
  fprintf(stderr, ERROR_COLOR);
  fprintf(stderr, BOLD_COLOR);
  fprintf(stderr, "%s", token_type_to_string(rw));
  fprintf(stderr, END_COLOR);
  fprintf(stderr, "` not supported by puny!\nExiting\n");
  exit(1);
}
