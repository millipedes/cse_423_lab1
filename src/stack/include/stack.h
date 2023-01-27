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

#define INT_CAST(x) *((int *)(x))

#define INT_STACK_LT(s, x)   INT_CAST(s->value) <  INT_CAST(x) ? 1 : 0
#define INT_STACK_GT(s, x)   INT_CAST(s->value) >  INT_CAST(x) ? 1 : 0
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
