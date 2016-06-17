#include "sn.h"

sn_value_t
sn_boxint(sn_t *S, int i)
{
  sn_value_t v;
  v.flags = SN_INT_T;
  v.i = i;
  return v;
}

int
sn_unboxint(sn_t *S, sn_value_t v)
{
  if ((v.flags & SN_INT_T) != SN_INT_T) {
    return 0;
  }
  return v.i;
}
