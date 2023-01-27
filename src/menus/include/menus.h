#ifndef MEN_H
#define MEN_H

#include <stdio.h>
#include "../../token/include/token_type.h"
#include "../../main/include/constants_macros.h"

#define RESERVED_WORD_NOT_SUPPORTED(t) ((t == IS)        \
                                        || (t == IN)     \
                                        || (t == IS_NOT) \
                                        || (t == NOT_IN)) ? 1 : 0

void print_not_puny_supported_reserved_word(token_type rw);

#endif
