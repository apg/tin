# Design of tin

Tin is heavily inspired by Lua. The C code that exists, essentially
manipulates a stack and translates values from C -> Tin and Tin -> C.

Core types:
- cons (a pair)
- int
- string (char *)

From here, we build upon it.


builtins:


stack core
    pushnil()
    pushcons(cons)
    pushint(int)
    pushstr(char *)
    pushstrl(char *, size_t)
    
stack interrogation:

    isnil(index)
    iscons(index)
    isint(index)
    isstr(index)
    
stack retrieval:

    const cons getcons(index)
    int getint(index)
    const char *getstr(index)
    
stack manipulation:

    int checksize() // returns size of stack
    int setsize(size) // truncates stack to size
    int replace(index) // replace index with top of the stack, return 1 on success, 0 on error
    int insert(index) // moves top of stack into index, shifting other stack elements.
    int push(index) // copies index to top of stack
    int remove(index) // shifts items above index down one.
    int dup(index) // copies top of stack

boxes / cons manipulation:

    box boxint(int) // converts int to something representable by tin
    box boxstr(char *) // converts string into something representable by tin
    box boxstrl(char *, size_t) // converts string into something representable by tin
    box boxintstr(char *) // interns string, and boxes it
    box boxintstrl(char *, size_t) // interns string, and boxes it

    int unboxint(box)
    const char *unboxstr(box)
    const cons unboxcons(box)

    const cons cons(box, cons)  // create a list
    const cons consnil(box)     // create a single element list

    const box car(cons)
    const box cdr(cons)

read:

    readstring(char *) // reads a string and pushes the value contained to the top of the stack
    readfile(FILE *) // reads the contents of the file into a list and pushes it to the top of the stack

