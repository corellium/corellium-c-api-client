#ifndef instance_uefi_bootloader_TEST
#define instance_uefi_bootloader_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_uefi_bootloader_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_uefi_bootloader.h"
instance_uefi_bootloader_t* instantiate_instance_uefi_bootloader(int include_optional);



instance_uefi_bootloader_t* instantiate_instance_uefi_bootloader(int include_optional) {
  instance_uefi_bootloader_t* instance_uefi_bootloader = NULL;
  if (include_optional) {
    instance_uefi_bootloader = instance_uefi_bootloader_create(
      "0",
      "0"
    );
  } else {
    instance_uefi_bootloader = instance_uefi_bootloader_create(
      "0",
      "0"
    );
  }

  return instance_uefi_bootloader;
}


#ifdef instance_uefi_bootloader_MAIN

void test_instance_uefi_bootloader(int include_optional) {
    instance_uefi_bootloader_t* instance_uefi_bootloader_1 = instantiate_instance_uefi_bootloader(include_optional);

	cJSON* jsoninstance_uefi_bootloader_1 = instance_uefi_bootloader_convertToJSON(instance_uefi_bootloader_1);
	printf("instance_uefi_bootloader :\n%s\n", cJSON_Print(jsoninstance_uefi_bootloader_1));
	instance_uefi_bootloader_t* instance_uefi_bootloader_2 = instance_uefi_bootloader_parseFromJSON(jsoninstance_uefi_bootloader_1);
	cJSON* jsoninstance_uefi_bootloader_2 = instance_uefi_bootloader_convertToJSON(instance_uefi_bootloader_2);
	printf("repeating instance_uefi_bootloader:\n%s\n", cJSON_Print(jsoninstance_uefi_bootloader_2));
}

int main() {
  test_instance_uefi_bootloader(1);
  test_instance_uefi_bootloader(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_uefi_bootloader_MAIN
#endif // instance_uefi_bootloader_TEST
