#include "greatest.h"

TEST foo(void) {
  PASS();
}

GREATEST_SUITE(stack_retrieval_suite) {
  RUN_TEST(foo);
}
