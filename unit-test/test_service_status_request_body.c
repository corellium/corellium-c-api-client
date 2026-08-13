#ifndef service_status_request_body_TEST
#define service_status_request_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define service_status_request_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/service_status_request_body.h"
service_status_request_body_t* instantiate_service_status_request_body(int include_optional);

#include "test_sys_info_schema.c"
#include "test_layout_schema.c"
#include "test_pool_usage_schema.c"
#include "test_network_schema.c"


service_status_request_body_t* instantiate_service_status_request_body(int include_optional) {
  service_status_request_body_t* service_status_request_body = NULL;
  if (include_optional) {
    service_status_request_body = service_status_request_body_create(
      1,
      "0",
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_sys_info_schema(0),
       // false, not to have infinite recursion
      instantiate_layout_schema(0),
      list_createList(),
       // false, not to have infinite recursion
      instantiate_pool_usage_schema(0),
      "0",
       // false, not to have infinite recursion
      instantiate_network_schema(0),
      "0",
      "0"
    );
  } else {
    service_status_request_body = service_status_request_body_create(
      1,
      "0",
      "0",
      "0",
      "0",
      NULL,
      NULL,
      list_createList(),
      NULL,
      "0",
      NULL,
      "0",
      "0"
    );
  }

  return service_status_request_body;
}


#ifdef service_status_request_body_MAIN

void test_service_status_request_body(int include_optional) {
    service_status_request_body_t* service_status_request_body_1 = instantiate_service_status_request_body(include_optional);

	cJSON* jsonservice_status_request_body_1 = service_status_request_body_convertToJSON(service_status_request_body_1);
	printf("service_status_request_body :\n%s\n", cJSON_Print(jsonservice_status_request_body_1));
	service_status_request_body_t* service_status_request_body_2 = service_status_request_body_parseFromJSON(jsonservice_status_request_body_1);
	cJSON* jsonservice_status_request_body_2 = service_status_request_body_convertToJSON(service_status_request_body_2);
	printf("repeating service_status_request_body:\n%s\n", cJSON_Print(jsonservice_status_request_body_2));
}

int main() {
  test_service_status_request_body(1);
  test_service_status_request_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // service_status_request_body_MAIN
#endif // service_status_request_body_TEST
