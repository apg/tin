#include "greatest.h"

TEST foo(void) {
  PASS();
}

GREATEST_SUITE(stack_container_suite) {
  RUN_TEST(foo);
}
