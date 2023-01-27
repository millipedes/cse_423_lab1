/**
 * @file   main.c
 * @brief  This file contains the entry point to the code.
 * @author Matthew C. Lindeman
 * @date   January 27, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "../token/include/token_list.h"

int main(void) {
  token_list * the_list = generate_token_list("idata/main.py");
  debug_token_list(the_list);
  free_token_list(the_list);
  return 0;
}
