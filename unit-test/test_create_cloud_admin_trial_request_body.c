#ifndef create_cloud_admin_trial_request_body_TEST
#define create_cloud_admin_trial_request_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_cloud_admin_trial_request_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_cloud_admin_trial_request_body.h"
create_cloud_admin_trial_request_body_t* instantiate_create_cloud_admin_trial_request_body(int include_optional);



create_cloud_admin_trial_request_body_t* instantiate_create_cloud_admin_trial_request_body(int include_optional) {
  create_cloud_admin_trial_request_body_t* create_cloud_admin_trial_request_body = NULL;
  if (include_optional) {
    create_cloud_admin_trial_request_body = create_cloud_admin_trial_request_body_create(
      "jane.doe@example.com",
      "Jane Doe",
      "+1-555-123-4567",
      "US",
      "Acme Corp",
      "Software",
      "Security Engineer",
      "Mobile App Security Testing",
      "prod_ExampleProductId",
      true,
      12,
      25,
      true,
      14
    );
  } else {
    create_cloud_admin_trial_request_body = create_cloud_admin_trial_request_body_create(
      "jane.doe@example.com",
      "Jane Doe",
      "+1-555-123-4567",
      "US",
      "Acme Corp",
      "Software",
      "Security Engineer",
      "Mobile App Security Testing",
      "prod_ExampleProductId",
      true,
      12,
      25,
      true,
      14
    );
  }

  return create_cloud_admin_trial_request_body;
}


#ifdef create_cloud_admin_trial_request_body_MAIN

void test_create_cloud_admin_trial_request_body(int include_optional) {
    create_cloud_admin_trial_request_body_t* create_cloud_admin_trial_request_body_1 = instantiate_create_cloud_admin_trial_request_body(include_optional);

	cJSON* jsoncreate_cloud_admin_trial_request_body_1 = create_cloud_admin_trial_request_body_convertToJSON(create_cloud_admin_trial_request_body_1);
	printf("create_cloud_admin_trial_request_body :\n%s\n", cJSON_Print(jsoncreate_cloud_admin_trial_request_body_1));
	create_cloud_admin_trial_request_body_t* create_cloud_admin_trial_request_body_2 = create_cloud_admin_trial_request_body_parseFromJSON(jsoncreate_cloud_admin_trial_request_body_1);
	cJSON* jsoncreate_cloud_admin_trial_request_body_2 = create_cloud_admin_trial_request_body_convertToJSON(create_cloud_admin_trial_request_body_2);
	printf("repeating create_cloud_admin_trial_request_body:\n%s\n", cJSON_Print(jsoncreate_cloud_admin_trial_request_body_2));
}

int main() {
  test_create_cloud_admin_trial_request_body(1);
  test_create_cloud_admin_trial_request_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_cloud_admin_trial_request_body_MAIN
#endif // create_cloud_admin_trial_request_body_TEST
