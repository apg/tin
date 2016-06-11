#include "sn.h"

sn_ptr_t
sn_boxint(sn_t *S, int i)
{
  if (i > SN_MAXINT || i < SN_MININT) {
    /* TODO: This should promote! */
    fprintf(stderr, "fatal: %d is too large for range (%d, %d) to store in a native %d-bit integer\n   - TODO: support promotion to bigint\n", i, SN_MAXINT, SN_MININT, SN_INTBITS);
    exit(1);
  }

  return (sn_ptr_t) (i << 1);
}

int
sn_unboxint(sn_t *S, sn_ptr_t o)
{
  if ((o & SN_INT_T) != SN_INT_T) {
    return 0;
  }
  return (int) (o >> 1);
}
