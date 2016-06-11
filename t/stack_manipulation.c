#include "greatest.h"

TEST foo(void) {
  PASS();
}

GREATEST_SUITE(stack_manipulation_suite) {
  RUN_TEST(foo);
}
