#include "sn.h"

sn_ptr_t
sn_boxcons(sn_t *S, const sn_cons_t *c)
{
  if (c != NULL) {
    return ((sn_ptr_t) c) | SN_CONS_T;
  }
  return S->NIL;
}

const sn_cons_t *
sn_unboxcons(sn_t *S, sn_ptr_t o)
{
  if ((o & SN_CONS_T) != SN_CONS_T) {
    return NULL;
  }

  return (sn_cons_t *) (o & ~0x3);
}

const sn_cons_t *
sn_cons(sn_t *S, sn_ptr_t a, const sn_cons_t *d)
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
sn_consnil(sn_t *S, sn_ptr_t a)
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

sn_ptr_t
sn_car(sn_t *S, const sn_cons_t *c)
{
  if (c != NULL) {
    return c->car;
  }
  return S->NIL;
}

sn_ptr_t
sn_cdr(sn_t *S, const sn_cons_t *c)
{
  if (c != NULL) {
    return c->cdr;
  }
  return S->NIL;
}
