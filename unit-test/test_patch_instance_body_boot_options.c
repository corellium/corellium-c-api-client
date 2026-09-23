#ifndef patch_instance_body_boot_options_TEST
#define patch_instance_body_boot_options_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_instance_body_boot_options_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_instance_body_boot_options.h"
patch_instance_body_boot_options_t* instantiate_patch_instance_body_boot_options(int include_optional);

#include "test_instance_boot_options_kernel.c"
#include "test_instance_boot_options_pongo.c"
#include "test_instance_boot_options_fvp.c"


patch_instance_body_boot_options_t* instantiate_patch_instance_body_boot_options(int include_optional) {
  patch_instance_body_boot_options_t* patch_instance_body_boot_options = NULL;
  if (include_optional) {
    patch_instance_body_boot_options = patch_instance_body_boot_options_create(
      "-v debug=0x8 keepsyms=1",
      "-v debug=0x8 keepsyms=1",
      "00008030-001A2D423C29802E",
      "0x1a2b3c4d5e6f",
      "deadbeefcafebabe",
      true,
      true,
      4,
      6144,
      [kalloc],
       // false, not to have infinite recursion
      instantiate_instance_boot_options_kernel(0),
       // false, not to have infinite recursion
      instantiate_instance_boot_options_pongo(0),
      "C39ABCDEFGH1",
      false,
      "0x18000000",
      [a1b2c3d4e5f60718293a4b5c6d7e8f90],
      "359268000000000",
      "310150123456789",
      "CorelliumWiFi",
      "CorelliumWiFi-5G",
      "02:00:00:aa:bb:cc",
      "SM-G973F",
      "samsung",
      "patch1,patch2",
      1,
      "0x800000000",
      true,
      "ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIGFhYmJjY2RkZWVmZmdnaGhpaWpqa2trbGxtbW5ubm9v user@example.com",
      list_createList(),
       // false, not to have infinite recursion
      instantiate_instance_boot_options_fvp(0)
    );
  } else {
    patch_instance_body_boot_options = patch_instance_body_boot_options_create(
      "-v debug=0x8 keepsyms=1",
      "-v debug=0x8 keepsyms=1",
      "00008030-001A2D423C29802E",
      "0x1a2b3c4d5e6f",
      "deadbeefcafebabe",
      true,
      true,
      4,
      6144,
      [kalloc],
      NULL,
      NULL,
      "C39ABCDEFGH1",
      false,
      "0x18000000",
      [a1b2c3d4e5f60718293a4b5c6d7e8f90],
      "359268000000000",
      "310150123456789",
      "CorelliumWiFi",
      "CorelliumWiFi-5G",
      "02:00:00:aa:bb:cc",
      "SM-G973F",
      "samsung",
      "patch1,patch2",
      1,
      "0x800000000",
      true,
      "ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIGFhYmJjY2RkZWVmZmdnaGhpaWpqa2trbGxtbW5ubm9v user@example.com",
      list_createList(),
      NULL
    );
  }

  return patch_instance_body_boot_options;
}


#ifdef patch_instance_body_boot_options_MAIN

void test_patch_instance_body_boot_options(int include_optional) {
    patch_instance_body_boot_options_t* patch_instance_body_boot_options_1 = instantiate_patch_instance_body_boot_options(include_optional);

	cJSON* jsonpatch_instance_body_boot_options_1 = patch_instance_body_boot_options_convertToJSON(patch_instance_body_boot_options_1);
	printf("patch_instance_body_boot_options :\n%s\n", cJSON_Print(jsonpatch_instance_body_boot_options_1));
	patch_instance_body_boot_options_t* patch_instance_body_boot_options_2 = patch_instance_body_boot_options_parseFromJSON(jsonpatch_instance_body_boot_options_1);
	cJSON* jsonpatch_instance_body_boot_options_2 = patch_instance_body_boot_options_convertToJSON(patch_instance_body_boot_options_2);
	printf("repeating patch_instance_body_boot_options:\n%s\n", cJSON_Print(jsonpatch_instance_body_boot_options_2));
}

int main() {
  test_patch_instance_body_boot_options(1);
  test_patch_instance_body_boot_options(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_instance_body_boot_options_MAIN
#endif // patch_instance_body_boot_options_TEST
