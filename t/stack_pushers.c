#include "greatest.h"

TEST foo(void) {
  PASS();
}

GREATEST_SUITE(stack_pushers_suite) {
  RUN_TEST(foo);
}
