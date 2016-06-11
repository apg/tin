#include "greatest.h"
#include "../sn.h"

TEST test_boxint(void)
{
  sn_ptr_t actual;
  actual = sn_boxint(NULL, 1);
  ASSERT_EQ_FMT((sn_ptr_t) 2, actual, "%d");

  actual = sn_boxint(NULL, -1);
  ASSERT_EQ_FMT((sn_ptr_t) -2, actual, "%d");

  PASS();
}

TEST test_unboxint(void)
{
  int actual;
  actual = sn_unboxint(NULL,  sn_boxint(NULL, 2));

  ASSERT_EQ(2, actual);
  PASS();
}


GREATEST_SUITE(core_data_suite) {
  RUN_TEST(test_boxint);
  RUN_TEST(test_unboxint);
}
