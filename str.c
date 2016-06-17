#include "gc.h"

sn_value_t
sn_boxstr(sn_t *S, char *s)
{
  return S->NIL;
}

sn_value_t
sn_boxstrl(sn_t *S, char *s, size_t n)
{
  return S->NIL;
}

sn_value_t
sn_boxintern(sn_t *S, char *s)
{
  return S->NIL;
}

sn_value_t
sn_boxinternl(sn_t *S, char *s, size_t n)
{
  return S->NIL;
}

const char *
sn_unboxstr(sn_t *S, sn_value_t o)
{
  return NULL;
}
