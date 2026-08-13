#ifndef service_status_request_body_vms_inner_TEST
#define service_status_request_body_vms_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define service_status_request_body_vms_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/service_status_request_body_vms_inner.h"
service_status_request_body_vms_inner_t* instantiate_service_status_request_body_vms_inner(int include_optional);



service_status_request_body_vms_inner_t* instantiate_service_status_request_body_vms_inner(int include_optional) {
  service_status_request_body_vms_inner_t* service_status_request_body_vms_inner = NULL;
  if (include_optional) {
    service_status_request_body_vms_inner = service_status_request_body_vms_inner_create(
      "0"
    );
  } else {
    service_status_request_body_vms_inner = service_status_request_body_vms_inner_create(
      "0"
    );
  }

  return service_status_request_body_vms_inner;
}


#ifdef service_status_request_body_vms_inner_MAIN

void test_service_status_request_body_vms_inner(int include_optional) {
    service_status_request_body_vms_inner_t* service_status_request_body_vms_inner_1 = instantiate_service_status_request_body_vms_inner(include_optional);

	cJSON* jsonservice_status_request_body_vms_inner_1 = service_status_request_body_vms_inner_convertToJSON(service_status_request_body_vms_inner_1);
	printf("service_status_request_body_vms_inner :\n%s\n", cJSON_Print(jsonservice_status_request_body_vms_inner_1));
	service_status_request_body_vms_inner_t* service_status_request_body_vms_inner_2 = service_status_request_body_vms_inner_parseFromJSON(jsonservice_status_request_body_vms_inner_1);
	cJSON* jsonservice_status_request_body_vms_inner_2 = service_status_request_body_vms_inner_convertToJSON(service_status_request_body_vms_inner_2);
	printf("repeating service_status_request_body_vms_inner:\n%s\n", cJSON_Print(jsonservice_status_request_body_vms_inner_2));
}

int main() {
  test_service_status_request_body_vms_inner(1);
  test_service_status_request_body_vms_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // service_status_request_body_vms_inner_MAIN
#endif // service_status_request_body_vms_inner_TEST
