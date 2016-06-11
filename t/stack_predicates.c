#include "greatest.h"

TEST foo(void) {
  PASS();
}

GREATEST_SUITE(stack_predicates_suite) {
  RUN_TEST(foo);
}
