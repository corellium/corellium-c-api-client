#ifndef install_firmware_body_TEST
#define install_firmware_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define install_firmware_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/install_firmware_body.h"
install_firmware_body_t* instantiate_install_firmware_body(int include_optional);



install_firmware_body_t* instantiate_install_firmware_body(int include_optional) {
  install_firmware_body_t* install_firmware_body = NULL;
  if (include_optional) {
    install_firmware_body = install_firmware_body_create(
      "0"
    );
  } else {
    install_firmware_body = install_firmware_body_create(
      "0"
    );
  }

  return install_firmware_body;
}


#ifdef install_firmware_body_MAIN

void test_install_firmware_body(int include_optional) {
    install_firmware_body_t* install_firmware_body_1 = instantiate_install_firmware_body(include_optional);

	cJSON* jsoninstall_firmware_body_1 = install_firmware_body_convertToJSON(install_firmware_body_1);
	printf("install_firmware_body :\n%s\n", cJSON_Print(jsoninstall_firmware_body_1));
	install_firmware_body_t* install_firmware_body_2 = install_firmware_body_parseFromJSON(jsoninstall_firmware_body_1);
	cJSON* jsoninstall_firmware_body_2 = install_firmware_body_convertToJSON(install_firmware_body_2);
	printf("repeating install_firmware_body:\n%s\n", cJSON_Print(jsoninstall_firmware_body_2));
}

int main() {
  test_install_firmware_body(1);
  test_install_firmware_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // install_firmware_body_MAIN
#endif // install_firmware_body_TEST
