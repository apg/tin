#ifndef SN_STACK_H__
#define SN_STACK_H__

#define SN_MINSTACK 32

typedef struct stack {
  size_t slots; /* in slots, not bytes */
  sn_int_t sp;
  sn_ptr_t *stack;
} snC_stack_t;

snC_stack_t *snC_newstack(sn_t *S, size_t size);
void snC_freestack(sn_t *S, snC_stack_t *stack);
sn_ptr_t snC_stackat(sn_t *S, snC_stack_t *stack, int index);
void snC_stackset(sn_t *S, snC_stack_t *stack, int index, sn_ptr_t value);
int snC_stackpush(sn_t *S, snC_stack_t *stack, sn_ptr_t value);
sn_ptr_t snC_stackpop(sn_t *S, snC_stack_t *stack);
int snC_stackshift(sn_t *S, snC_stack_t *stack, int n, int shift);

#endif /* SN_STACK_H__ */
