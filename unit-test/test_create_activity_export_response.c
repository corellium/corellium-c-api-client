#ifndef create_activity_export_response_TEST
#define create_activity_export_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_activity_export_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_activity_export_response.h"
create_activity_export_response_t* instantiate_create_activity_export_response(int include_optional);



create_activity_export_response_t* instantiate_create_activity_export_response(int include_optional) {
  create_activity_export_response_t* create_activity_export_response = NULL;
  if (include_optional) {
    create_activity_export_response = create_activity_export_response_create(
      "activity-export/722cdce5-6f71-4f4a-b2b6-c00f11c015f6"
    );
  } else {
    create_activity_export_response = create_activity_export_response_create(
      "activity-export/722cdce5-6f71-4f4a-b2b6-c00f11c015f6"
    );
  }

  return create_activity_export_response;
}


#ifdef create_activity_export_response_MAIN

void test_create_activity_export_response(int include_optional) {
    create_activity_export_response_t* create_activity_export_response_1 = instantiate_create_activity_export_response(include_optional);

	cJSON* jsoncreate_activity_export_response_1 = create_activity_export_response_convertToJSON(create_activity_export_response_1);
	printf("create_activity_export_response :\n%s\n", cJSON_Print(jsoncreate_activity_export_response_1));
	create_activity_export_response_t* create_activity_export_response_2 = create_activity_export_response_parseFromJSON(jsoncreate_activity_export_response_1);
	cJSON* jsoncreate_activity_export_response_2 = create_activity_export_response_convertToJSON(create_activity_export_response_2);
	printf("repeating create_activity_export_response:\n%s\n", cJSON_Print(jsoncreate_activity_export_response_2));
}

int main() {
  test_create_activity_export_response(1);
  test_create_activity_export_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_activity_export_response_MAIN
#endif // create_activity_export_response_TEST
