/**
 * @file   stack.h
 * @brief  This file contains the relavent function definitions and macros for
 * stack.c
 * @author Matthew C. Lindeman
 * @date   Junuary 27, 2023
 * @bug    None known
 * @todo   Nothing
 */
#ifndef STA_H
#define STA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct GROUP_T {
  unsigned int value : 3;
} group;

group * init_group(void);
group * adjust_group(group * the_group, void * value);
void debug_group(group * the_group);
void free_group(group * the_group);

// cast a given void pointed to be an integer value at given address
#define INT_CAST(x) *((int *)(x))

// Is int x < int value on stack
#define INT_STACK_LT(s, x)   INT_CAST(s->value) <  INT_CAST(x) ? 1 : 0
// Is int x > int value on stack
#define INT_STACK_GT(s, x)   INT_CAST(s->value) >  INT_CAST(x) ? 1 : 0
// Is int x == int value on stack
#define INT_STACK_CMP(s, x)  INT_CAST(s->value) == INT_CAST(x) ? 1 : 0

typedef struct STACK_T {
  void * value;
  struct STACK_T * prev;
  group * current_tabstop;
} stack;

stack * init_stack(void * value);
stack * push(stack * the_stack, void * value);
stack * pop(stack * the_stack);
void debug_stack(stack * the_stack);
void free_current_stack(stack * the_stack);

#endif
