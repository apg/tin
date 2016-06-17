/**
 * sn.h: Interface description
 *
 * Copyright (C) 2014 Andrew Gwozdziewycz <web@apgwoz.com>
 *
 * This file is part of Tin.
 *
 * Tin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Tin is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Tin.  If not, see <http:www.gnu.org/licenses/>.
 */

#ifndef SN_H_
#define SN_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef int sn_int_t;

typedef struct Value sn_value_t;


/* #define BOX_INT(x) ((sn_ptr_t) x << 1) */
/* #define BOX_CONS(x) (((sn_ptr_t) x) | SN_CONS_T) */
/* #define BOX_OBJ(x) (((sn_ptr_t) x) | SN_OBJ_T) */
/* #define UNBOX_INT(x) ((sn_int_t) x >> 1) */
/* #define UNBOX_CONS(x) ((sn_cons_t *) (x & ~0x3)) */
/* #define UNBOX_OBJ(x) ((sn_obj_t *) (x & ~0x3)) */
/* #define UNBOX(x, type) ((type *)UNBOX_OBJ(x)) */
/* #define IS_OBJ(x) ((x & 0x3) == SN_OBJ_T) */
/* #define IS_CONS(x) ((x & 0x3) == SN_CONS_T) */
/* #define IS_INT(x) ((x & 0x1) == 0x0) */
/* #define TAGOF_PTR(x) (((x & 0x3) == SN_OBJ_T) ? TAGOF_OBJ(UNBOX_OBJ(x)) : (x & 0x3)) */
/* #define TAGOF_OBJ(x) (x->flags & 0x1f) */

/* #define MKFLAGS(tdx, tag) ((tdx << 5) | tag) */
/* #define TYPEIDX(x) (x >> 5) */
/* #define MARKED(x) (x & (1 << SN_INT_BITS)) */
/* #define MARK(x) x = (x | (1 << SN_INT_BITS)) */


typedef enum tag {
  SN_NIL_T = 0,
  SN_INT_T,
  SN_CONS_T,
  SN_STR_T,
} sn_tag_t;

typedef struct Tracked sn_object_t;

struct Tracked {
  sn_object_t *last; /* last allocated object */
  void *pointer;
  int flags;
};

struct Value {
  int flags;
  union {
    sn_object_t *o;
    int i;
  };
};

typedef struct cons {
  sn_value_t cdr;
  sn_value_t car;
} sn_cons_t;

typedef struct str {
  const char *data;
  size_t len;
} sn_str_t;

typedef struct Context {
  FILE *ERROR;
  void *(*malloc)(size_t);
  void *(*realloc)(void *, size_t);
  void (*free)(void *);
  sn_value_t NIL;
  sn_object_t *last;
} sn_t;

/**
 * stack pushers
 *
 * Stack pushers hoist C values into tin values.
 */

void sn_pushnil(sn_t *S);
void sn_pushcons(sn_t *S, const sn_cons_t *c);
void sn_pushint(sn_t *S, int i);
void sn_pushstr(sn_t *S, char *str);
void sn_pushstrl(sn_t *S, char *str, size_t n);

/**
 * stack predicates
 *
 * Predicate functions check the type of items on the stack.
 */

/* sn_isnil returns 1 if the index is nil, or 0 otherwise */
int sn_isnil(sn_t *S, int index);

/* sn_iscons returns 1 if the index is a cons, or 0 otherwise */
int sn_iscons(sn_t *S, int index);

/* sn_isint returns 1 if the index is an int, or 0 otherwise */
int sn_isint(sn_t *S, int index);

/* sn_isstr returns 1 if the index is a string, or 0 otherwise */
int sn_isstr(sn_t *S, int index);

/**
 * stack retrieval
 *
 * Retrieval functions return items from the tin stack to C land.
 *
 * Retrieval functions, and the other manipulation functions utilize
 * an integer index argument, which when 0 or,positive, starts at the
 * bottom of the stack. When negative, the index uses subtracts from
 * the top of the stack. Thus -1 would reference the top of the stack,
 * and 0 would reference the bottom.
 */

/* sn_getcons returns indexes the stack and returns a cons if it's a
   cons, NULL otherwise. */
const sn_cons_t *sn_getcons(sn_t *S, int index);

/* sn_getint indexes the stack and returns an int, or 0 otherwise. */
int sn_getint(sn_t *S, int index);

/* sn_getstr indexes the stack and returns a char *, or NULL
   otherwise. */
const char *sn_getstr(sn_t *S, int index);

/**
 * stack manipulation
 *
 * Manipulation functions affect the stack in various ways by either
 * splicing values in, removing them all together, or simply copying
 * values to other positions.
 */

/* sn_replace replaces index with the top of the stack */
int sn_replace(sn_t *S, int index);

/* sn_insert inserts the top of the stack into the index slot, and
   pops the top */
int sn_insert(sn_t *S, int index);

/* sn_push pushes the value at index to the top of the stack */
int sn_push(sn_t *S, int index);

/* sn_remove removes the item and index, and fills the gap by shifting
   the stack down */
int sn_remove(sn_t *S, int index);

/* sn_dup duplicates the top of the stack */
int sn_dup(sn_t *S);

/* sn_checksize returns the current capacity of the stack */
int sn_checksize(sn_t *S);

/**
 * core data
 *
 * Core data functions take C primitive values and convert them
 * into boxed tin values. These are helpful for dealing with
 * conses, and for data structures written in C, but utilized
 * from tin.
 */

sn_value_t sn_boxint(sn_t *S, int i);
sn_value_t sn_boxstr(sn_t *S, char *s);
sn_value_t sn_boxstrl(sn_t *S, char *s, size_t n);
sn_value_t sn_boxintern(sn_t *S, char *s);
sn_value_t sn_boxinternl(sn_t *S, char *s, size_t n);

int sn_unboxint(sn_t *S, sn_value_t o);
const char *sn_unboxstr(sn_t *S, sn_value_t o);
const sn_cons_t *sn_unboxcons(sn_t *S, sn_value_t o);

sn_value_t sn_boxcons(sn_t *S, const sn_cons_t *c);
const sn_cons_t *sn_cons(sn_t *S, sn_value_t a, const sn_cons_t *d);
const sn_cons_t *sn_consnil(sn_t *S, sn_value_t a);

sn_value_t sn_car(sn_t *S, const sn_cons_t *c);
sn_value_t sn_cdr(sn_t *S, const sn_cons_t *c);

#endif
