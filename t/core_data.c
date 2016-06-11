#include "greatest.h"

TEST foo(void) {
  PASS();
}

GREATEST_SUITE(core_data_suite) {
  RUN_TEST(foo);
}
