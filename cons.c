#include "sn.h"

const sn_cons_t *
sn_unboxcons(sn_t *S, sn_ptr_t o)
{

}

const sn_cons_t *
sn_cons(sn_t *S, sn_ptr_t a, const sn_cons_t *d)
{

}

const sn_cons_t *
sn_consnil(sn_t *S, sn_ptr_t a)
{

}

sn_ptr_t
sn_car(sn_t *S, const sn_cons_t *c)
{
  return S->NIL;
}

sn_ptr_t
sn_cdr(sn_t *S, const sn_cons_t *c)
{
  return S->NIL;
}
