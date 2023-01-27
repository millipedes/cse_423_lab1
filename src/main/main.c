#include "../token/include/token_list.h"

int main(void) {
  token_list * the_list = generate_token_list("idata/main.py");
  debug_token_list(the_list);
  free_token_list(the_list);
  return 0;
}
