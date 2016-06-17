/**
 * stack.c - A stack type
 *
 * Supports typical stack operations as well as arbitrary
 * indexing, shifting top n values, and duplicating the entire
 * stack. Stores arbitrary word sized things.
 *
 * Uses the tin context to allocate required memory.
 */


#include "sn.h"
#include "stack.h"

snC_stack_t *
snC_newstack(sn_t *S, size_t size)
{
  snC_stack_t *out;
  out = S->malloc(sizeof(*out));
  if (out == NULL) {  /* TODO: how are we handling this? */
    goto fail;
  }

  /* initialize stack with minimum slots */
  out->stack = S->malloc(sizeof(*out->stack) * SN_MINSTACK);
  if (out->stack == NULL) {
    goto cleanup;
  }

  out->sp = 0;
  out->slots = SN_MINSTACK;
  return out;

 cleanup:
  free(out);

 fail:
  if (S->ERROR != NULL) { /* TODO: Refactor as logging helper, if logging is correct */
    fprintf(S->ERROR, "error: failed to allocate space for stack");
  }
  return NULL;
}

void
snC_freestack(sn_t *S, snC_stack_t *stack)
{
  if (stack == NULL) {
    return;
  }
  if (stack->stack != NULL) {
    S->free(stack->stack);
  }
  S->free(stack);
}

/* snC_stackat accepts a positive index and returns the object at, or
   NIL */
sn_value_t
snC_stackat(sn_t *S, snC_stack_t *stack, int index)
{
  if (stack != NULL && index >= 0 && index < stack->sp) {
    return stack->stack[index];
  }
  return S->NIL; /* TODO: reconsider error handling here */
}

void
snC_stackset(sn_t *S, snC_stack_t *stack, int index, sn_value_t value)
{
  if (stack != NULL && index >= 0 && index < stack->sp) {
    stack->stack[index] = value;
  }
}

int
snC_stackpush(sn_t *S, snC_stack_t *stack, sn_value_t value)
{
  if (stack->sp >= stack->slots) {
    /* TODO: Should maybe consider doing 1.5x the stack->slots,
       instead of 2x */
    stack->stack = S->realloc(stack->stack, stack->slots * 2);
    if (stack->stack == NULL) {
      return 0; /* TODO: reconsider error handling here */
    }
  }

  stack->stack[stack->sp++] = value;
  return 1;
}

sn_value_t
snC_stackpop(sn_t *S, snC_stack_t *stack)
{
  if (stack != NULL && stack->sp > 0) {
    return stack->stack[--stack->sp];
  }
  return S->NIL;
}

/* snC_stackshift shifts the elements above index left or right
 *
 * In the case of expansion, the original value at index will remain.
 *
 * shift([1, 2, 3, 4], 1, 2) => [1, 2, 2, 2, 3, 4]
 */
int
snC_stackshift(sn_t *S, snC_stack_t *stack, int index, int shift)
{
  int i;
  if (stack == NULL || index < 0 || index >= stack->sp) {
    return 0; /* TODO: Reconsider error handling */
  }

  /* if shift > 0 */
  if (shift > 0) {
    /* TODO: figure out the number of slots necessary, and ensure we have them all
       DANGER: For now, just segfault if we don't have enough.
     */

    for (i = stack->sp-1; i >= index; i--) {
      stack->stack[i+shift] = stack->stack[i];
    }
  } else if (shift < 0) {
    for (i = index; i < stack->sp; i++) {
      stack->stack[i] = stack->stack[i-shift];
    }
  }
  stack->sp += shift;
  return 1;
}
