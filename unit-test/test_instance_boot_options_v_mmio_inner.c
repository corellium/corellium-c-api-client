#ifndef instance_boot_options_v_mmio_inner_TEST
#define instance_boot_options_v_mmio_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_boot_options_v_mmio_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_boot_options_v_mmio_inner.h"
instance_boot_options_v_mmio_inner_t* instantiate_instance_boot_options_v_mmio_inner(int include_optional);



instance_boot_options_v_mmio_inner_t* instantiate_instance_boot_options_v_mmio_inner(int include_optional) {
  instance_boot_options_v_mmio_inner_t* instance_boot_options_v_mmio_inner = NULL;
  if (include_optional) {
    instance_boot_options_v_mmio_inner = instance_boot_options_v_mmio_inner_create(
      "0",
      "0",
      "0"
    );
  } else {
    instance_boot_options_v_mmio_inner = instance_boot_options_v_mmio_inner_create(
      "0",
      "0",
      "0"
    );
  }

  return instance_boot_options_v_mmio_inner;
}


#ifdef instance_boot_options_v_mmio_inner_MAIN

void test_instance_boot_options_v_mmio_inner(int include_optional) {
    instance_boot_options_v_mmio_inner_t* instance_boot_options_v_mmio_inner_1 = instantiate_instance_boot_options_v_mmio_inner(include_optional);

	cJSON* jsoninstance_boot_options_v_mmio_inner_1 = instance_boot_options_v_mmio_inner_convertToJSON(instance_boot_options_v_mmio_inner_1);
	printf("instance_boot_options_v_mmio_inner :\n%s\n", cJSON_Print(jsoninstance_boot_options_v_mmio_inner_1));
	instance_boot_options_v_mmio_inner_t* instance_boot_options_v_mmio_inner_2 = instance_boot_options_v_mmio_inner_parseFromJSON(jsoninstance_boot_options_v_mmio_inner_1);
	cJSON* jsoninstance_boot_options_v_mmio_inner_2 = instance_boot_options_v_mmio_inner_convertToJSON(instance_boot_options_v_mmio_inner_2);
	printf("repeating instance_boot_options_v_mmio_inner:\n%s\n", cJSON_Print(jsoninstance_boot_options_v_mmio_inner_2));
}

int main() {
  test_instance_boot_options_v_mmio_inner(1);
  test_instance_boot_options_v_mmio_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_boot_options_v_mmio_inner_MAIN
#endif // instance_boot_options_v_mmio_inner_TEST
