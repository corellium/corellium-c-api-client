#ifndef v3_get_activity_export_status_200_response_TEST
#define v3_get_activity_export_status_200_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v3_get_activity_export_status_200_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v3_get_activity_export_status_200_response.h"
v3_get_activity_export_status_200_response_t* instantiate_v3_get_activity_export_status_200_response(int include_optional);



v3_get_activity_export_status_200_response_t* instantiate_v3_get_activity_export_status_200_response(int include_optional) {
  v3_get_activity_export_status_200_response_t* v3_get_activity_export_status_200_response = NULL;
  if (include_optional) {
    v3_get_activity_export_status_200_response = v3_get_activity_export_status_200_response_create(
      corellium_api_v3_get_activity_export_status_200_response_STATUS_in-progress
    );
  } else {
    v3_get_activity_export_status_200_response = v3_get_activity_export_status_200_response_create(
      corellium_api_v3_get_activity_export_status_200_response_STATUS_in-progress
    );
  }

  return v3_get_activity_export_status_200_response;
}


#ifdef v3_get_activity_export_status_200_response_MAIN

void test_v3_get_activity_export_status_200_response(int include_optional) {
    v3_get_activity_export_status_200_response_t* v3_get_activity_export_status_200_response_1 = instantiate_v3_get_activity_export_status_200_response(include_optional);

	cJSON* jsonv3_get_activity_export_status_200_response_1 = v3_get_activity_export_status_200_response_convertToJSON(v3_get_activity_export_status_200_response_1);
	printf("v3_get_activity_export_status_200_response :\n%s\n", cJSON_Print(jsonv3_get_activity_export_status_200_response_1));
	v3_get_activity_export_status_200_response_t* v3_get_activity_export_status_200_response_2 = v3_get_activity_export_status_200_response_parseFromJSON(jsonv3_get_activity_export_status_200_response_1);
	cJSON* jsonv3_get_activity_export_status_200_response_2 = v3_get_activity_export_status_200_response_convertToJSON(v3_get_activity_export_status_200_response_2);
	printf("repeating v3_get_activity_export_status_200_response:\n%s\n", cJSON_Print(jsonv3_get_activity_export_status_200_response_2));
}

int main() {
  test_v3_get_activity_export_status_200_response(1);
  test_v3_get_activity_export_status_200_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // v3_get_activity_export_status_200_response_MAIN
#endif // v3_get_activity_export_status_200_response_TEST
