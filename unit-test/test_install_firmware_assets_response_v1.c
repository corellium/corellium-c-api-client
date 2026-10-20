#ifndef install_firmware_assets_response_v1_TEST
#define install_firmware_assets_response_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define install_firmware_assets_response_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/install_firmware_assets_response_v1.h"
install_firmware_assets_response_v1_t* instantiate_install_firmware_assets_response_v1(int include_optional);



install_firmware_assets_response_v1_t* instantiate_install_firmware_assets_response_v1(int include_optional) {
  install_firmware_assets_response_v1_t* install_firmware_assets_response_v1 = NULL;
  if (include_optional) {
    install_firmware_assets_response_v1 = install_firmware_assets_response_v1_create(
      "0"
    );
  } else {
    install_firmware_assets_response_v1 = install_firmware_assets_response_v1_create(
      "0"
    );
  }

  return install_firmware_assets_response_v1;
}


#ifdef install_firmware_assets_response_v1_MAIN

void test_install_firmware_assets_response_v1(int include_optional) {
    install_firmware_assets_response_v1_t* install_firmware_assets_response_v1_1 = instantiate_install_firmware_assets_response_v1(include_optional);

	cJSON* jsoninstall_firmware_assets_response_v1_1 = install_firmware_assets_response_v1_convertToJSON(install_firmware_assets_response_v1_1);
	printf("install_firmware_assets_response_v1 :\n%s\n", cJSON_Print(jsoninstall_firmware_assets_response_v1_1));
	install_firmware_assets_response_v1_t* install_firmware_assets_response_v1_2 = install_firmware_assets_response_v1_parseFromJSON(jsoninstall_firmware_assets_response_v1_1);
	cJSON* jsoninstall_firmware_assets_response_v1_2 = install_firmware_assets_response_v1_convertToJSON(install_firmware_assets_response_v1_2);
	printf("repeating install_firmware_assets_response_v1:\n%s\n", cJSON_Print(jsoninstall_firmware_assets_response_v1_2));
}

int main() {
  test_install_firmware_assets_response_v1(1);
  test_install_firmware_assets_response_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // install_firmware_assets_response_v1_MAIN
#endif // install_firmware_assets_response_v1_TEST
