#include <stdio.h>
#include <stdlib.h>
#include "greatest.h"

/* Declare suites that are externed */
SUITE_EXTERN(core_data_suite);
SUITE_EXTERN(stack_container_suite);
SUITE_EXTERN(stack_manipulation_suite);
SUITE_EXTERN(stack_predicates_suite);
SUITE_EXTERN(stack_pushers_suite);
SUITE_EXTERN(stack_retrieval_suite);

/* */
GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();      /* init & parse command-line args */

  /* Run the suites */
  RUN_SUITE(stack_container_suite);
  RUN_SUITE(core_data_suite);
  RUN_SUITE(stack_container_suite);
  RUN_SUITE(stack_manipulation_suite);
  RUN_SUITE(stack_predicates_suite);
  RUN_SUITE(stack_pushers_suite);
  RUN_SUITE(stack_retrieval_suite);

  GREATEST_MAIN_END();        /* display results */
}
