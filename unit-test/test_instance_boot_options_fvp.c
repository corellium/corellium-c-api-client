#ifndef instance_boot_options_fvp_TEST
#define instance_boot_options_fvp_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_boot_options_fvp_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_boot_options_fvp.h"
instance_boot_options_fvp_t* instantiate_instance_boot_options_fvp(int include_optional);



instance_boot_options_fvp_t* instantiate_instance_boot_options_fvp(int include_optional) {
  instance_boot_options_fvp_t* instance_boot_options_fvp = NULL;
  if (include_optional) {
    instance_boot_options_fvp = instance_boot_options_fvp_create(
      "/usr/local/fvp/bin/FVP_Base_RevC-2xAEMvA",
      {"bp.secure_memory":"false","cluster0.NUM_CORES":"4"},
      ["/tmp/data.bin@0x80000000"],
      ["0x80001000"],
      ["/tmp/dump.bin@0x80000000,0x1000"],
      "cadi-log.xml",
      "true",
      "true",
      "info",
      "true",
      "7000:7010",
      "7100",
      "true",
      "true",
      "true",
      "0x80000000",
      "/usr/local/fvp/plugins/ToolsSharedLib.so",
      "fastram.cfg",
      "/tmp/checkpoint",
      "/tmp/checkpoint",
      "cpi.txt",
      "1000000",
      "3600",
      "3600",
      "60"
    );
  } else {
    instance_boot_options_fvp = instance_boot_options_fvp_create(
      "/usr/local/fvp/bin/FVP_Base_RevC-2xAEMvA",
      {"bp.secure_memory":"false","cluster0.NUM_CORES":"4"},
      ["/tmp/data.bin@0x80000000"],
      ["0x80001000"],
      ["/tmp/dump.bin@0x80000000,0x1000"],
      "cadi-log.xml",
      "true",
      "true",
      "info",
      "true",
      "7000:7010",
      "7100",
      "true",
      "true",
      "true",
      "0x80000000",
      "/usr/local/fvp/plugins/ToolsSharedLib.so",
      "fastram.cfg",
      "/tmp/checkpoint",
      "/tmp/checkpoint",
      "cpi.txt",
      "1000000",
      "3600",
      "3600",
      "60"
    );
  }

  return instance_boot_options_fvp;
}


#ifdef instance_boot_options_fvp_MAIN

void test_instance_boot_options_fvp(int include_optional) {
    instance_boot_options_fvp_t* instance_boot_options_fvp_1 = instantiate_instance_boot_options_fvp(include_optional);

	cJSON* jsoninstance_boot_options_fvp_1 = instance_boot_options_fvp_convertToJSON(instance_boot_options_fvp_1);
	printf("instance_boot_options_fvp :\n%s\n", cJSON_Print(jsoninstance_boot_options_fvp_1));
	instance_boot_options_fvp_t* instance_boot_options_fvp_2 = instance_boot_options_fvp_parseFromJSON(jsoninstance_boot_options_fvp_1);
	cJSON* jsoninstance_boot_options_fvp_2 = instance_boot_options_fvp_convertToJSON(instance_boot_options_fvp_2);
	printf("repeating instance_boot_options_fvp:\n%s\n", cJSON_Print(jsoninstance_boot_options_fvp_2));
}

int main() {
  test_instance_boot_options_fvp(1);
  test_instance_boot_options_fvp(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_boot_options_fvp_MAIN
#endif // instance_boot_options_fvp_TEST
