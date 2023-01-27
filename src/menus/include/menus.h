/**
 * @file   menus.h
 * @brief  This file contains the function definitions and macros for menus.c
 * @author Matthew C. Lindeman
 * @date   Junuary 27, 2023
 * @bug    None known
 * @todo   Nothing
 */
#ifndef MEN_H
#define MEN_H

#include <stdio.h>
#include "../../token/include/token_type.h"
#include "../../main/include/constants_macros.h"

// Is type t a reserved word that is not supported?
#define RESERVED_WORD_NOT_SUPPORTED(t) ((t == IS)        \
                                        || (t == IN)     \
                                        || (t == IS_NOT) \
                                        || (t == NOT_IN)) ? 1 : 0

void print_not_puny_supported_reserved_word(token_type rw);

#endif
