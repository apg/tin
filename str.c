#include "sn.h"

sn_ptr_t
sn_boxstr(sn_t *S, char *s)
{
  return 0;
}

sn_ptr_t
sn_boxstrl(sn_t *S, char *s, size_t n)
{
  return S->NIL;
}

sn_ptr_t
sn_boxintern(sn_t *S, char *s)
{
  return S->NIL;
}

sn_ptr_t
sn_boxinternl(sn_t *S, char *s, size_t n)
{
  return S->NIL;
}

const char *
sn_unboxstr(sn_t *S, sn_ptr_t o)
{
  return NULL;
}
