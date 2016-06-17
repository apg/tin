#include <stdlib.h>

#include "gc.h"

sn_object_t *
snC_alloc(sn_t *S, size_t n)
{
  sn_object_t *x;
  if (n < 0) {
    return NULL;
  }

  x = (sn_object_t *)malloc(n);
  if (x == NULL) {
    /* TODO: in some sort of DEBUG mode, maybe print an error? */
    /* TODO: maybe we try to GC? */
    return NULL;
  }

  x->last = S->last;
  S->last = x;

  return x;
}
