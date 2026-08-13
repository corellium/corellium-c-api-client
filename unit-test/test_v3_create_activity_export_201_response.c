#ifndef v3_create_activity_export_201_response_TEST
#define v3_create_activity_export_201_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v3_create_activity_export_201_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v3_create_activity_export_201_response.h"
v3_create_activity_export_201_response_t* instantiate_v3_create_activity_export_201_response(int include_optional);



v3_create_activity_export_201_response_t* instantiate_v3_create_activity_export_201_response(int include_optional) {
  v3_create_activity_export_201_response_t* v3_create_activity_export_201_response = NULL;
  if (include_optional) {
    v3_create_activity_export_201_response = v3_create_activity_export_201_response_create(
      "0"
    );
  } else {
    v3_create_activity_export_201_response = v3_create_activity_export_201_response_create(
      "0"
    );
  }

  return v3_create_activity_export_201_response;
}


#ifdef v3_create_activity_export_201_response_MAIN

void test_v3_create_activity_export_201_response(int include_optional) {
    v3_create_activity_export_201_response_t* v3_create_activity_export_201_response_1 = instantiate_v3_create_activity_export_201_response(include_optional);

	cJSON* jsonv3_create_activity_export_201_response_1 = v3_create_activity_export_201_response_convertToJSON(v3_create_activity_export_201_response_1);
	printf("v3_create_activity_export_201_response :\n%s\n", cJSON_Print(jsonv3_create_activity_export_201_response_1));
	v3_create_activity_export_201_response_t* v3_create_activity_export_201_response_2 = v3_create_activity_export_201_response_parseFromJSON(jsonv3_create_activity_export_201_response_1);
	cJSON* jsonv3_create_activity_export_201_response_2 = v3_create_activity_export_201_response_convertToJSON(v3_create_activity_export_201_response_2);
	printf("repeating v3_create_activity_export_201_response:\n%s\n", cJSON_Print(jsonv3_create_activity_export_201_response_2));
}

int main() {
  test_v3_create_activity_export_201_response(1);
  test_v3_create_activity_export_201_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // v3_create_activity_export_201_response_MAIN
#endif // v3_create_activity_export_201_response_TEST
