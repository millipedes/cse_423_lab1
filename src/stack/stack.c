#include "include/stack.h"

group * init_group(void) {
  group * the_group = calloc(1, sizeof(struct GROUP_T));
  the_group->value = 0;
  return the_group;
}

group * adjust_group(group * the_group, void * value) {
  the_group->value += INT_CAST(value);
  return the_group;
}

void debug_group(group * the_group) {
  printf("[GROUP]: %d\n", the_group->value);
}

void free_group(group * the_group) {
  if(the_group)
    free(the_group);
}

stack * init_stack(void * value) {
  stack * the_stack = calloc(1, sizeof(struct STACK_T));
  the_stack->current_tabstop = init_group();
  the_stack->current_tabstop = adjust_group(the_stack->current_tabstop, value);
  the_stack->prev = NULL;
  the_stack->value = value;
  return the_stack;
}

stack * push(stack * the_stack, void * value) {
  if(INT_STACK_LT(the_stack, value) || INT_STACK_CMP(the_stack, value)) {
    stack * tmp = init_stack(value);
    tmp->prev = the_stack;
    return tmp;
  } else {
    fprintf(stderr, "Indentation is Incorrect\nCurrent Indentation Level: %d"
        "\nAttempted Indent Level: %d\n", INT_CAST(the_stack->value),
        INT_CAST(value));
    return NULL;
  }
}

stack * pop(stack * the_stack) {
  if(INT_CAST(the_stack->value)) {
    stack * tmp = the_stack->prev;
    free_current_stack(the_stack);
    return tmp;
  } else
    return the_stack;
}

void debug_stack(stack * the_stack) {
  printf("[STACK]\n");
  printf("value: %d\n", INT_CAST(the_stack->value));
  debug_group(the_stack->current_tabstop);
  if(the_stack->prev)
    debug_stack(the_stack->prev);
  else
    printf("END OF STACK\n");
} 

void free_current_stack(stack * the_stack) {
  if(the_stack) {
    if(the_stack->current_tabstop)
      free_group(the_stack->current_tabstop);
    if(the_stack->value)
      free(the_stack->value);
    free(the_stack);
  }
}
