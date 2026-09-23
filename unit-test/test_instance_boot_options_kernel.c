#ifndef instance_boot_options_kernel_TEST
#define instance_boot_options_kernel_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_boot_options_kernel_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_boot_options_kernel.h"
instance_boot_options_kernel_t* instantiate_instance_boot_options_kernel(int include_optional);



instance_boot_options_kernel_t* instantiate_instance_boot_options_kernel(int include_optional) {
  instance_boot_options_kernel_t* instance_boot_options_kernel = NULL;
  if (include_optional) {
    instance_boot_options_kernel = instance_boot_options_kernel_create(
      "kernelcache"
    );
  } else {
    instance_boot_options_kernel = instance_boot_options_kernel_create(
      "kernelcache"
    );
  }

  return instance_boot_options_kernel;
}


#ifdef instance_boot_options_kernel_MAIN

void test_instance_boot_options_kernel(int include_optional) {
    instance_boot_options_kernel_t* instance_boot_options_kernel_1 = instantiate_instance_boot_options_kernel(include_optional);

	cJSON* jsoninstance_boot_options_kernel_1 = instance_boot_options_kernel_convertToJSON(instance_boot_options_kernel_1);
	printf("instance_boot_options_kernel :\n%s\n", cJSON_Print(jsoninstance_boot_options_kernel_1));
	instance_boot_options_kernel_t* instance_boot_options_kernel_2 = instance_boot_options_kernel_parseFromJSON(jsoninstance_boot_options_kernel_1);
	cJSON* jsoninstance_boot_options_kernel_2 = instance_boot_options_kernel_convertToJSON(instance_boot_options_kernel_2);
	printf("repeating instance_boot_options_kernel:\n%s\n", cJSON_Print(jsoninstance_boot_options_kernel_2));
}

int main() {
  test_instance_boot_options_kernel(1);
  test_instance_boot_options_kernel(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_boot_options_kernel_MAIN
#endif // instance_boot_options_kernel_TEST
