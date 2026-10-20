#ifndef kernel_thread_v1_TEST
#define kernel_thread_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define kernel_thread_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/kernel_thread_v1.h"
kernel_thread_v1_t* instantiate_kernel_thread_v1(int include_optional);



kernel_thread_v1_t* instantiate_kernel_thread_v1(int include_optional) {
  kernel_thread_v1_t* kernel_thread_v1 = NULL;
  if (include_optional) {
    kernel_thread_v1 = kernel_thread_v1_create(
      "0",
      56,
      list_createList()
    );
  } else {
    kernel_thread_v1 = kernel_thread_v1_create(
      "0",
      56,
      list_createList()
    );
  }

  return kernel_thread_v1;
}


#ifdef kernel_thread_v1_MAIN

void test_kernel_thread_v1(int include_optional) {
    kernel_thread_v1_t* kernel_thread_v1_1 = instantiate_kernel_thread_v1(include_optional);

	cJSON* jsonkernel_thread_v1_1 = kernel_thread_v1_convertToJSON(kernel_thread_v1_1);
	printf("kernel_thread_v1 :\n%s\n", cJSON_Print(jsonkernel_thread_v1_1));
	kernel_thread_v1_t* kernel_thread_v1_2 = kernel_thread_v1_parseFromJSON(jsonkernel_thread_v1_1);
	cJSON* jsonkernel_thread_v1_2 = kernel_thread_v1_convertToJSON(kernel_thread_v1_2);
	printf("repeating kernel_thread_v1:\n%s\n", cJSON_Print(jsonkernel_thread_v1_2));
}

int main() {
  test_kernel_thread_v1(1);
  test_kernel_thread_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // kernel_thread_v1_MAIN
#endif // kernel_thread_v1_TEST
