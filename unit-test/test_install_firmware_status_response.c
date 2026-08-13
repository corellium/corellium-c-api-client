#ifndef install_firmware_status_response_TEST
#define install_firmware_status_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define install_firmware_status_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/install_firmware_status_response.h"
install_firmware_status_response_t* instantiate_install_firmware_status_response(int include_optional);



install_firmware_status_response_t* instantiate_install_firmware_status_response(int include_optional) {
  install_firmware_status_response_t* install_firmware_status_response = NULL;
  if (include_optional) {
    install_firmware_status_response = install_firmware_status_response_create(
      corellium_api_install_firmware_status_response__in-progress,
      "0"
    );
  } else {
    install_firmware_status_response = install_firmware_status_response_create(
      corellium_api_install_firmware_status_response__in-progress,
      "0"
    );
  }

  return install_firmware_status_response;
}


#ifdef install_firmware_status_response_MAIN

void test_install_firmware_status_response(int include_optional) {
    install_firmware_status_response_t* install_firmware_status_response_1 = instantiate_install_firmware_status_response(include_optional);

	cJSON* jsoninstall_firmware_status_response_1 = install_firmware_status_response_convertToJSON(install_firmware_status_response_1);
	printf("install_firmware_status_response :\n%s\n", cJSON_Print(jsoninstall_firmware_status_response_1));
	install_firmware_status_response_t* install_firmware_status_response_2 = install_firmware_status_response_parseFromJSON(jsoninstall_firmware_status_response_1);
	cJSON* jsoninstall_firmware_status_response_2 = install_firmware_status_response_convertToJSON(install_firmware_status_response_2);
	printf("repeating install_firmware_status_response:\n%s\n", cJSON_Print(jsoninstall_firmware_status_response_2));
}

int main() {
  test_install_firmware_status_response(1);
  test_install_firmware_status_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // install_firmware_status_response_MAIN
#endif // install_firmware_status_response_TEST
