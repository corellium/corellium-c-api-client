#ifndef instance_boot_options_pongo_TEST
#define instance_boot_options_pongo_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_boot_options_pongo_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_boot_options_pongo.h"
instance_boot_options_pongo_t* instantiate_instance_boot_options_pongo(int include_optional);



instance_boot_options_pongo_t* instantiate_instance_boot_options_pongo(int include_optional) {
  instance_boot_options_pongo_t* instance_boot_options_pongo = NULL;
  if (include_optional) {
    instance_boot_options_pongo = instance_boot_options_pongo_create(
      "0",
      "0",
      1.337
    );
  } else {
    instance_boot_options_pongo = instance_boot_options_pongo_create(
      "0",
      "0",
      1.337
    );
  }

  return instance_boot_options_pongo;
}


#ifdef instance_boot_options_pongo_MAIN

void test_instance_boot_options_pongo(int include_optional) {
    instance_boot_options_pongo_t* instance_boot_options_pongo_1 = instantiate_instance_boot_options_pongo(include_optional);

	cJSON* jsoninstance_boot_options_pongo_1 = instance_boot_options_pongo_convertToJSON(instance_boot_options_pongo_1);
	printf("instance_boot_options_pongo :\n%s\n", cJSON_Print(jsoninstance_boot_options_pongo_1));
	instance_boot_options_pongo_t* instance_boot_options_pongo_2 = instance_boot_options_pongo_parseFromJSON(jsoninstance_boot_options_pongo_1);
	cJSON* jsoninstance_boot_options_pongo_2 = instance_boot_options_pongo_convertToJSON(instance_boot_options_pongo_2);
	printf("repeating instance_boot_options_pongo:\n%s\n", cJSON_Print(jsoninstance_boot_options_pongo_2));
}

int main() {
  test_instance_boot_options_pongo(1);
  test_instance_boot_options_pongo(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_boot_options_pongo_MAIN
#endif // instance_boot_options_pongo_TEST
