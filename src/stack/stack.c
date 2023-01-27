/**
 * @file   stack.c
 * @brief  This file contains the relavent functions for stack and group data
 * structures.
 * @author Matthew C. Lindeman
 * @date   Junuary 27, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "include/stack.h"

/**
 * This function initializes a group.
 * @param        N/a
 * @return the_group - The initilized group.
 */
group * init_group(void) {
  group * the_group = calloc(1, sizeof(struct GROUP_T));
  the_group->value = 0;
  return the_group;
}

/**
 * This function adjusts a group for the given value.
 * @param  the_group - The group to be adjusted.
 * @param      value - The value to be adjusted by.
 * @return the_group - The group that has been adjusted.
 */
group * adjust_group(group * the_group, void * value) {
  the_group->value += INT_CAST(value);
  return the_group;
}

/**
 * This function debugs a group.
 * @param the_group - The group to be debugged.
 * @return      N/a
 */
void debug_group(group * the_group) {
  printf("[GROUP]: %d\n", the_group->value);
}

/**
 * This function frees a given group.
 * @param the_group - The group to be freed.
 * @return      N/a
 */
void free_group(group * the_group) {
  if(the_group)
    free(the_group);
}

/**
 * This function initializes a stack with given value.
 * @param      value - The value to intialize the stack with.
 * @return the_stack - The stack that has had the member pushed onto it.
 */
stack * init_stack(void * value) {
  stack * the_stack = calloc(1, sizeof(struct STACK_T));
  the_stack->current_tabstop = init_group();
  the_stack->current_tabstop = adjust_group(the_stack->current_tabstop, value);
  the_stack->prev = NULL;
  the_stack->value = value;
  return the_stack;
}

/**
 * This function pushs a member onto the stack.
 * @param the_stack - The stack to be pushed onto.
 * @param     value - The value to be pushed onto the stack.
 * @return      tmp - The stack with the member pushed.
 */
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

/**
 * This function pops the current stack off the stack and returns the previous
 * member of the stack (unless the 0 member, in which case it just returns the 0
 * member).
 * @param the_stack - The stack to be popped.
 * @return       .\ - The correct stack.
 */
stack * pop(stack * the_stack) {
  if(INT_CAST(the_stack->value)) {
    stack * tmp = the_stack->prev;
    free_current_stack(the_stack);
    return tmp;
  } else
    return the_stack;
}

/**
 * This function debugs a given stack.
 * @param the_stack - The stack to be debugged.
 * @return      N/a
 */
void debug_stack(stack * the_stack) {
  printf("[STACK]\n");
  printf("value: %d\n", INT_CAST(the_stack->value));
  debug_group(the_stack->current_tabstop);
  if(the_stack->prev)
    debug_stack(the_stack->prev);
  else
    printf("END OF STACK\n");
} 

/**
 * This function frees a given stack (only the current, not the whole stack).
 * @param the_stack - The stack to be freed.
 * @return      N/a
 */
void free_current_stack(stack * the_stack) {
  if(the_stack) {
    if(the_stack->current_tabstop)
      free_group(the_stack->current_tabstop);
    if(the_stack->value)
      free(the_stack->value);
    free(the_stack);
  }
}
