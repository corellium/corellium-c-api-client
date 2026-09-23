#ifndef login_result_domain_device_auto_shutdown_TEST
#define login_result_domain_device_auto_shutdown_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define login_result_domain_device_auto_shutdown_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/login_result_domain_device_auto_shutdown.h"
login_result_domain_device_auto_shutdown_t* instantiate_login_result_domain_device_auto_shutdown(int include_optional);



login_result_domain_device_auto_shutdown_t* instantiate_login_result_domain_device_auto_shutdown(int include_optional) {
  login_result_domain_device_auto_shutdown_t* login_result_domain_device_auto_shutdown = NULL;
  if (include_optional) {
    login_result_domain_device_auto_shutdown = login_result_domain_device_auto_shutdown_create(
      true,
      10
    );
  } else {
    login_result_domain_device_auto_shutdown = login_result_domain_device_auto_shutdown_create(
      true,
      10
    );
  }

  return login_result_domain_device_auto_shutdown;
}


#ifdef login_result_domain_device_auto_shutdown_MAIN

void test_login_result_domain_device_auto_shutdown(int include_optional) {
    login_result_domain_device_auto_shutdown_t* login_result_domain_device_auto_shutdown_1 = instantiate_login_result_domain_device_auto_shutdown(include_optional);

	cJSON* jsonlogin_result_domain_device_auto_shutdown_1 = login_result_domain_device_auto_shutdown_convertToJSON(login_result_domain_device_auto_shutdown_1);
	printf("login_result_domain_device_auto_shutdown :\n%s\n", cJSON_Print(jsonlogin_result_domain_device_auto_shutdown_1));
	login_result_domain_device_auto_shutdown_t* login_result_domain_device_auto_shutdown_2 = login_result_domain_device_auto_shutdown_parseFromJSON(jsonlogin_result_domain_device_auto_shutdown_1);
	cJSON* jsonlogin_result_domain_device_auto_shutdown_2 = login_result_domain_device_auto_shutdown_convertToJSON(login_result_domain_device_auto_shutdown_2);
	printf("repeating login_result_domain_device_auto_shutdown:\n%s\n", cJSON_Print(jsonlogin_result_domain_device_auto_shutdown_2));
}

int main() {
  test_login_result_domain_device_auto_shutdown(1);
  test_login_result_domain_device_auto_shutdown(0);

  printf("Hello world \n");
  return 0;
}

#endif // login_result_domain_device_auto_shutdown_MAIN
#endif // login_result_domain_device_auto_shutdown_TEST
