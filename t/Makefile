CFLAGS = -g -Wall -Werror -std=c99
LDFLAGS = ../libsn.a

SUITES = \
	core_data.o \
	stack_container.o \
	stack_manipulation.o \
	stack_predicates.o \
	stack_pushers.o \
	stack_retrieval.o

test: prove
	./prove

prove: $(SUITES) prove.c
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	@rm -if *.o prove

.PHONY: test clean
