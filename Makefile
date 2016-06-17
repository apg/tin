CFLAGS = -g -Wall -Werror -std=c99

OBJS = \
	alloc.o \
	cons.o \
	int.o \
	stack.o \
	str.o

HEADERS = \
	gc.h \
	sn.h \
	stack.h

libsn.a: $(OBJS) $(HEADERS)
	$(AR) rcs $@ $(OBJS)

test: libsn.a
	$(MAKE) -C t/ test

clean:
	@rm -if *.o *.a && \
	$(MAKE) -C t/ clean

tags: *.c
	etags *.c

.PHONY: tags clean
