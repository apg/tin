#include "sn.h"

void
sn_pushnil(sn_t *S)
{
}

void
sn_pushcons(sn_t *S, const sn_cons_t *c)
{
}

void
sn_pushint(sn_t *S, int i)
{
}

void
sn_pushstr(sn_t *S, char *str)
{
}

void
sn_pushstrl(sn_t *S, char *str, size_t n)
{
}


/* sn_isnil returns 1 if the index is nil, or 0 otherwise */
int
sn_isnil(sn_t *S, int index)
{
  return 0;
}

/* sn_iscons returns 1 if the index is a cons, or 0 otherwise */
int
sn_iscons(sn_t *S, int index)
{
  return 0;
}

/* sn_isint returns 1 if the index is an int, or 0 otherwise */
int
sn_isint(sn_t *S, int index)
{
  return 0;
}

/* sn_isstr returns 1 if the index is a string, or 0 otherwise */
int
sn_isstr(sn_t *S, int index)
{
  return 0;
}

/* sn_getcons returns indexes the stack and returns a cons if it's a
   cons, NULL otherwise. */
const sn_cons_t *
sn_getcons(sn_t *S, int index)
{
  return NULL;
}

/* sn_getint indexes the stack and returns an int, or 0 otherwise. */
int
sn_getint(sn_t *S, int index)
{
  return 0;
}

/* sn_getstr indexes the stack and returns a char *, or NULL
   otherwise. */
const char *
sn_getstr(sn_t *S, int index)
{
  return NULL;
}

/* sn_replace replaces index with the top of the stack */
int
sn_replace(sn_t *S, int index)
{
  return 0;
}

/* sn_insert inserts the top of the stack into the index slot, and
   pops the top */
int
sn_insert(sn_t *S, int index)
{
  return 0;
}

/* sn_push pushes the value at index to the top of the stack */
int
sn_push(sn_t *S, int index)
{
  return 0;
}

/* sn_remove removes the item and index, and fills the gap by shifting
   the stack down */
int
sn_remove(sn_t *S, int index)
{
  return 0;
}

/* sn_dup duplicates the top of the stack */
int
sn_dup(sn_t *S)
{
  return 0;
}

/* sn_checksize returns the current capacity of the stack */
int
sn_checksize(sn_t *S)
{
  return 0;
}
