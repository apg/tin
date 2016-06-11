CFLAGS = -g -Wall -Werror -std=c99

OBJS = \
	int.o \
	stack.o \
	cons.o \
	str.o

HEADERS = \
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
