#include "gc.h"
#include "sn.h"

sn_value_t
sn_boxcons(sn_t *S, const sn_cons_t *c)
{
  sn_value_t x;
  sn_object_t *bc;

  if (c == NULL) {
    return S->NIL;
  }

  bc = snC_alloc(S, sizeof(*bc));
  if (bc == NULL) {
    /* TODO: WARN THAT WE'RE OUT OF MEMORY, GC, etc! */
    return S->NIL;
  }

  x.flags = SN_CONS_T;
  x.o = bc;
  return x;
}

const sn_cons_t *
sn_unboxcons(sn_t *S, sn_value_t o)
{
  if ((o.flags & SN_CONS_T) != SN_CONS_T) {
    return NULL;
  }

  return o.o->pointer;
}

const sn_cons_t *
sn_cons(sn_t *S, sn_value_t a, const sn_cons_t *d)
{
  sn_cons_t *out;
  out = S->malloc(sizeof(*out));
  if (out == NULL) {
    return NULL;
  }

  out->cdr = sn_boxcons(S, d);
  out->car = a;

  /* TODO: link to previous allocation */

  return out;
}

const sn_cons_t *
sn_consnil(sn_t *S, sn_value_t a)
{
  sn_cons_t *out;
  out = S->malloc(sizeof(*out));
  if (out == NULL) {
    return NULL;
  }

  out->cdr = S->NIL;
  out->car = a;

  /* TODO: link to previous allocation */
  return out;
}

sn_value_t
sn_car(sn_t *S, const sn_cons_t *c)
{
  if (c != NULL) {
    return c->car;
  }
  return S->NIL;
}

sn_value_t
sn_cdr(sn_t *S, const sn_cons_t *c)
{
  if (c != NULL) {
    return c->cdr;
  }
  return S->NIL;
}
